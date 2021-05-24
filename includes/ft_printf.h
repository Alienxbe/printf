/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:22:25 by mykman            #+#    #+#             */
/*   Updated: 2021/05/21 02:46:46 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../libft/includes/libft.h" 


# define MALLOC_ERROR		-1
# define TAG_BUILD_ERROR	-2

# define FLAG_ZERO			1
# define FLAG_MINUS			2
# define FLAG_PRECISION		4
# define FLAGS				"0-P"
# define TYPES				"cspdiuxX%"
# define NULL_STR			"(null)"
# define BASE_DECI			"0123456789"
# define BASE_HEXA_L		"0123456789abcdef"
# define BASE_HEXA_U		"0123456789ABCDEF"


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
t_tag	*ft_create_tag(const char **format, va_list args);

int	ft_print_type(t_tag *tag, char *s);
int	ft_type_c(t_tag *tag, va_list args);
int	ft_type_s(t_tag *tag, va_list args);
int	ft_type_p(t_tag *tag, va_list args);
int ft_type_d(t_tag *tag, va_list args);
int	ft_type_ubase(t_tag *tag, va_list args);
int	ft_type_pct(t_tag *tag, va_list args);

#endif