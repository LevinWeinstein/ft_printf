/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_specifier_substring.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:45:47 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/15 05:20:15 by lweinste         ###   ########.fr       */
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

char    *next_flag(void *next, char *(*handler[13])(void *), int format)
{
    char    *output;
    
    output = (*handler[format])(next);
    return (output);
    
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
        return e_unsigned;
    if (unread.conversion == 'X' || unread.conversion == 'x')
        return (unread.conversion == 'X' ? e_hex_upper : e_hex_lower);
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
    return (0);
}

int		pign(char c)
{
	return (c == '%' || c == 'X' || c == 'x');
}

char *handle_flags(t_format *saved, char *str)
{
    t_flag *flagset;

    flagset = (t_flag *)malloc(sizeof(t_flag));
    store_flag(flagset, saved->flags);
   
	if(saved->precision > (int)ft_strlen(str) && is_number(saved))
        str = zero_width(str, saved->precision);
	else if (saved->precision != -1 && !pign(saved->conversion) &&!isnumber(saved->precision))
		str = ft_strndup(str, saved->precision); 
    if (flagset->plus && (saved->conversion == 'i' || saved->conversion == 'd' || saved->conversion == 'D'))
        str = add_plus(str);
    else if (flagset->space && (saved->conversion == 'i' || saved->conversion == 'd' || saved->conversion == 'D'))
        str = add_space(str);
    if (saved->field != 0 && flagset->minus)
        str = left_width(str, saved->field);
    else if (flagset->zero)
        str = zero_width(str, saved->field);
    if(flagset->hash && (saved->conversion == 'x' || saved->conversion == 'X'|| saved->conversion == 'p'))
        str = (ft_atoi(str) == 0) ? str : add_0x(str, saved->conversion);
    if(flagset->hash && (saved->conversion == 'o' || saved->conversion == 'O'))
        str = add_0(str);
	if (!flagset->zero && !flagset->minus)
		str = field_width(str, saved->field);
    return (str);
}
