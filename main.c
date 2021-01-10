/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:02:32 by mykman            #+#    #+#             */
/*   Updated: 2021/01/10 19:31:48 by mykman           ###   ########.fr       */
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
	printf("%04.d\n", 255651651);
	return 0;
}