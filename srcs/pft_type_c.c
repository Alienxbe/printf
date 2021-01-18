/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_type_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:47:31 by mykman            #+#    #+#             */
/*   Updated: 2021/01/19 00:17:10 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** "[CHAR][PRECISION(0)][C][CHAR]"
*/

int	pft_type_c(int flags)
{
	int	prec;
	int	n;

	prec = 0;
	n = 0;
	if (pft_isactive(flags, PFT_WIDTH_N) || pft_isactive(flags, PFT_WIDTH_VAR))
		n = (pft_isactive(flags, PFT_WIDTH_N)) ? g_width : va_arg(g_args, int);
	if (pft_isactive(flags, PFT_PREC_N) || pft_isactive(flags, PFT_PREC_VAR))
		prec = (pft_isactive(flags, PFT_PREC_N)) ? g_prec : va_arg(g_args, int);
	prec = (prec <= 1) ? 0 : prec - 1;
	n = (n <= prec + 1) ? 0 : n - (prec + 1);
	ft_putmultchar_fd((pft_isactive(flags, PFT_FLAG_ZERO)) ? '0' : ' ',
		n * !pft_isactive(flags, PFT_FLAG_MINUS), 1);
	ft_putmultchar_fd('0', prec, 1);
	ft_putchar_fd((char)va_arg(g_args, int), 1);
	ft_putmultchar_fd(' ', n * pft_isactive(flags, PFT_FLAG_MINUS), 1);
	return (prec + n + 1);
}
