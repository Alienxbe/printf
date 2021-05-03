/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:50:16 by mykman            #+#    #+#             */
/*   Updated: 2021/05/03 18:55:18 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(t_tag *tag, va_list args)
{
	char c_pad;

	c_pad = ' ';
	if (tag->flags & FLAG_ZERO)
		c_pad = '0';
	tag->width--;
	ft_padding(c_pad, tag->width * ((tag->flags & FLAG_MINUS) <= 0));
	ft_putchar_fd((char)va_arg(args, int), 1);
	ft_padding(c_pad, tag->width * ((tag->flags & FLAG_MINUS) > 0));
	return (0);
}