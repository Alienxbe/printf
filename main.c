/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:02:32 by mykman            #+#    #+#             */
/*   Updated: 2021/01/11 03:08:11 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int	ft_printf(int n, ...)
{
	va_list args;
	int		i;
	int		sum;

	i = -1;
	sum = 0;
	va_start(args, n);
	while (++i < n)
		printf("%d\n", va_arg(args, int));
	va_end(args);
	return (sum);
}

int main(void)
{
	//printf("Boonjour %s %*d ca va ?\n", "Theo", 15, 156);
	printf("%s %0*d\n", "Bonjour les amis %s tout va bien ?", 20, 42);
	return 0;
}