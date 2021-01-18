/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:07:15 by mykman            #+#    #+#             */
/*   Updated: 2021/01/18 14:36:56 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pft_isactive(int flags, int flag)
{
	int i;

	i = 15;
	while (i && flags)
	{
		if (ft_pow(2, i) <= flags)
		{
			if (ft_pow(2, i) == flag)
				return (1);
			flags -= ft_pow(2, i);
		}
		i--;
	}
	return (0);
}

int pft_type_c(int flags)
{
	ft_putchar_fd((char)va_arg(g_args, int), 1);
	return (flags);
}

int pft_printflag(int flags)
{
	return (flags);
}