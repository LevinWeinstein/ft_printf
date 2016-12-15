/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters_etc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:36:49 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/15 03:48:06 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char   *fp_char(va_list *val)
{
    char *output;
    char c;

    output = (char *)malloc(2 * sizeof(char));
    c = va_arg(*val, int);
    output[0] = c;
    output[1] = '\0';
    return (output);
}

char   *fp_str(va_list *val)
{
    char *output;

    output = va_arg(*val, char *);
	if (output == NULL)
		return ft_strdup("(null)");
    return (output);
}

char   *fp_wchar(va_list *val) //ft_wchar must be added to set still, (it's located in the wideset folder now)
{
    char *output;
    wchar_t wc;

    wc = va_arg(*val, wchar_t);  //CHANGING FROM FT_U2PTR, FT_WCHAR AND FT_WSTR TO PUTCHAR AND PUTSTR TO COMPILE BEFORE ADDING WSET. **CHANGE BACK**
    output = ft_wchar(wc);
    return (output);
}

char   *fp_wstr(va_list *val) //Import ft_wstr.c and ft_wchar.c. Declarations currently in should_be_ft_printf.h. Simply declare in ft_printf.h.
                              //Make sure to copy the whole files to include the static helper function in ft_wchar.c
{
    char *output;
    wchar_t *wstr;

    wstr = va_arg(*val, wchar_t*);
    output = ft_wstr(wstr);
    return (output);
}

char   *fp_mod(void)
{
    char *output;

    output = (char *)malloc(2 * sizeof(char));
    output[0] = '%';
    output[1] = '\0';
    return (output);
}
