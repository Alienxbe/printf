/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 00:32:07 by mykman            #+#    #+#             */
/*   Updated: 2021/05/08 02:17:31 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_s(t_tag *tag, va_list args)
{
	char	*s;
	char	c_pad;

	c_pad = ' ';
	if (tag->flags & FLAG_ZERO)
		c_pad = '0';
	return (0);
}
