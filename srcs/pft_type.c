/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:07:15 by mykman            #+#    #+#             */
/*   Updated: 2021/01/18 21:05:50 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pft_isactive(int flags, int flag)
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

int pft_printflag(int flags)
{
	return (flags);
}