/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_upper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 05:11:05 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/19 05:39:48 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fp_cx_upper(va_list *val)
{
	char				*output;
	unsigned char		t;
	int					n;

	n = va_arg(*val, int);
	t = (unsigned char)n;
	output = ft_utoa_base_upper(t, 16);
	return (output);
}

char	*fp_sx_upper(va_list *val)
{
	char				*output;
	unsigned short		t;
	int					n;

	n = va_arg(*val, int);
	t = (unsigned short)n;
	output = ft_utoa_base_upper(t, 16);
	return (output);
}

char	*fp_x_upper(va_list *val)
{
	char				*output;
	int					t;

	t = 0;
	t = va_arg(*val, int);
	output = ft_utoa_base_upper(t, 16);
	if (t < 0)
		return (output + 8);
	return (output);
}

char	*fp_lx_upper(va_list *val)
{
	char			*output;
	unsigned long	t;

	t = 0;
	t = va_arg(*val, unsigned long);
	output = ft_utoa_base_upper(t, 16);
	return (output);
}

char	*fp_llx_upper(va_list *val)
{
	char				*output;
	unsigned long long	t;

	t = 0;
	t = va_arg(*val, unsigned long long);
	output = ft_utoa_base_upper(t, 16);
	return (output);
}
