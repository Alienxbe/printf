/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:26:55 by mykman            #+#    #+#             */
/*   Updated: 2021/01/14 15:06:11 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char			*str;
	unsigned int	un;
	int				size;

	size = (!n) ? 2 : ft_intsize(n, 0) + 1;
	if (!(str = (char *)ft_calloc(sizeof(char), size)))
		return (NULL);
	ft_memset(str, '0', size - 1);
	if (!n)
		return (str);
	un = (n < 0) ? -n : n;
	while (--size)
	{
		str[size - 1] = (!un && !(size - 1)) ? '-' : '0' + un % 10;
		un /= 10;
	}
	return (str);
}
