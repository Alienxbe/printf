/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 02:19:32 by mykman            #+#    #+#             */
/*   Updated: 2021/05/08 02:46:51 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_type(t_tag *tag, char *s)
{
	char c_pad;

	c_pad = ' ';
	if (tag->flags & FLAG_ZERO)
		c_pad = '0';
	ft_padding(c_pad, tag->width * ((tag->flags & FLAG_MINUS) <= 0));
	ft_putstr_fd(s, 1);
	ft_padding(c_pad, tag->width * ((tag->flags & FLAG_MINUS) > 0));
	free(s);
	return (0);
}
