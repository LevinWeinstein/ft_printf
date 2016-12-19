/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_integers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:34:24 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/15 09:23:49 by lweinste         ###   ########.fr       */
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
	short			s;
	
	t = va_arg(*val, int);
	s = (short)t;
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
