/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_specifier_substring2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 07:42:28 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/19 07:42:29 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
