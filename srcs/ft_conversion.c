/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:24:08 by mykman            #+#    #+#             */
/*   Updated: 2021/01/16 15:39:47 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 2**0		| 1		: 0
** 2**1		| 2		: -
** 2**2		| 4		: width
** 2**3		| 8		: precision
** 2**4		| 16	: c
** 2**5		| 32	: s
** 2**6		| 64	: p
** 2**7		| 128	: d
** 2**8		| 256	: i
** 2**9		| 512	: u
** 2**10	| 1024	: x
** 2**11	| 2048	: X
** 2**12	| 4096	: %
** 2**13	| 8192	: ERROR
*/

static int	ft_type(const char c)
{
	const char	*type;

	type = "cspdiuxX%";
	if (ft_index(type, c) < 0)
		return (8192);
	return (ft_pow(2, ft_index(type, c) + 4));
}

int			ft_conversion(const char **format)
{
	int out;

	out = 0;
	while (**format == '-' || **format == '0')
	{
		out = (**format == '0' && !out) ? 1 : out;
		out = (*(*format)++ == '-') ? 2 : out;
	}
	if (ft_isdigit(**format) || **format == '*')
	{
		out += 4;
		*format += (**format == '*') ? 1 : ft_intsize(ft_atoi(*format), 0);
	}
	if (**format == '.')
	{
		while (*++*format == '0')
			if (*((*format) + 1) == '*')
				out += 8192;
		out += 8;
		*format += (**format == '*') ? 1 : ft_intsize(ft_atoi(*format), 0);
	}
	return (out + ft_type(**format));
}
