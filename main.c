/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:34:49 by mykman            #+#    #+#             */
/*   Updated: 2021/05/25 03:56:12 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <unistd.h>
#include <stdio.h>

typedef union u_float_cast
{
	float d;
	struct
	{
		unsigned int mantisa : 23;
		unsigned int exponent : 8;
		unsigned int sign : 1;
	}	s_parts;
} t_float_cast;

int	main(void)
{
	t_float_cast f1;

	f1.d = 3.14;
	printf("Sign : %d\n", f1.s_parts.sign);
	printf("Exponent : %d\n", f1.s_parts.exponent);
	printf("mantisa : %d\n", f1.s_parts.mantisa);
	printf("sizeof : %lu\n", sizeof(f1.s_parts));
	return (0);
}



/*
**								(4 octets)
** (unsigned int) 2147483647 = 0111...1111 = (int)  2147483647
** (unsigned int) 2147483648 = 1000...0000 = (int) -2147483648
** (unsigned int) 2147483649 = 1000...0001 = (int) -2147483647
**							    (32 bits)
*/

