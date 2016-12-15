/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:38:42 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/15 08:57:52 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putfull(char *str)
{
	int i;
	char c;

	i = 0;
	c = '\0';
	while(str[i] != '\0')
	{
		if(str[i] == 7)
			write(1, &c, 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}

char    *fp_distributor(char *format, char *output, va_list *ap, char *(*handler[13])()) // To-Do: Pull Va-Arg piece from here, put into each pointer function individually.
{
    int another;
    int which;
    t_format *store;
    char *next;
    int  n;

    another = 1;
    while(another != -1)
    {
       if(*format == '%' && format_len(format) > 1)
        {
            store = read_spec(format + 1);
            which = get_type(*store);
            format += format_len(format);
            next = handle_flags(store, handler[which](ap));
            output = ft_strjoin(output, next);
        }
        else if (*format == '%')
            format++;
        n = ft_strlen(output);
        output = to_next(output, format, &another);
        format += (-1 * (n - ft_strlen(output)));
    }
    return (output);
}

int     ft_printf(const char *format, ...)
{
    va_list ap;
    char    *clone;
    char    *output;
    int		n;

    va_start(ap, format);
    clone = (char *)format;
    output = ft_strdup(""); //need to add strdup to test.
    output = fp_distributor(clone, output, &ap, g_handle);
    va_end(ap);
    ft_putfull(output);
    n = ft_strlen(output);
    return (n);
}
