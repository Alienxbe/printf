/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_ubase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 06:55:14 by mykman            #+#    #+#             */
/*   Updated: 2021/05/15 07:34:16 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_ubase(t_tag *tag, va_list args)
{
	char			*s;
	unsigned int	n;

	s = NULL;
	n = (unsigned int)va_arg(args, unsigned int);
	if (tag->flags & FLAG_PRECISION && tag->flags & FLAG_ZERO)
		tag->flags ^= FLAG_ZERO;
	if (tag->type == U_INT)
		s = ft_utoa_base(n, tag->prec, BASE_DECI);
	else if (tag->type == LC_HEXA)
		s = ft_utoa_base(n, tag->prec, BASE_HEXA_L);
	else if (tag->type == UC_HEXA)
		s = ft_utoa_base(n, tag->prec, BASE_HEXA_U);
	return (ft_print_type(tag, s));
}
