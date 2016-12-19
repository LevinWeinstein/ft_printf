/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_definitions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:47:18 by lweinste          #+#    #+#             */
/*   Updated: 2016/12/19 04:42:27 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	g_values[] = {
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
	'A',
	'B',
	'C',
	'D',
	'E',
	'F'};

const char	g_conversions[] = "diDuUxXpoOcsCSZR%";

char		*(*g_handle[34])() = {
	fp_d, fp_l,
	fp_ll, fp_u,
	fp_x_lower, fp_x_upper,
	fp_ptr, fp_o, fp_char,
	fp_str, fp_wchar,
	fp_wstr, fp_mod, fp_uc, fp_ul, fp_ull,
	fp_ic, fp_sd, fp_r, fp_z, fp_oc,
	fp_os, fp_ol, fp_oll, fp_cx_lower, fp_cx_upper, fp_sx_lower,
	fp_sx_upper, fp_lx_lower, fp_lx_upper, fp_llx_lower, fp_llx_upper, fp_us
};
