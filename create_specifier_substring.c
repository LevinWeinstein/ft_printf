/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_specifier_substring.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:45:47 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/19 04:19:21 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*to_next(char *output, char *str, int *another)
{
	int i;
	int	found;

	i = -1;
	found = 0;
	while (found == 0 && str[++i])
		if (str[i] == '%' && format_len(&str[i]))
			found = 1;
	output = ft_strjoin(output, ft_strndup(str, i));
	if (str[i])
		*another = i;
	else
		*another = -1;
	return (output);
}

int		is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

char	*next_flag(void *next, char *(*handler[17])(void *), int format)
{
	char	*output;

	output = (*handler[format])(next);
	return (output);
}

int		cs(int c, int s, char spec, char *len)
{
	if (spec == 'U' && len[0] == 'h')
		return (e_ulong);
	if (ft_strlen(len) == 2 && is_lower(spec))
		return (c);
	return (s);
}

int		handle_u(char *str, char c)
{
	if (c == 'U' && str == NULL)
		return (e_ulong);
	if (c == 'u' && str == NULL)
		return (e_unsigned);
	if ((c == 'U' || c == 'u'))
		return (*str == 'h' ? cs(e_uc, e_us, c, str) : e_ulonglong);
	if ((c == 'U' && *str != 'h'))
		return (e_ulonglong);
	if (c == 'u' && *str == 'l')
		return (e_ulong);
	if (c == 'u' && *str != 'h')
		return (e_ulonglong);
	if (c == 'u' && *str == 'h')
		return (e_uc);
	return (e_longlong);
}

int		handle_low_x(char *str)
{
	if (str == NULL)
		return (e_hex_lower);
	if (str[0] == 'h' && ft_strlen(str) == 2)
		return (e_cx_lower);
	if (str[0] == 'h')
		return (e_sx_lower);
	if (str[0] == 'l' && ft_strlen(str) == 1)
		return (e_lx_lower);
	return (e_llx_lower);
}

int		handle_up_x(char *str)
{
	if (str == NULL)
		return (e_hex_upper);
	if (str[0] == 'h' && ft_strlen(str) == 2)
		return (e_cx_upper);
	if (str[0] == 'h')
		return (e_sx_upper);
	if (str[0] == 'l' && ft_strlen(str) == 1)
		return (e_lx_upper);
	return (e_llx_upper);
}

int		handle_x(t_format saved)
{
	if (is_lower(saved.conversion))
		return (handle_low_x(saved.modifier));
	return (handle_up_x(saved.modifier));
}

int		handle_o(char *str, char c)
{
	if (c == 'O' && str == NULL)
		return (e_olong);
	if (c == 'o' && str == NULL)
		return (e_octal);
	if ((c == 'o' || c == 'O'))
		return (*str == 'h' ? cs(e_oc, e_os, c, str) : e_olonglong);
	if ((c == 'O' && *str != 'h'))
		return (e_olonglong);
	if (c == 'o' && *str == 'l')
		return (e_olong);
	if (c == 'o' && *str != 'h')
		return (e_olonglong);
	if (c == 'o' && *str == 'h')
		return (e_oc);
	return (e_olonglong);
}

int		small_d(t_format unread)
{
	if (unread.modifier == NULL)
		return (e_int);
	else if (ft_strlen(unread.modifier) == 2)
		return (e_ichar);
	return (e_short);
}

int		parse_singles(char c)
{
	if (c == 'Z' || c == 'R')
		return (c == 'Z' ? e_z : e_r);
	return (e_modulus);
}

int		get_type(t_format unread)
{
	if ((unread.conversion == 'd' || unread.conversion == 'i') &&
			(unread.modifier == NULL || unread.modifier[0] == 'h'))
		return (small_d(unread));
	else if (unread.conversion == 'd' || unread.conversion == 'i')
		return (ft_strlen(unread.modifier) == 1 ? e_long : e_longlong);
	if (unread.conversion == 'D' && unread.modifier == NULL)
		return (e_long);
	else if (unread.conversion == 'D')
		return (unread.modifier[0] == 'l' ? e_longlong : e_int);
	if (unread.conversion == 'U' || unread.conversion == 'u')
		return (handle_u(unread.modifier, unread.conversion));
	if (unread.conversion == 'X' || unread.conversion == 'x')
		return (handle_x(unread));
	if (unread.conversion == 'p')
		return (e_pointer);
	if (unread.conversion == 'o' || unread.conversion == 'O')
		return (handle_o(unread.modifier, unread.conversion));
	if (unread.conversion == 'c')
		return (unread.modifier == NULL ? e_char : e_wchar);
	if (unread.conversion == 's')
		return (unread.modifier == NULL ? e_str : e_wstr);
	if (unread.conversion == 'S' || unread.conversion == 'C')
		return (unread.conversion == 'S' ? e_wstr : e_wchar);
	return (parse_singles(unread.conversion));
}

int		is_number(t_format *saved)
{
	if (saved->conversion == 'o' || saved->conversion == 'O')
		return (1);
	if (saved->conversion == 'd' || saved->conversion == 'D')
		return (1);
	if (saved->conversion == 'i' || saved->conversion == 'p')
		return (1);
	if (saved->conversion == 'u' || saved->conversion == 'U')
		return (1);
	if (saved->conversion == 'x' || saved->conversion == 'X')
		return (1);
	if (saved->conversion == 'p')
		return (1);
	return (0);
}

int		pign(char c)
{
	return (c == '%' || c == 'X' || c == 'x');
}

int		iszero(t_format *format, char *str)
{
	if (format->conversion == '%')
		return (0);
	if (format->conversion == 'c' || format->conversion == 'C')
		return (0);
	if (is_number(format))
		return (ft_atoi(str) == 0 ? 1 : 0);
	return (1);
}

char	*check_err(char *str)
{
	if (*str == ' ' && str[1] == '-')
	{
		str[0] = '-';
		str[1] = '0';
		return (str);
	}
	return (str);
}

int		is_did(char c)
{
	if (c == 'd' || c == 'i' || c == 'D')
		return (1);
	return (0);
}

char	*handle_flags(t_format *s, char *str)
{
	t_flag *flagset;

	flagset = (t_flag *)malloc(sizeof(t_flag));
	store_flag(flagset, s->flags, s);
	if (s->precision > (int)ft_strlen(str) && is_number(s))
		str = zero_width(str, s->precision + (negcheck(str) != 0));
	else if (s->precision != -1 && iszero(s, str))
		str = ft_strndup(str, s->precision);
	if (flagset->plus && is_did(s->conversion))
		str = add_plus(str);
	else if (flagset->space && is_did(s->conversion))
		str = add_space(str);
	if (s->field != 0 && flagset->minus)
		str = left_width(str, s->field);
	else if (flagset->zero)
		str = zero_width(str, s->field);
	if (flagset->hash && (s->conversion == 'x' || s->conversion == 'X'))
		str = (ft_atoi(str) == 0) ? str : add_0x(str, s->conversion);
	if (flagset->hash && (s->conversion == 'o' || s->conversion == 'O'))
		str = add_0(str);
	if ((!flagset->zero && !flagset->minus))
		str = field_width(str, s->field);
	return (check_err(str));
}
