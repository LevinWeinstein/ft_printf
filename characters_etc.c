/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters_etc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:36:49 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/19 04:57:54 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fp_char(va_list *val)
{
	char *output;
	char c;

	output = (char *)malloc(2 * sizeof(char));
	c = va_arg(*val, int);
	if (c == '\0')
		output[0] = -1;
	else
		output[0] = c;
	output[1] = '\0';
	return (output);
}

char	*fp_str(va_list *val)
{
	char *output;

	output = va_arg(*val, char *);
	if (output == NULL)
		return (ft_strdup("(null)"));
	return (output);
}

char	*fp_wchar(va_list *val)
{
	char	*output;
	wchar_t	wc;

	wc = va_arg(*val, wchar_t);
	if (wc == L'\0')
	{
		output = (char *)malloc(2 * sizeof(char));
		output[0] = -1;
		output[1] = '\0';
	}
	else
		output = ft_wchar(wc);
	return (output);
}

char	*fp_wstr(va_list *val)
{
	char	*output;
	wchar_t	*wstr;

	wstr = va_arg(*val, wchar_t*);
	output = ft_wstr(wstr);
	return (output);
}

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
