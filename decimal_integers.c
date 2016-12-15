/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_integers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:34:24 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/15 01:08:20 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *fp_d(va_list *val)
{
    char *output;
    int  t;
    
    t = va_arg(*val, int);
    output = ft_itoa_base(t, 10);
    return (output);
}

char    *fp_l(va_list *val)
{
    char *output;
    long  t;
    
    t = va_arg(*val, long);
    output = ft_itoa_base(t, 10);
    return (output);
}

char    *fp_ll(va_list *val)
{
    char *output;
    long long  t;
    
    t = va_arg(*val, long long);
    output = ft_itoa_base(t, 10);
    return (output);
}

char    *fp_u(va_list *val)
{
    char *output;
    int  t;
    
    t = va_arg(*val, unsigned long long);
    output = ft_utoa_base_lower(t, 10);
    return (output);
}
