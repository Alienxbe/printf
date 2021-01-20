/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:17:20 by mykman            #+#    #+#             */
/*   Updated: 2021/01/20 10:53:50 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft/includes/libft.h"

/*
** 2**0		| 1		: 0
** 2**1		| 2		: -
** 2**2		| 4		: width_n
** 2**3		| 8		: width_var
** 2**4		| 16	: precision_n
** 2**5		| 32	: precision_var
** 2**6		| 64	: precision_flag_0
** 2**7		| 128	: c
** 2**8		| 256	: s
** 2**9		| 512	: p
** 2**10	| 1024	: d
** 2**11	| 2048	: i
** 2**12	| 4096	: u
** 2**13	| 8192	: x
** 2**14	| 16384	: X
** 2**15	| 32768 : %%
** 2**16	| 65536	: ERROR
*/

# define PFT_FLAG_ZERO		1
# define PFT_FLAG_MINUS		2
# define PFT_WIDTH_N		4
# define PFT_WIDTH_VAR		8
# define PFT_PREC_N			16
# define PFT_PREC_VAR		32
# define PFT_PREC_ZERO		64
# define PFT_ERROR			65536

# define PFT_TYPES			"cspdiuxX%"
# define PFT_NULL_STR		"(null)"
# define PFT_BASE_DECI		"0123456789"
# define PFT_BASE_HEXA_L	"0123456789abcdef"
# define PFT_BASE_HEXA_U	"0123456789ABCDEF"

va_list g_args;
int		g_width;
int		g_prec;

/*
** Main functions
*/

int	ft_printf(const char *format, ...);
int	pft_conversion(const char **format);
int	pft_isactive(int flags, int flag);

/*
** Print convertion functions
*/

int pft_printconversion(int flags);
int pft_type_c(int flags);
int pft_type_s(int flags);
int	pft_type_d(int flags);
int	pft_type_u_base(int flags, char *base);
int	pft_type_pct(int flags);

#endif
