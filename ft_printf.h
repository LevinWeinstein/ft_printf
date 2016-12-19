/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 01:24:16 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/19 05:06:28 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <wchar.h>

extern const char			g_conversions[];
extern const char			g_values[];
extern char					*(*g_handle[34])();

enum						e_values
{
	e_int, e_long, e_longlong, e_unsigned,
	e_hex_lower, e_hex_upper, e_pointer, e_octal,
	e_char, e_str, e_wchar, e_wstr, e_modulus, e_uc,
	e_ulong, e_ulonglong, e_ichar, e_short, e_r,
	e_z, e_oc, e_os, e_olong, e_olonglong, e_cx_lower,
	e_cx_upper, e_sx_lower, e_sx_upper, e_lx_lower,
	e_lx_upper, e_llx_lower, e_llx_upper, e_us,
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
char						*fp_cx_lower(va_list *val);
char						*fp_cx_upper(va_list *val);
char						*fp_sx_lower(va_list *val);
char						*fp_sx_upper(va_list *val);
char						*fp_lx_lower(va_list *val);
char						*fp_lx_upper(va_list *val);
char						*fp_llx_lower(va_list *val);
char						*fp_llx_upper(va_list *val);
char						*fp_ptr(va_list *val);
char						*fp_oc(va_list *val);
char						*fp_os(va_list *val);
char						*fp_o(va_list *val);
char						*fp_ol(va_list *val);
char						*fp_oll(va_list *val);
char						*fp_d(va_list *val);
char						*fp_l(va_list *val);
char						*fp_ll(va_list *val);
char						*fp_ic(va_list *val);
char						*fp_sd(va_list *val);
char						*fp_u(va_list *val);
char						*fp_uc(va_list *val);
char						*fp_us(va_list *val);
char						*fp_ul(va_list *val);
char						*fp_ull(va_list *val);
char						*ft_wchar(wchar_t wc);
char						*ft_wstr(wchar_t *wstr);
char						*ft_utoa_ptr(uintmax_t value, int base);
int							is_flag(const char *str);
int							is_field(const char *str);
int							is_precision(const char *str);
int							is_modifier(const char *str);
int							is_conversion(const char c);
int							format_len(char *str);
t_format					*new_format(void);
t_format					*read_spec(char *str);

void						store_flag(t_flag *flag, char
							*flag_str, t_format *s);

char						*to_next(char *output, char *str, int *another);

char						*next_flag(void *next,
							char *(*handler[34])(void *), int format);

int							get_type(t_format unread);
int							is_number(t_format *saved);
char						*handle_flags(t_format *saved, char *str);
char						*add_0x(char *str, char c);
char						*add_0(char *str);
char						*add_plus(char *str);
char						*add_space(char *str);
char						*field_width(char *str, int n);
char						*left_width(char *str, int n);
char						*zero_width(char *str, int n);

char						*fp_distributor(char *format, char *output,
							va_list *ap, char *(*handler[20])(void *));

int							ft_printf(const char *format, ...);
char						negcheck(char *str);
int							pign(char c);
char						*fp_r(void);
char						*fp_z(void);

int							is_lower(char c);
int							cs(int c, int s, char spec, char *len);
int							handle_u(char *str, char c);
int							handle_low_x(char *str);
int							handle_up_x(char *str);
int							handle_x(t_format saved);
int							handle_o(char *str, char c);
int							small_d(t_format unread);
int							parse_singles(char c);
int							iszero(t_format *format, char *str);
int							is_did(char c);
void						check_edge(t_flag *flag, t_format *s);
void						ft_putfull(char *str);
char						*check_err(char *str);

#endif
