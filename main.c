/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:54:10 by mykman            #+#    #+#             */
/*   Updated: 2021/01/19 00:43:33 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	//ft_printf("%00000000-------999999999d Bonjour %000000000.i quelle age as tu %-*.*d as %.20s ?\n", "Salut ça farte ?");
	//printf("%999999999d\n", ft_pow(2, 2));
	//printf("|%5c|\n", 'A');
	//printf("printf : %d\n", printf("La bite est : %c\n", 'm'));
	//printf("ft_printf : %d\n", ft_printf("La bite est : %c\n", 'm'));
	ft_printf("Bonjour %-10.0*c|\n", 5, '1');
	return (0);
}
