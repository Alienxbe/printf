/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:07:15 by mykman            #+#    #+#             */
/*   Updated: 2021/01/19 00:46:31 by mykman           ###   ########.fr       */
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
	if (pft_type(flags) == 'c')
		return (pft_type_c(flags));
	return (0);
}
