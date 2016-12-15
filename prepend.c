/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:44:17 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/15 11:56:58 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *add_0x(char *str, char c)
{
	int n;

	n = 0;
	if (str != NULL && str[0] == '0')
	{
		if (ft_strlen(str) > 1 && str[1] == '0')
			n = 2;
		else
			n = 1;
	}
	if (str != NULL && str[ft_strlen(str) - 1] == ' ')
	{
		if (ft_strlen(str) > 1 && str[ft_strlen(str) - 2] == ' ')
			str[ft_strlen(str) - 2] = '\0';
		else
			str[ft_strlen(str) - 1] = '\0';
	}
	if(c == 'X')
		return (ft_strjoin(ft_strdup("0X"), str + n));
    return (ft_strjoin(ft_strdup("0x"), str + n));
}

char *add_0(char *str)
{
	int n;

	n = 0;
	if (str != NULL && str[0] == '0')
		n = 1;
	if (str != NULL && str[ft_strlen(str) - 1] == ' ')
		str[ft_strlen(str) - 1] = '\0';
    return (ft_strjoin(ft_strdup("0"), str + n));
}

char *add_plus(char *str)
{
    return ((*str == '-') ? str : ft_strjoin(ft_strdup("+"), str)); //takes priority over space
}

char *add_space(char *str)
{
	if (str != NULL && str[0] == '-')
		return (str);
    return (ft_strjoin(ft_strdup(" "), str));
}
