/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 09:52:47 by mykman            #+#    #+#             */
/*   Updated: 2021/01/16 13:10:03 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_type(int out)
{
	const char	*type;
	int			i;

	type = "cspdiuxX%";
	i = 0;
	while (out >= ft_pow(2, i + 5))
		i++;
	return (type[i]);
}

int	ft_printf(const char *format, ...)
{
	int out;
	int size;
	va_list args;

	size = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			out = ft_conversion(&format);
			ft_putstr_fd("{Flags : ", 1);
			ft_putchar_fd(ft_type(out), 1);
			/*if (out < 8192)
				i++;*/
			ft_putchar_fd('}', 1);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			size++;
		}
		format++;
	}
	ft_putnbr_fd((int)va_arg(args, char *), 1);
	va_end(args);
	return (size);
}