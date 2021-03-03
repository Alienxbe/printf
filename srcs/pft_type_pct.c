/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_type_pct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:51:02 by mykman            #+#    #+#             */
/*   Updated: 2021/03/03 19:02:44 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pft_type_pct(int flags)
{
	int	w;

	w = g_width;
	w = (w <= 1) ? 0 : w - 1;
	ft_putmultchar_fd((pft_isactive(flags, PFT_FLAG_ZERO)) ? '0' : ' ',
		w * !pft_isactive(flags, PFT_FLAG_MINUS), 1);
	ft_putchar_fd('%', 1);
	ft_putmultchar_fd(' ', w * pft_isactive(flags, PFT_FLAG_MINUS), 1);
	return (w + 1);
}