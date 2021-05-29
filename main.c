/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:34:49 by mykman            #+#    #+#             */
/*   Updated: 2021/05/30 00:10:26 by mykman           ###   ########.fr       */
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
	unsigned long	mantisa_val; // With a 1 bit before everything
	long	exponent_val;
	//unsigned long	real_dec;
	unsigned long 	float_dec;
	int bit;

	n.f = 0.1526;
	mantisa_val = (n.s_parts.mantisa | 1L << m_size);
	exponent_val = n.s_parts.exponent - 127;
	printf("%d | %ld\n", n.s_parts.exponent - (1 << (e_size - 1)) - 2, exponent_val);
	printf("Mantisa encoded: %u\n", n.s_parts.mantisa);
	printf("Sign: %d\nReal value: %lu\n\n", n.s_parts.sign, mantisa_val >> (m_size - exponent_val));
	bit = m_size - exponent_val - 1;
	float_dec = 0;
	while (bit > 0)
	{
		printf("%d", (n.s_parts.mantisa >> (bit)) & 1);
		if ((n.s_parts.mantisa >> (bit)) & 1)
			float_dec += ft_pow(5, m_size - exponent_val - bit) * ft_pow(10, bit - 1);
		bit--;
	}
	printf("\n%lu.%lu\n", mantisa_val >> (m_size - exponent_val), float_dec);
	return (0);
}
