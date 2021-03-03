/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:34:49 by mykman            #+#    #+#             */
/*   Updated: 2021/03/03 21:42:57 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

va_list g_args;

unsigned long long get_arg(int type)
{
	if (type == 1)
		return ((unsigned long long)va_arg(g_args, int));
	if (type == 2)
		return ((unsigned long long)va_arg(g_args, long long));
	return (0);
}


void func(int n, ...)
{
	va_start(g_args, n);
	printf("%llu\n", get_arg(2));
	va_end(g_args);
}

int	main(void)
{
	// ft_printf("Bonjour '%.d'", 150);
	// printf("%lu %lu\n", sizeof(int), sizeof(long long));
	// unsigned int n = 2147483650;
	// printf("%d\n", (int)n);
	func(5, 2147483650);
	return (0);
}

/*
**								(4 octets)
** (unsigned int) 2147483647 = 0111...1111 = (int)  2147483647
** (unsigned int) 2147483648 = 1000...0000 = (int) -2147483648
** (unsigned int) 2147483649 = 1000...0001 = (int) -2147483647
**							    (32 bits)
*/

