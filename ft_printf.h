/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 01:24:16 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/15 04:50:44 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "./libft/libft.h"
#include <wchar.h>

extern const char g_conversions[];
extern const char g_values[];
extern char    *(*handle[13])();

enum values
{
	e_int,
	e_long,
	e_longlong,
	e_unsigned,
	e_hex_lower,
	e_hex_upper,
	e_pointer,
	e_octal,
	e_char,
	e_str,
	e_wchar,
	e_wstr,
	e_modulus,
};

typedef struct				s_flag
{
	int						hash;
	int						plus;
	int						minus;
	int						zero;
	int						space;
}							t_flag;

typedef	struct s_format		t_format;

struct						s_format
{
	char					*flags;
	t_flag					flag;
	int						field;
	int						precision;
	char					*modifier;
	char					conversion;
	t_format				*next;
};

char						*fp_char(va_list *val);
char						*fp_str(va_list *val);
char						*fp_wchar(va_list *val);
char						*fp_wstr(va_list *val);
char						*fp_mod(void);
char						*fp_x_lower(va_list *val);
char						*fp_x_upper(va_list *val);
char						*fp_ptr(va_list *val);
char						*fp_o(va_list *val);
char						*fp_d(va_list *val);
char						*fp_l(va_list *val);
char						*fp_ll(va_list *val);
char						*fp_u(va_list *val);
char						*ft_wchar(wchar_t wc);
char						*ft_wstr(wchar_t *wstr);
char    					*ft_utoa_ptr(unsigned long long value, int base);
int							is_flag(const char *str);
int							is_field(const char *str);
int							is_precision(const char *str);
int							is_modifier(const char *str);
int							is_conversion(const char c);
int         				format_len(char *str);
t_format					*new_format(void);
t_format					*read_spec(char *str);
void    					store_flag(t_flag *flag, char *flag_str);
char						*to_next(char *output, char *str, int *another);
char    					*next_flag(void *next, char *(*handler[13])(void *), int format);
int     					get_type(t_format unread);
int    						is_number(t_format *saved);
char 						*handle_flags(t_format *saved, char *str);
char						*add_0x(char *str, char c);
char						*add_0(char *str);
char						*add_plus(char *str);
char						*add_space(char *str);
char						*field_width(char *str, int n);
char						*left_width(char *str, int n);
char						*zero_width(char *str, int n);
char    					*fp_distributor(char *format, char *output, va_list *ap, char *(*handler[13])(void *));
int							ft_printf(const char *format, ...);

#endif
