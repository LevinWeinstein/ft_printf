/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 05:11:18 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/19 05:11:19 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fp_oc(va_list *val)
{
	char				*output;
	unsigned int		t;
	unsigned char		c;

	t = va_arg(*val, unsigned int);
	c = (unsigned char)t;
	output = ft_utoa_base_lower(c, 8);
	return (output);
}

char	*fp_os(va_list *val)
{
	char				*output;
	unsigned int		t;
	unsigned short		s;

	t = va_arg(*val, unsigned int);
	s = (unsigned short)t;
	output = ft_utoa_base_lower(s, 8);
	return (output);
}

char	*fp_o(va_list *val)
{
	char			*output;
	unsigned int	t;

	t = va_arg(*val, int);
	output = ft_utoa_base_lower(t, 8);
	return (output);
}

char	*fp_ol(va_list *val)
{
	char				*output;
	unsigned long		t;

	t = va_arg(*val, unsigned long);
	output = ft_utoa_base_lower(t, 8);
	return (output);
}

char	*fp_oll(va_list *val)
{
	char				*output;
	unsigned long long	t;

	t = va_arg(*val, unsigned long long);
	output = ft_utoa_base_lower(t, 8);
	return (output);
}
