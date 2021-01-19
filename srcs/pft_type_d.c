/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_type_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:47:44 by mykman            #+#    #+#             */
/*   Updated: 2021/01/19 19:08:24 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putunbr_fd(unsigned int n, int fd)
{
	if (n > 9)
		putunbr_fd(n / 10, fd);
	ft_putchar_fd('0' + n % 10, fd);
}

int			pft_type_d(int flags)
{
	int				p;
	int				w;
	int				n;
	unsigned int	un;

	p = 0;
	w = 0;
	if (pft_isactive(flags, PFT_WIDTH_N) || pft_isactive(flags, PFT_WIDTH_VAR))
		w = (pft_isactive(flags, PFT_WIDTH_N)) ? g_width : va_arg(g_args, int);
	if (pft_isactive(flags, PFT_PREC_N) || pft_isactive(flags, PFT_PREC_VAR))
		p = (pft_isactive(flags, PFT_PREC_N)) ? g_prec : va_arg(g_args, int);
	n = (int)va_arg(g_args, int);
	un = (n < 0) ? -n : n;
	p = (p > ft_intsize(un, 0)) ? p - ft_intsize(un, 0) : 0;
	w = (w > p + ft_intsize(n, 0)) ? w - (p + ft_intsize(n, 0)) : 0;
	ft_putmultchar_fd((pft_isactive(flags, PFT_FLAG_ZERO) &&
		!(pft_isactive(flags, PFT_PREC_N) ||
			pft_isactive(flags, PFT_PREC_VAR))) ? '0' : ' ',
		w * !pft_isactive(flags, PFT_FLAG_MINUS), 1);
	if (n < 0)
		ft_putchar_fd('-', 1);
	ft_putmultchar_fd('0', p, 1);
	putunbr_fd(un, 1);
	ft_putmultchar_fd(' ', w * pft_isactive(flags, PFT_FLAG_MINUS), 1);
	return (p + w + ft_intsize(n, 0));
}
