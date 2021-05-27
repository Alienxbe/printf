/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:34:49 by mykman            #+#    #+#             */
/*   Updated: 2021/05/27 01:39:13 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <unistd.h>
#include <stdio.h>

typedef union u_float_cast
{
	float f;
	struct
	{
		unsigned int mantisa : 23;
		unsigned int exponent : 8;
		unsigned int sign : 1;
	}	s_parts;
} t_float_cast;

typedef union u_double
{
	double d;
	struct
	{
		unsigned long mantisa : 52;
		unsigned int exponent : 11;
		unsigned int sign : 1;
	}	s_parts;
}	t_double;

int	main(void)
{
	printf("%g", 1777752.3451651651);
	return (0);
}



/*
**								(4 octets)
** (unsigned int) 2147483647 = 0111...1111 = (int)  2147483647
** (unsigned int) 2147483648 = 1000...0000 = (int) -2147483648
** (unsigned int) 2147483649 = 1000...0001 = (int) -2147483647
**							    (32 bits)
*/
