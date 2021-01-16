/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:24:08 by mykman            #+#    #+#             */
/*   Updated: 2021/01/14 15:41:49 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 1 : 0
** 2 : -
** 4 : width
** 8 : precision
** 16 : c
** 32 : s
** 64 : p
** 128 : d
** 256 : i
** 512 : u
** 1024 : x
** 2048 : X
** 4096 : %
** 8192 : ERROR
*/

static int	ft_type(const char *format)
{
	if (*format == 'c')
		return (16);
	else if (*format == 's')
		return (32);
	else if (*format == 'p')
		return (64);
	else if (*format == 'd')
		return (128);
	else if (*format == 'i')
		return (256);
	else if (*format == 'u')
		return (512);
	else if (*format == 'x')
		return (1024);
	else if (*format == 'X')
		return (2048);
	else if (*format == '%')
		return (4096);
	return (8192);

}

int	ft_conversion(const char *format)
{
	int out;

	out = 0;
	while (*format == '-' || *format == '0')
	{
		out = (*format == '0' && !out) ? 1 : out;
		out = (*format++ == '-') ? 2 : out;
	}
	if (ft_atoi(format) || *format == '*')
	{
		out += 4;
		format += (*format == '*') ? 1 : ft_intsize(ft_atoi(format), 0);
	}
	if (*format == '.')
	{
		out += 8;
		format++;
		format += (*format == '*') ? 1 : ft_intsize(ft_atoi(format), 0) + 1;
	}
	return (out + ft_type(format));
}