/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:54:10 by mykman            #+#    #+#             */
/*   Updated: 2021/01/18 21:21:19 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	//ft_printf("%00000000-------999999999d Bonjour %000000000.i quelle age as tu %-*.*d as %.20s ?\n", "Salut ça farte ?");
	//printf("%999999999d\n", ft_pow(2, 2));
	//printf("|%5c|\n", 'A');
	printf("print%c\t\t: %50.d|\n", 'f', 50);
	ft_printf("ft_print%c\t: %20.5c|\n", 'f', 'a');
	return (0);
}
