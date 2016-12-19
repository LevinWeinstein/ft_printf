/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 05:10:42 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/19 05:33:57 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fp_uc(va_list *val)
{
	char			*output;
	int				n;
	unsigned char	t;

	n = va_arg(*val, int);
	t = (unsigned char)n;
	output = ft_utoa_base_lower(t, 10);
	return (output);
}

char	*fp_us(va_list *val)
{
	char			*output;
	int				t;
	unsigned short	s;

	t = va_arg(*val, int);
	s = (unsigned short)t;
	output = ft_utoa_base_lower(s, 10);
	return (output);
}

char	*fp_u(va_list *val)
{
	char			*output;
	unsigned int	t;

	t = va_arg(*val, unsigned int);
	output = ft_utoa_base_lower(t, 10);
	return (output);
}

char	*fp_ul(va_list *val)
{
	char			*output;
	unsigned long	t;

	t = va_arg(*val, unsigned long);
	output = ft_utoa_base_lower(t, 10);
	return (output);
}

char	*fp_ull(va_list *val)
{
	char				*output;
	unsigned long long	t;

	t = va_arg(*val, unsigned long);
	output = ft_utoa_base_lower(t, 10);
	return (output);
}
