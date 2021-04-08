/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_type_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:47:44 by mykman            #+#    #+#             */
/*   Updated: 2021/03/03 18:45:24 by mykman           ###   ########.fr       */
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

	w = g_width;
	p = g_prec;
	n = va_arg(g_args, int);
	un = (n < 0) ? -n : n;
	p = (p > ft_intsize(un, un == 0)) ? p - ft_intsize(un, un == 0) : 0;
	w = (w > p + ft_intsize(n, n == 0)) ? w - (p + ft_intsize(n, n == 0)) : 0;
	ft_putmultchar_fd((pft_isactive(flags, PFT_FLAG_ZERO) &&
		!(pft_isactive(flags, PFT_PREC_N) ||
			pft_isactive(flags, PFT_PREC_VAR))) ? '0' : ' ',
		w * !pft_isactive(flags, PFT_FLAG_MINUS), 1);
	ft_putmultchar_fd('-', n < 0, 1);
	ft_putmultchar_fd('0', p, 1);
	putunbr_fd(un, 1);
	ft_putmultchar_fd(' ', w * pft_isactive(flags, PFT_FLAG_MINUS), 1);
	return (p + w + ft_intsize(n, n == 0));
}