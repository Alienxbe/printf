/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 09:52:47 by mykman            #+#    #+#             */
/*   Updated: 2021/01/14 16:05:19 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format)
{
	int i;
	int out;

	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			out = ft_conversion(format + i + 1);
			ft_putstr_fd("Flags : ", 1);
			ft_putnbr_fd(out, 1);
			if (out >= 8192)
				ft_putendl_fd("\nFLAG ERROR", 1);
			ft_putendl_fd("\n-------------", 1);
		}
	}
	return (0);
}