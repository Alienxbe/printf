/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_type_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:47:31 by mykman            #+#    #+#             */
/*   Updated: 2021/03/03 18:42:13 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** "[n * CHAR * !sign][PRECISION(0)][C][n * CHAR * sign]"
*/

int	pft_type_c(int flags)
{
	int	w;

	w = g_width;
	w = (w <= 1) ? 0 : w - 1;
	ft_putmultchar_fd((pft_isactive(flags, PFT_FLAG_ZERO)) ? '0' : ' ',
		w * !pft_isactive(flags, PFT_FLAG_MINUS), 1);
	ft_putchar_fd((char)va_arg(g_args, int), 1);
	ft_putmultchar_fd(' ', w * pft_isactive(flags, PFT_FLAG_MINUS), 1);
	return (w + 1);
}
