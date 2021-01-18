/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_type_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:47:31 by mykman            #+#    #+#             */
/*   Updated: 2021/01/18 21:37:24 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int pft_type_c(int flags)
{
	char	c;
	int		bef;
	int		aft;
	int		prec;

	char ' ';
	if (pft_isactive(flags, PFT_PREC_N) || pft_isactive(flags, PFT_PREC_VAR))
	{

	}
	if (pft_isactive(flags, PFT_FLAG_MINUS))
	{
		ft_putchar_fd((char)va_arg(g_args, int), 1);
		ft_putmultchar_fd(' ', g_width - 1, 1);
		return (flags);
	}
	c = (pft_isactive(flags, PFT_FLAG_ZERO)) ? '0' : ' ';
	ft_putmultchar_fd(c, g_width - 1, 1);
	ft_putchar_fd((char)va_arg(g_args, int), 1);


	ft_putmultchar_fd(c, bef, 1);
	ft_putmultchar_fd('0', prec, 1);
	ft_putchar_fd((char)va_arg(g_args, int), 1);
	ft_putmultchar_fd(c, aft, 1);
	return (flags);
}

SPACE = WIDTH - 1;
CHAR  = ' '
SI PRECISION:
	PREC = NBR de '0' AVANT TYPE - 1;
SINON ZERO:
	CHAR = '0';
SI MOIN && PAS ZERO:
	SPACE AFTER !

"[CHAR][PRECISION(0)][C][CHAR]"