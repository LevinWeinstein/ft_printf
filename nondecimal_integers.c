/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nondecimal_integers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:35:37 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/15 10:52:21 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fp_x_lower(va_list *val)
{
	char				*output;
	unsigned long long	t;

	t = 0;
	t = va_arg(*val, unsigned long long);
	output = ft_utoa_base_lower(t, 16);
	return (output);
}

char	*fp_x_upper(va_list *val)
{
	char				*output;
	unsigned long long	t;

	t = 0;
	t = va_arg(*val, unsigned long long);
	output = ft_utoa_base_upper(t, 16);
	return (output);
}

char	*fp_ix_lower(va_list *val)
{
	char				*output;
	int					t;

	t = 0;
	t = va_arg(*val, int);
	output = ft_utoa_base_lower(t, 16);
	if (t < 0)
		return (output + 8);
	return (output);
}

char	*fp_ix_upper(va_list *val)
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
char	*fp_ptr(va_list *val)
{
	char				*output;
	unsigned long long	t;

	t = va_arg(*val, unsigned long long);
	output = ft_utoa_ptr(t, 16);
	return (output);
}

char	*fp_o(va_list *val)
{
	char	*output;
	int		t;

	t = va_arg(*val, unsigned long long);
	output = ft_utoa_base_lower(t, 8);
	return (output);
}
