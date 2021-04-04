/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:21:31 by mykman            #+#    #+#             */
/*   Updated: 2021/04/04 19:07:23 by mykman           ###   ########.fr       */
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
			printf("\nConvertion detected !\n Flags: %d\n", tag->flags);
			printf(" Width: %d\n", tag->width);
			printf(" Prec: %d\n", tag->prec);
			printf(" Type: %d\n", tag->type);
			free(tag);
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