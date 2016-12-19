/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 07:42:49 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/19 07:50:04 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fp_mod(void)
{
	char *output;

	output = (char *)malloc(2 * sizeof(char));
	output[0] = '%';
	output[1] = '\0';
	return (output);
}

char	*fp_z(void)
{
	char *output;

	output = (char *)malloc(2 * sizeof(char));
	output[0] = 'Z';
	output[1] = '\0';
	return (output);
}

char	*fp_r(void)
{
	char *output;

	output = (char *)malloc(2 * sizeof(char));
	output[0] = 'R';
	output[1] = '\0';
	return (output);
}
