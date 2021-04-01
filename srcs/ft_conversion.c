/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:55:45 by mykman            #+#    #+#             */
/*   Updated: 2021/04/01 20:28:44 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_flags(const char **format)
{
	int	flags;

	flags = 0;
	while (ft_strchr(FLAGS, **format))
	{
		if (**format == '0' && !flags)
			flags = FLAG_ZERO;
		if (*(*format)++ == '-')
			flags = FLAG_MINUS;
	}
	return (flags);
}

static int	ft_get_width(const char **format, va_list args)
{
	int	width;

	width = 0;
	if (ft_isdigit(**format))
	{
		width = ft_atoi(*format);
		*format += ft_intsize(width, 0);
	}
	else if (**format == '*')
	{
		width = (int)va_arg(args, int);
		(*format)++;
	}
	return (width);
}

static int	ft_get_prec(const char **format, va_list args)
{

}

static t_type	ft_get_type(const char **format)
{

}

t_tag	*ft_conversion(const char **format, va_list args)
{
	t_tag	*tag;

	tag = (t_tag*)malloc(sizeof(t_tag));
	if (!tag)
		return (NULL);
	tag->type = NONE;
	if (!++*format)
		return (tag);
	tag->flags = ft_get_flags(format);
	tag->width = ft_get_width(format, args);
	tag->prec = ft_get_prec(format, args);
	tag->type = ft_get_type(format);
	return (tag);
}
