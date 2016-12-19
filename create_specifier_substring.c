/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_specifier_substring.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:45:47 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/19 07:50:18 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*to_next(char *output, char *str, int *another)
{
	int i;
	int	found;

	i = -1;
	found = 0;
	while (found == 0 && str[++i])
		if (str[i] == '%' && format_len(&str[i]))
			found = 1;
	output = ft_strjoin(output, ft_strndup(str, i));
	if (str[i])
		*another = i;
	else
		*another = -1;
	return (output);
}

int		is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

char	*next_flag(void *next, char *(*handler[17])(void *), int format)
{
	char	*output;

	output = (*handler[format])(next);
	return (output);
}

int		cs(int c, int s, char spec, char *len)
{
	if (spec == 'U' && len[0] == 'h')
		return (e_ulong);
	if (ft_strlen(len) == 2 && is_lower(spec))
		return (c);
	return (s);
}
