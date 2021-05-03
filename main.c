/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:34:49 by mykman            #+#    #+#             */
/*   Updated: 2021/05/03 18:56:27 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <unistd.h>
#include <stdio.h>

/*
** typedef
*/

/*typedef	enum	e_type
{
	ADD,
	SUB,
	MUL,
	DIV
}				t_type;

typedef	int	(t_operations)(int, int);

t_operations	**init_opertations_table(void);
int				add(int a, int b);
int 			sub(int a, int b);
int 			mul(int a, int b);
int 			divi(int a, int b);

int add(int a, int b)
{
	return (a + b);
}

int sub(int a, int b)
{
	return (a - b);
}

int mul(int a, int b)
{
	return (a * b);
}

int divi(int a, int b)
{
	return (a / b);
}

t_operations	**init_opertations_table(void)
{
	t_operations	**table;

	if (!(table = malloc(sizeof(t_operations *) * 4)))
		return (NULL);
	table[ADD] = &add;
	table[SUB] = &sub;
	table[MUL] = &mul;
	table[DIV] = &divi;
	return (table);
}
*/
int	main(void)
{
	/*t_operations **op_table;

	op_table = init_opertations_table();

	printf("%d\n", (*op_table[MUL])(10, 5));
	
	free(op_table);*/

	//printf("Bonjour les %010.d amis", 50);
	/*ft_printf("Hey salut %-0-.*s !\n", 0);
	printf("%0s\n", "Oui la base");*/
	ft_printf("Salut toi %0*c !\n", -5, 'c');
	printf("Salut toi %0*c !\n", -5, 'c');
	return (0);
}

/*
**								(4 octets)
** (unsigned int) 2147483647 = 0111...1111 = (int)  2147483647
** (unsigned int) 2147483648 = 1000...0000 = (int) -2147483648
** (unsigned int) 2147483649 = 1000...0001 = (int) -2147483647
**							    (32 bits)
*/

