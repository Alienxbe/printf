/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_type_u_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:17:56 by mykman            #+#    #+#             */
/*   Updated: 2021/03/03 19:02:41 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putnbr_ubase_fd(unsigned int n, char *base, int fd)
{
	int				n_base;

	n_base = ft_strlen(base);
	if (n > (unsigned int)n_base - 1)
		putnbr_ubase_fd(n / n_base, base, fd);
	ft_putchar_fd(base[n % n_base], fd);
}

static int	usize_base(unsigned int n, char *base, int c)
{
	if (!n)
		return (c);
	return (usize_base(n / ft_strlen(base), base, c + 1));
}

int			pft_type_u_base(int flags, char *base)
{
	int				p;
	int				w;
	unsigned long	n;

	p = g_prec;
	w = g_width;
	n = va_arg(g_args, unsigned int);
	p = (p > usize_base(n, base, 0)) ? p - usize_base(n, base, 0) : 0;
	w = (w > p + usize_base(n, base, 0)) ? w - (p + usize_base(n, base, 0)) : 0;
	ft_putmultchar_fd((pft_isactive(flags, PFT_FLAG_ZERO) &&
		!(pft_isactive(flags, PFT_PREC_N) ||
			pft_isactive(flags, PFT_PREC_VAR))) ? '0' : ' ',
		w * !pft_isactive(flags, PFT_FLAG_MINUS), 1);
	ft_putmultchar_fd('0', p, 1);
	putnbr_ubase_fd(n, base, 1);
	ft_putmultchar_fd(' ', w * pft_isactive(flags, PFT_FLAG_MINUS), 1);
	return (p + w + usize_base(n, base, 0));
}