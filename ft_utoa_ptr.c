/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 05:59:20 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/19 05:56:23 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		g_vals[] = "0123456789abcdef";

static char		*str_zero(void)
{
	char *output;

	output = (char *)malloc(4 * sizeof(char));
	output[0] = '0';
	output[1] = 'x';
	output[2] = '0';
	output[3] = '\0';
	return (output);
}

static int		get_digits(uintmax_t value, int base)
{
	int i;

	i = 0;
	while (value != 0)
	{
		value /= base;
		i++;
	}
	return (i);
}

char			*ft_utoa_ptr(uintmax_t value, int base)
{
	int		digits;
	char	*output;

	if (base < 2 || base > 16)
		return ((char *)0);
	if (value == 0)
		return ((output = str_zero()));
	digits = get_digits(value, base);
	digits += 2;
	output = (char *)malloc((digits + 1) * sizeof(char));
	output[digits] = '\0';
	output[0] = '0';
	output[1] = 'x';
	while (value != 0)
	{
		output[--digits] = g_vals[value % base];
		value /= base;
	}
	return (output);
}
