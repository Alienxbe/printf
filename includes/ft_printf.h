/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:22:25 by mykman            #+#    #+#             */
/*   Updated: 2021/05/03 18:06:40 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../libft/includes/libft.h" 


# define MALLOC_ERROR	-1
# define PREC_ERROR		-2

# define FLAG_ZERO		1
# define FLAG_MINUS		2
# define FLAGS			"0-"
# define TYPES			"cspdiuxX%"


typedef enum e_type
{
	NONE = -1,
	CHAR,
	STR,
	PTR,
	D_INT,
	I_INT,
	U_INT,
	LC_HEXA,
	UC_HEXA,
	PCT,
	LENGTH
}				t_type;

typedef struct s_tag
{
	int		flags;
	int		width;
	int		prec;
	t_type	type;
}				t_tag;

typedef int		(t_print)(t_tag *, va_list);

int	ft_printf(const char *format, ...);
t_tag	*ft_conversion(const char **format, va_list args);

int	ft_print_c(t_tag *tag, va_list args);

#endif