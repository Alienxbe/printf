/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:50:16 by mykman            #+#    #+#             */
/*   Updated: 2021/05/08 03:28:02 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_c(t_tag *tag, va_list args)
{
	char *s;

	s = (char *)ft_calloc(sizeof(char), 2);
	if (!s)
		return (-1);
	*s = (char)va_arg(args, char); // Compacter ici !
	tag->width--;
	return (ft_print_type(tag, s));
}
