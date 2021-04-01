/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:24:08 by mykman            #+#    #+#             */
/*   Updated: 2021/04/01 19:36:25 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pft_encode_type(const char c)
{
	const char	*type;

	type = PFT_TYPES;
	if (ft_index(type, c) < 0)
		return (PFT_ERROR);
	return (ft_pow(2, ft_index(type, c) + 7));
}

static int	pft_precision(const char **format, int *flags)
{
	int value;

	value = 0;
	while (**format && *++*format == '0')
	{
		*flags += PFT_PREC_ZERO;
		if (*((*format) + 1) == '*')
			*flags += PFT_ERROR;
	}
	*flags += (**format == '*') ? PFT_PREC_VAR : PFT_PREC_N;
	value = ft_atoi(*format);
	if (**format)
		*format += (**format == '*') ? 1 : ft_intsize(ft_atoi(*format), 0);
	return (value);
}

int			pft_conversion(const char **format)
{
	int flags;

	flags = 0;
	if (!++*format)
		return (PFT_ERROR);
	while (**format == '-' || **format == '0') // getting flags
	{
		flags = (**format == '0' && !flags) ? PFT_FLAG_ZERO : flags;
		flags = (*(*format)++ == '-') ? PFT_FLAG_MINUS : flags;
	}
	if (ft_isdigit(**format) || **format == '*') // getting width
	{
		if (ft_isdigit(**format))
			g_width = ft_atoi(*format);
		flags += (**format == '*') ? PFT_WIDTH_VAR : PFT_WIDTH_N;
		*format += (**format == '*') ? 1 : ft_intsize(ft_atoi(*format), 0);
	}
	if (**format == '.')
		g_prec = pft_precision(format, &flags);
	return (flags + pft_encode_type(**format));
}
