/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 09:52:47 by mykman            #+#    #+#             */
/*   Updated: 2021/01/18 21:07:59 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	pft_type(int out)
{
	const char	*type;
	int			i;

	type = PFT_TYPES;
	i = 0;
	if (out >= PFT_ERROR)
		return ('E');
	while (out >= ft_pow(2, i + 8))
		i++;
	return (type[i]);
}

int	ft_printf(const char *format, ...)
{
	int flags;
	int size;

	va_start(g_args, format);
	size = 0;
	while (*format)
	{
		g_width = 0;
		g_prec = 0;
		if (*format == '%')
		{
			format++;
			flags = pft_conversion(&format);
			/*ft_putstr_fd("{Flags : ", 1);
			ft_putnbr_fd(pft_isactive(flags, PFT_FLAG_ZERO), 1);
			ft_putchar_fd(pft_type(flags), 1);
			ft_putchar_fd('}', 1);*/
			pft_type_c(flags);
			if (pft_isactive(flags, PFT_ERROR))
				return (0);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			size++;
		}
		format++;
	}
	va_end(g_args);
	return (size);
}