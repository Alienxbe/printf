/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:54:10 by mykman            #+#    #+#             */
/*   Updated: 2021/01/16 15:58:36 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int add(int a, int b)
{
	return (a + b);
}

int sub(int a, int b)
{
	return (a - b);
}

int main()
{
	int (*f[2])(int, int);

	f = {add, sub};
	printf("%d\n", f[0](10, 5));
	//ft_printf("%00000000-------999999999d Bonjour %000000000.i quelle age as tu %-*.*d as %.20s ?\n", "Salut ça farte ?");
	//printf("%999999999d\n", ft_pow(2, 2));
	//printf("%.2147483647d\n", 50);
	//ft_printf("%.2147483647x\n", "Labase");
	return (0);
}
