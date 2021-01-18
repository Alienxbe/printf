/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:17:20 by mykman            #+#    #+#             */
/*   Updated: 2021/01/18 14:34:38 by mykman           ###   ########.fr       */
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
** 2**6		| 64	: c
** 2**7		| 128	: s
** 2**8		| 256	: p
** 2**9		| 512	: d
** 2**10	| 1024	: i
** 2**11	| 2048	: u
** 2**12	| 4096	: x
** 2**13	| 8192	: X
** 2**14	| 16384	: %
** 2**15	| 32768 : ERROR
*/

# define PFT_TYPES		"cspdiuxX%"
# define PFT_FLAG_ZERO	1
# define PFT_FLAG_MINUS	2
# define PFT_WIDTH_N	4
# define PFT_WIDTH_VAR	8
# define PFT_PREC_N		16
# define PFT_PREC_VAR	32
# define PTF_ERROR		32768

va_list g_args;

/*
** Main functions
*/

int	ft_printf(const char *format, ...);
int	pft_conversion(const char **format);
int	pft_isactive(int flags, int flag);

/*
** Print convertion functions
*/

int pft_type_c(int flags);

#endif
