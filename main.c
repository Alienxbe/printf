/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:34:49 by mykman            #+#    #+#             */
/*   Updated: 2021/03/04 21:45:19 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

va_list g_args;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthexa(long int n)
{
	char *base;

	base = "0123456789abcdef";
	ft_putchar(base[n / 16]);
	ft_putchar(base[n % 16]);
}

void	ft_putcontent(char *str, int n)
{
	int i;

	i = -1;
	while (++i < n)
	{
		if (str[i] < 32 || str[i] == 127)
			ft_putchar('.');
		else
			ft_putchar(str[i]);
	}
}

void	ft_putcontent_hexa(char *str, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_puthexa((unsigned char)str[i]);
		if (i++ % 2)
			ft_putchar(' ');
	}
	if (n != 16)
	{
		while (n < 16)
		{
			write(1, "  ", 2);
			if (n++ % 2)
				ft_putchar(' ');
		}
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int i;
	int j;

	i = 0;
	while ((unsigned int)i < size)
	{
		j = 8;
		while (--j > -1)
		{
			ft_puthexa((long int)(addr + i) >> (j * 8) & 0xff);
		}
		write(1, ": ", 2);
		ft_putcontent_hexa(addr + i, (size - i < 16) ? size - i : 16);
		ft_putcontent(addr + i, (size - i < 16) ? size - i : 16);
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}

long long get_arg(int type)
{
	if (type == 1)
		return ((long long)va_arg(g_args, unsigned int));
	if (type == 2)
		return ((long long)va_arg(g_args, unsigned long long));
	if (type == 3)
		return ((long long)va_arg(g_args, int));
	return (0);
}


void func(int n, ...)
{
	ft_print_memory(&n, 100);
	ft_print_memory(*(&n + ((sizeof(n) + sizeof(int) - 1) / sizeof(int)) * sizeof(int)), 100);
	
	printf("%lu-*-*\n", sizeof(g_args));
	printf("%d\n", (char)get_arg(2));
	printf("%d-*-*\n", *g_args);
	va_end(g_args);
}



int	main(void)
{
	// ft_printf("Bonjour '%.d'", 150);
	// printf("%lu %lu\n", sizeof(int), sizeof(long long));
	// unsigned int n = 2147483650;
	// printf("%d\n", (int)n);
	func(55, 152, 55, 66844, 65465165132132, 2);
	printf("%lu %lu %lu\n", sizeof(int), sizeof(long long), sizeof(char));
	printf("%hhd\n", 152);
	return (0);
}

/*
**								(4 octets)
** (unsigned int) 2147483647 = 0111...1111 = (int)  2147483647
** (unsigned int) 2147483648 = 1000...0000 = (int) -2147483648
** (unsigned int) 2147483649 = 1000...0001 = (int) -2147483647
**							    (32 bits)
*/

