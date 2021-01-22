/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_type_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:49:03 by mykman            #+#    #+#             */
/*   Updated: 2021/01/22 14:06:35 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putnbr_ubase_fd(unsigned long n, char *base, int fd)
{
	int				n_base;

	n_base = ft_strlen(base);
	if (n > (unsigned int)n_base - 1)
		putnbr_ubase_fd(n / n_base, base, fd);
	ft_putchar_fd(base[n % n_base], fd);
}

static int	usize_base(unsigned long n, char *base, int c)
{
	if (!n)
		return (c);
	return (usize_base(n / ft_strlen(base), base, c + 1));
}

int			pft_type_p_base(int flags, char *base)
{
	int				p;
	int				w;
	unsigned long	n;

	p = 0;
	w = 0;
	if (pft_isactive(flags, PFT_WIDTH_N) || pft_isactive(flags, PFT_WIDTH_VAR))
		w = (pft_isactive(flags, PFT_WIDTH_N)) ? g_width : va_arg(g_args, int);
	if (pft_isactive(flags, PFT_PREC_N) || pft_isactive(flags, PFT_PREC_VAR))
		p = (pft_isactive(flags, PFT_PREC_N)) ? g_prec : va_arg(g_args, int);
	n = va_arg(g_args, unsigned long);
	p = (p > usize_base(n, base, 0)) ? p - usize_base(n, base, 0): 0;
	w = (w > p + usize_base(n, base, 0)) ? w - (p + usize_base(n, base, 0) + 2) : 0;
	ft_putmultchar_fd((pft_isactive(flags, PFT_FLAG_ZERO) &&
		!(pft_isactive(flags, PFT_PREC_N) ||
			pft_isactive(flags, PFT_PREC_VAR))) ? '0' : ' ',
		w * !pft_isactive(flags, PFT_FLAG_MINUS), 1);
	ft_putstr_fd("0x", 1);
	ft_putmultchar_fd('0', p, 1);
	putnbr_ubase_fd(n, base, 1);
	ft_putmultchar_fd(' ', w * pft_isactive(flags, PFT_FLAG_MINUS), 1);
	return (p + w + usize_base(n, base, 0));
}