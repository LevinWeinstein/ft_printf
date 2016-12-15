/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:30:48 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/13 12:30:49 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char    *str_zero(void)
{
    char *output;
    
    output = (char *)malloc(2 * sizeof(char));
    output[0] = '0';
    output[1] = '\0';
    return (output);
}

static int     get_digits(unsigned long long value, int base)
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

char    *ft_utoa_ptr(unsigned long long value, int base)
{
    int     digits;
    char    *output;
    
    if (base < 2 || base > 16)
        return ((char *) 0);
    if (value == 0)
        return ((output = str_zero()));
    digits = (2 + get_digits(value, base));
    output = (char *)malloc((digits + 1) * sizeof(char));
    output[digits] = '\0';
    output[0] = '0';
    output[1] = 'x';
    while (value != 0)
    {
        output[--digits] = g_values[value % base];
        value /= base;
    }
    return (output);
}
