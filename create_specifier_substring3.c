/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_specifier_substring4.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 07:46:17 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/19 07:51:13 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
