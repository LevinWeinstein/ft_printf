/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 05:10:13 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/19 05:34:21 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fp_ic(va_list *val)
{
	char	*output;
	int		t;
	char	c;

	t = va_arg(*val, int);
	c = (char)t;
	output = ft_itoa_base(c, 10);
	return (output);
}

char	*fp_sd(va_list *val)
{
	char	*output;
	int		n;
	short	t;

	n = va_arg(*val, int);
	t = (short)n;
	output = ft_itoa_base(t, 10);
	return (output);
}

char	*fp_d(va_list *val)
{
	char	*output;
	int		t;

	t = va_arg(*val, int);
	output = ft_itoa_base(t, 10);
	return (output);
}

char	*fp_l(va_list *val)
{
	char	*output;
	long	t;

	t = va_arg(*val, long);
	output = ft_itoa_base(t, 10);
	return (output);
}

char	*fp_ll(va_list *val)
{
	char		*output;
	long long	t;

	t = va_arg(*val, long long);
	output = ft_itoa_base(t, 10);
	return (output);
}
