/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:21:31 by mykman            #+#    #+#             */
/*   Updated: 2021/05/08 03:29:25 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_print	**init_type_table(void)
{
	t_print	**table;

	table = malloc(sizeof(t_print *) * LENGTH);
	if (!table)
		return (NULL);
	table[CHAR] = &ft_print_c;
	/*table[STR] = &ft_print_s;
	table[PTR] = &ft_print_p;
	table[D_INT] = &ft_print_int;
	table[I_INT] = &ft_print_int;*/
	return (table);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	t_tag	*tag;
	t_print	**type_table;

	va_start(args, format);
	type_table = init_type_table();
	if (!type_table)
		return (MALLOC_ERROR);
	while (*format)
	{
		if (*format == '%')
		{
			tag = ft_conversion(&format, args);
			if (!tag)
				return (MALLOC_ERROR);
			if ((*(type_table[tag->type]))(tag, args) < 0)
				return (MALLOC_ERROR); // Gerer erreur malloc ! (free)
			free(tag);
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	free(type_table);
	return (0);
}