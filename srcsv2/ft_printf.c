/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 09:52:47 by mykman            #+#    #+#             */
/*   Updated: 2021/01/19 00:44:24 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int flags;
	int size;

	va_start(g_args, format);
	size = 0;
	while (*format)
	{
		g_width = 0;
		g_prec = 0;
		if (*format == '%')
		{
			flags = pft_conversion(&format);
			size += pft_printconversion(flags);
			if (pft_isactive(flags, PFT_ERROR))
				return (-1);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			size++;
		}
		format++;
	}
	va_end(g_args);
	return (size);
}
