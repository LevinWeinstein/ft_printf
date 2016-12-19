/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_component.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 23:21:36 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/19 04:41:42 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

int			is_flag(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '#' || str[i] == '-' || str[i] == '+'
			|| str[i] == '0' || str[i] == ' ')
		i++;
	return (i);
}

int			is_field(const char *str)
{
	int i;

	i = -1;
	while (str[++i] >= '0' && str[i] <= '9')
		;
	return (i);
}

int			is_precision(const char *str)
{
	int	i;

	i = 0;
	if (str[i] != '.')
		return (0);
	while (str[++i] >= '0' && str[i] <= '9')
		;
	return (i);
}

int			is_modifier(const char *str)
{
	if (str[0] == 'l')
		return ((str[1] == 'l' ? 2 : 1));
	if (str[0] == 'h')
		return ((str[1] == 'h' ? 2 : 1));
	if (str[0] == 'j' || str[0] == 'z')
		return (1);
	return (0);
}

int			is_conversion(const char c)
{
	int i;

	i = 0;
	while (g_conversions[i])
		if (g_conversions[i++] == c)
			return (1);
	return (0);
}
