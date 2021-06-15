/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:34:49 by mykman            #+#    #+#             */
/*   Updated: 2021/06/15 15:24:38 by mykman           ###   ########.fr       */
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
	//int				e_size = 8;
	unsigned long	mantisa_val; // With a 1 bit before everything
	long	exponent_val;
	//unsigned long	real_dec;
	unsigned long 	float_dec;
	int bit;

	n.f = 3.56860899925;
	mantisa_val = (n.s_parts.mantisa | 1L << m_size);
	exponent_val = n.s_parts.exponent - 127;
	printf("%d 	      | %ld\n", n.s_parts.exponent, exponent_val);
	printf("Mantisa encoded: %u\n", n.s_parts.mantisa);
	printf("Sign: %d\nReal value: %lu\n\n", n.s_parts.sign, mantisa_val >> (m_size - exponent_val));
	if (exponent_val <= 0)
		bit = m_size - 1;
	else
		bit = m_size - exponent_val - 1;
	printf("Floating bit number: %d\n", bit);
	float_dec = 0;
	while (bit >= 0)
	{
		printf("%-3ld : %d", m_size - exponent_val - bit, (n.s_parts.mantisa >> (bit)) & 1);
		if ((n.s_parts.mantisa >> (bit)) & 1)
		{
			printf("%20llu\n", ft_pow(5, m_size - exponent_val - bit) * ft_pow(10, bit));
			float_dec += ft_pow(5, m_size - exponent_val - bit) * ft_pow(10, bit);
			// Overflow ici !!!
			// Solutions : Strings maths or New type w/ struct
		}
		else
			printf("\n");
		bit--;
	}
	printf("\ncustom: %lu.%lu\n", mantisa_val >> (m_size - exponent_val), float_dec);
	printf("printf: %f\n", n.f);
	return (0);
}
