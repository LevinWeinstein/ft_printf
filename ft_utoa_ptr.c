/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 05:59:20 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/15 11:50:39 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ssize_t long long
#include <stdlib.h>

static char	g_values[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

static char	*str_zero(void)
{
	char *output;

	output = (char *)malloc(4 * sizeof(char));
	output[0] = '0';
	output[1] = 'x';
	output[2] = '0';
	output[3] = '\0';
	return (output);
}


static int		get_digits(ssize_t value, int base)
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

char	*ft_utoa_ptr(ssize_t value, int base)
{
	int		negative;
	int		digits;
	char	*output;

	if (base < 2 || base > 16)
		return ((char *) 0);
	if (value == 0)
		return ((output = str_zero()));
	negative = ((value < 0 && base == 10)? 1 : 0);
	digits = get_digits(value, base);
	digits += negative + 2;
	output = (char *)malloc((digits + 1) * sizeof(char));
	output[digits] = '\0';
	output[0] = '0';
	output[1] = 'x';
	if (negative)
		output[0] = '-';
	while (value != 0)
	{
		output[--digits] = g_values[value % base];
		value /= base;
	}
	return (output);
}
