/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_fp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 05:12:41 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/19 05:12:43 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fp_ptr(va_list *val)
{
	char				*output;
	unsigned long long	t;

	t = va_arg(*val, unsigned long long);
	output = ft_utoa_ptr(t, 16);
	return (output);
}
