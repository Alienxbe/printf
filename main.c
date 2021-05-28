/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:34:49 by mykman            #+#    #+#             */
/*   Updated: 2021/05/28 03:42:27 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <unistd.h>
#include <stdio.h>

typedef union u_float_cast
{
	float	f;
	struct
	{
		unsigned int	mantisa : 23;
		unsigned int	exponent : 8;
		unsigned int	sign : 1;
	}	s_parts;
}	t_float_cast;

typedef union u_double
{
	double	d;
	struct
	{
		unsigned long	mantisa : 52;
		unsigned int	exponent : 11;
		unsigned int	sign : 1;
	}	s_parts;
}	t_double;

int	main(void)
{
	t_float_cast	n;
	int				m_size = 23;
	int				e_size = 8;
	unsigned long	full_mantisa; // With a 1 bit before everything
	unsigned long	true_exponent;
	unsigned long	floating_part;

	n.f = 3596.0;
	full_mantisa = (n.s_parts.mantisa | 1L << m_size);
	true_exponent = n.s_parts.exponent - (1 << (e_size - 1));
	floating_part = true_exponent + 1;
	printf("%d %lu\n", n.s_parts.sign,
	// This compute the real part of float / double
		full_mantisa >> (m_size - floating_part));


	return (0);
}
