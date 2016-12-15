/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:42:34 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/15 04:31:56 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *field_width(char *str, int n)
{
    int m;
    int diff;
    char *output;
    int i;
    int j;

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
        while(++j < diff)
            output[j] = ' ';
		j--;
        while(j++ < (m + diff))
            output[j] = str[i++];
        output[j] = '\0';
    }
    return (output);
}

char *left_width(char *str, int n) //takes priority over zero padding on the right cuz if it's pushed all the way to the left then like, there's no with which to pad.
{
    int m;
    int used;
    char *output;
    int i;
    int j;

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
        while(str[++j])
            output[j] = str[j];
		j--;
        while(j++ < n && (used = 1) != 0)
            output[j] = ' ';
        output[j - used] = '\0';
    }
    return (output);
}

int negcheck(char *str)
{
	return (*str == '-' ? 1 : 0);
}

char *zero_width(char *str, int n) //works for 0 flag field width, and also for precision for integer numbers
{
    int m[3];
    int diff;
    char *output;

    m[1] = negcheck(str);
    m[2] = -1 + negcheck(str);
    m[0] = ft_strlen(str);
    if (m[0] >= n)
        return (str);
    else
    {
        diff = n - m[0];
        output = (char *)malloc((n + 1) * sizeof(char));
        output[n] = '\0';
        while(++m[2] < diff + negcheck(str))
            output[m[2]] = '0';
        m[2]--;
        while(m[2]++ < (m[0] + diff))
            output[m[2]] = str[m[1]++];
        output[m[2]] = '\0';
		if (negcheck(str))
			output[0] = '-';
    }
    return (output);
}
