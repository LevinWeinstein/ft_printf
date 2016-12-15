/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:32:31 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/13 13:04:51 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int      ft_wchar_len(wchar_t wc)
{
    if (wc < 0x80)
        return (1);
    else if (wc < 0x800)
        return (2);
    else if (wc < 0x10000)
        return (3);
    else if (wc < 0x110000)
        return (4);
    return (0);
}

char            *ft_wchar(wchar_t wc)
{
    char *output;

    output = (char *)malloc((1 + ft_wchar_len(wc)) * sizeof(char));
    output[ft_wchar_len(wc)] = '\0';
    if (wc < 0x80)
        output[0] = wc;
    else if (wc < 0x800)
    {
        output[0] = (wc >> 6) + 0xC0;
        output[1] = (wc & 0x3F) + 0x80;
    }
    else if (wc < 0x10000)
    {
        output[0] = ((wc >> 12) + 0xE0);
        output[1] = ((wc >> 6) & 0x3F) + 0x80;
        output[2] = (wc & 0x3F) + 0x80;
    }
    else if (wc < 0x110000)
    {
        output[0] = ((wc >> 18) + 0xF0);
        output[1] = ((wc >> 12) & 0x3F) + 0x80;
        output[2] = ((wc >> 6) & 0x3F) + 0x80;
        output[3] = (wc & 0x3F) + 0x80;
    }
    return (output);
}

char    *ft_wstr(wchar_t *wstr)
{
    int     i;
    char    *output;

	i = 0;
    output = "";
    while (wstr[i])
        output = ft_strjoin(output, ft_wchar(wstr[i++]));
    return (output);
}
