/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:21:31 by mykman            #+#    #+#             */
/*   Updated: 2021/04/01 20:23:03 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_tag	*tag;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			tag = ft_conversion(&format, args);
			if (!tag)
				return (MALLOC_ERROR);
			printf("\nwidth : %d\nFlags : %d\n", tag->width, tag->flags);
			free(tag);
			ft_putchar_fd('s', 1);
		}
		else
		{
			ft_putchar_fd(*format, 1);
		}
		format++;
	}
	va_end(args);
	return (0);
}