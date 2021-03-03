/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:07:15 by mykman            #+#    #+#             */
/*   Updated: 2021/03/03 18:33:32 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	pft_type(int flags)
{
	const char	*type;
	int			i;

	type = PFT_TYPES;
	i = 0;
	if (flags >= PFT_ERROR)
		return ('E');
	while (flags >= ft_pow(2, i + 8))
		i++;
	return (type[i]);
}

int			pft_isactive(int flags, int flag)
{
	int i;

	i = 17;
	while (i--)
	{
		if (ft_pow(2, i) <= flags)
		{
			if (ft_pow(2, i) == flag)
				return (1);
			flags -= ft_pow(2, i);
		}
	}
	return (0);
}

int			pft_printconversion(int flags)
{
	if (pft_isactive(flags, PFT_WIDTH_VAR))
		g_width = va_arg(g_args, int);
	if (pft_isactive(flags, PFT_PREC_VAR))
		g_prec = va_arg(g_args, int);
	if (pft_type(flags) == 'c')
		return (pft_type_c(flags));
	else if (pft_type(flags) == 'p')
		return (pft_type_p_base(flags, PFT_BASE_HEXA_L));
	else if (pft_type(flags) == 's')
		return (pft_type_s(flags));
	else if (pft_type(flags) == 'd' || pft_type(flags) == 'i')
		return (pft_type_d(flags));
	else if (pft_type(flags) == 'u')
		return (pft_type_u_base(flags, PFT_BASE_DECI));
	else if (pft_type(flags) == 'x')
		return (pft_type_u_base(flags, PFT_BASE_HEXA_L));
	else if (pft_type(flags) == 'X')
		return (pft_type_u_base(flags, PFT_BASE_HEXA_U));
	else if (pft_type(flags) == '%')
		return (pft_type_pct(flags));
	return (0);
}
