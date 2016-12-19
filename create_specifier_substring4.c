/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_specifier_substring3.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 07:42:37 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/19 07:42:38 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
