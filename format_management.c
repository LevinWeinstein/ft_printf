/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:41:03 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/19 03:26:45 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			format_len(char *str)
{
	int i;
	int j;

	j = 0;
	i = 1;
	if (ft_strlen(str) == 1)
		return (1);
	while (i != j)
	{
		j = i;
		i += is_flag(&str[i]);
		i += is_field(&str[i]);
		i += is_precision(&str[i]);
		i += is_modifier(&str[i]);
		if (is_conversion(*(&str[i])))
			return (i + is_conversion(*(&str[i])));
	}
	return (1);
}

t_format	*new_format(void)
{
	t_format	*new;

	new = (t_format *)malloc(sizeof(t_format));
	new->flags = NULL;
	new->field = 0;
	new->precision = -1;
	new->modifier = NULL;
	new->conversion = 0;
	new->next = NULL;
	return (new);
}

t_format	*read_spec(char *str)
{
	int			i;
	char		*string;
	t_format	*new;

	string = ft_strdup(str);
	new = new_format();
	if ((i = is_flag(string)) > 0)
		new->flags = ft_strndup(string, is_flag(string));
	string += i;
	if ((i = is_field(string)) > 0)
		new->field = ft_atoi(string);
	string += i;
	if ((i = is_precision(string)) > 0)
		new->precision = ft_isdigit(string[1]) ? ft_atoi(string + 1) : 0;
	string += i;
	if ((i = is_modifier(string)) > 0)
		new->modifier = ft_strndup(string, is_modifier(string));
	string += i;
	if (is_conversion(*(string)))
		new->conversion = *string;
	return (new);
}

void		check_edge(t_flag *flag, t_format *s)
{
	if (flag->zero && is_number(s) && s->precision > 0)
		flag->zero = 0;
}

void		store_flag(t_flag *flag, char *flag_str, t_format *s)
{
	int i;

	i = 0;
	if (flag_str == NULL)
	{
		flag->hash = 0;
		flag->plus = 0;
		flag->minus = 0;
		flag->zero = 0;
		flag->space = 0;
		return ;
	}
	while (flag_str[i] && !(flag->hash && flag->plus
				&& flag->minus && flag->zero && flag->space))
	{
		flag->hash = (flag_str[i] == '#' || flag->hash == 1) ? 1 : 0;
		flag->plus = (flag_str[i] == '+' || flag->plus == 1) ? 1 : 0;
		flag->minus = (flag_str[i] == '-' || flag->minus == 1) ? 1 : 0;
		flag->zero = (flag_str[i] == '0' || flag->zero == 1) ? 1 : 0;
		check_edge(flag, s);
		flag->space = (flag_str[i] == ' ' || flag->space == 1) ? 1 : 0;
		i++;
	}
}
