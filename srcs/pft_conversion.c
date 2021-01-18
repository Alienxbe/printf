/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:24:08 by mykman            #+#    #+#             */
/*   Updated: 2021/01/18 14:36:48 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pft_encode_type(const char c)
{
	const char	*type;

	type = PF_TYPES;
	if (ft_index(type, c) < 0)
		return (PF_ERROR);
	return (ft_pow(2, ft_index(type, c) + 6));
}

int			pft_conversion(const char **format)
{
	int flags;

	flags = 0;
	if (!*format)
		return (PFT_ERROR);
	while (**format == '-' || **format == '0')
	{
		flags = (**format == '0' && !flags) ? PFT_FLAG_ZERO : flags;
		flags = (*(*format)++ == '-') ? PFT_FLAG_MINUS : flags;
	}
	if (ft_isdigit(**format) || **format == '*')
	{
		flags += (**format == '*') ? PFT_WIDTH_VAR : PFT_WIDTH_N;
		*format += (**format == '*') ? 1 : ft_intsize(ft_atoi(*format), 0);
	}
	if (**format == '.' && (*(*format + 1) == '*' || ft_isdigit(*(*format + 1))))
	{
		while (*++*format == '0')
		{
			flags += !pft_isactive(flags, PFT_FLAG_ZERO);
			if (*((*format) + 1) == '*')
				flags += 8192;
		}
		flags += (**format == '*') ? PFT_PREC_VAR  : PFT_PREC_N;
		*format += (**format == '*') ? 1 : ft_intsize(ft_atoi(*format), 0);
	}
	return (flags + pft_encode_type(**format));
}
