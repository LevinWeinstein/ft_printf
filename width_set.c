/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:42:34 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/19 04:20:47 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*field_width(char *str, int n)
{
	int		m;
	int		diff;
	char	*output;
	int		i;
	int		j;

	i = 0;
	j = -1;
	m = ft_strlen(str);
	if (m >= n)
		return (str);
	else
	{
		diff = n - m;
		output = (char *)malloc((n + 1) * sizeof(char));
		output[n] = '\0';
		while (++j < diff)
			output[j] = ' ';
		j--;
		while (j++ < (m + diff))
			output[j] = str[i++];
		output[j] = '\0';
	}
	return (output);
}

char	*left_width(char *str, int n)
{
	int		m;
	int		used;
	char	*output;
	int		i;
	int		j;

	i = 0;
	j = -1;
	m = ft_strlen(str);
	used = 0;
	if (m >= n)
		return (str);
	else
	{
		output = (char *)malloc((n + 1) * sizeof(char));
		output[n] = '\0';
		while (str[++j])
			output[j] = str[j];
		j--;
		while (j++ < n && (used = 1) != 0)
			output[j] = ' ';
		output[j - used] = '\0';
	}
	return (output);
}

char	negcheck(char *str)
{
	if (*str == '-')
		return ('-');
	if (*str == '+')
		return ('+');
	if (*str == ' ')
		return (' ');
	return (0);
}

char	*zero_width(char *str, int n)
{
	int		m[3];
	int		diff;
	char	*output;

	m[1] = (int)(negcheck(str) != 0);
	m[2] = -1 + (int)(negcheck(str) != 0);
	m[0] = ft_strlen(str);
	if (m[0] >= n)
		return (str);
	else
	{
		diff = n - m[0];
		output = (char *)malloc((n + 1) * sizeof(char));
		output[n] = '\0';
		while (++m[2] < diff + (int)(negcheck(str) != 0))
			output[m[2]] = '0';
		m[2]--;
		while (m[2]++ < (m[0] + diff))
			output[m[2]] = str[m[1]++];
		output[m[2]] = '\0';
		if (negcheck(str))
			output[0] = (char)negcheck(str);
	}
	return (output);
}
