/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:44:17 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/15 00:50:36 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *add_0x(char *str, char c)
{
	if(c == 'X')
		return (ft_strjoin(ft_strdup("0X"), str));
    return (ft_strjoin(ft_strdup("0x"), str));
}

char *add_0(char *str)
{
    return (ft_strjoin(ft_strdup("0"), str));
}

char *add_plus(char *str)
{
    return (*str == '-' ? str : ft_strjoin(ft_strdup("+"), str)); //takes priority over space
}

char *add_space(char *str)
{
    return (ft_strjoin(ft_strdup(" "), str)); //takes priority over space
}
