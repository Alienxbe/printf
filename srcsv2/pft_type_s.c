/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_type_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 09:34:26 by mykman            #+#    #+#             */
/*   Updated: 2021/03/03 19:02:43 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** [CHAR][STRING[:prec char]][CHAR]
*/

int	pft_type_s(int flags)
{
	char	*s;
	int		p;
	int		w;

	p = g_prec;
	w = g_width;
	s = (char *)va_arg(g_args, char *);
	s = (!s) ? PFT_NULL_STR : s;
	p = (p > (int)ft_strlen(s)) ? (int)ft_strlen(s) : p;
	if (!pft_isactive(flags, PFT_PREC_N) && !pft_isactive(flags, PFT_PREC_VAR))
		p = ft_strlen(s);
	w = (p < w) ? w - p : 0;
	ft_putmultchar_fd((pft_isactive(flags, PFT_FLAG_ZERO)) ? '0' : ' ',
		w * !pft_isactive(flags, PFT_FLAG_MINUS), 1);
	write(1, s, p);
	ft_putmultchar_fd(' ', w * pft_isactive(flags, PFT_FLAG_MINUS), 1);
	return (w + p);
}
