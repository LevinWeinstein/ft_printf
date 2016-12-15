/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_specifier_substring.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:45:47 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/15 12:33:40 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*to_next(char *output, char *str, int *another) //starts at start of first char after last formspec
{
	int i;			//index
	int	found;		//found fspec?

	i = -1;
	found = 0;
	while(found == 0 && str[++i])
		if (str[i] == '%' && format_len(&str[i]))
			found = 1;
	output = ft_strjoin(output, ft_strndup(str, i));
	if (str[i])
        *another = i;
    else
        *another = -1;
    return (output);
}

char    *next_flag(void *next, char *(*handler[17])(void *), int format)
{
    char    *output;
    
    output = (*handler[format])(next);
    return (output);
    
}

int		handle_u(char *str, char c)//add
{
	if (c == 'U' && str == NULL)
		return (e_ulong);
	if (c == 'u' && str == NULL)
		return (e_unsigned);
	if ((c == 'U' || c == 'u') && ft_strlen(str) == 2)
		return (*str == 'h' ? e_uchar : e_ulonglong);
	if ((c == 'U' && *str != 'h'))
		return (e_ulonglong);
	if (c == 'u' && *str == 'l')
		return (e_ulong);
	if (c == 'u' && *str != 'h')
		return (e_ulonglong);
	if (c == 'u' && *str == 'h')
		return (e_char);
	return (e_longlong);
}
int		handle_x(t_format saved) //add
{
	int n;

	n = 0;
	if (saved.modifier == NULL || saved.modifier[0] == 'h')
		n = e_ix_lower;
	else
		n = e_hex_lower;
	if (saved.conversion == 'X')
		n += 1;
	return (n);
}

int     get_type(t_format unread)
{
    if((unread.conversion == 'd' || unread.conversion == 'i') && 
        (unread.modifier == NULL || unread.modifier[0] == 'h'))
        return e_int;
    else if (unread.conversion == 'd' || unread.conversion == 'i')
        return (ft_strlen(unread.modifier) == 1 ? e_long : e_longlong);
    if(unread.conversion == 'D' && unread.modifier == NULL)
        return e_long;
    else if(unread.conversion == 'D')
        return (unread.modifier[0] == 'l' ? e_longlong : e_int);
    if (unread.conversion == 'U' || unread.conversion == 'u')
        return (handle_u(unread.modifier, unread.conversion));
    if (unread.conversion == 'X' || unread.conversion == 'x')
        return (handle_x(unread));
    if (unread.conversion == 'p')
        return (e_pointer);
    if (unread.conversion == 'o' || unread.conversion == 'O')
        return (e_octal);
    if (unread.conversion == 'c')
        return (unread.modifier == NULL ? e_char : e_wchar);
    if (unread.conversion == 's')
        return (unread.modifier == NULL ? e_str : e_wstr);
    if (unread.conversion == 'S' || unread.conversion == 'C')
        return (unread.conversion == 'S' ? e_wstr : e_wchar);
    return (e_modulus);
}
//add these three to header
int    is_number(t_format *saved)
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
	if (is_number(format))
		return (ft_atoi(str) == 0 ? 1 : 0);
	return (1);
}


//end
char *handle_flags(t_format *s, char *str)
{
    t_flag *flagset;

    flagset = (t_flag *)malloc(sizeof(t_flag));
    store_flag(flagset, s->flags);
   
	if(s->precision > (int)ft_strlen(str) && is_number(s))
        str = zero_width(str, s->precision);
	else if (s->precision != -1 && iszero(s, str))
		str = ft_strndup(str, s->precision);
	if (flagset->plus && (s->conversion == 'i' || s->conversion == 'd' || s->conversion == 'D'))
        str = add_plus(str);
    else if (flagset->space && (s->conversion == 'i' || s->conversion == 'd' || s->conversion == 'D'))
        str = add_space(str);
    if (s->field != 0 && flagset->minus)
        str = left_width(str, s->field);
    else if (flagset->zero)
        str = zero_width(str, s->field);
    if(flagset->hash && (s->conversion == 'x' || s->conversion == 'X'|| s->conversion == 'p'))
        str = (ft_atoi(str) == 0) ? str : add_0x(str, s->conversion);
    if(flagset->hash && (s->conversion == 'o' || s->conversion == 'O'))
        str = add_0(str);
	if ((!flagset->zero && !flagset->minus))
		str = field_width(str, s->field);
    return (str);
}
