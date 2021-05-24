/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 06:49:21 by mykman            #+#    #+#             */
/*   Updated: 2021/05/21 01:41:39 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ulsize_base(unsigned long n, char *base, int c)
{
	if (!n)
		return (c);
	return (ft_ulsize_base(n / ft_strlen(base), base, c + 1));
}

char	*ft_ultoa_base(unsigned long n, int minsize, char *base)
{
	char	*str;
	int		size;
	int		len_base;

	size = ft_ulsize_base(n, base, 0) + 1;
	len_base = ft_strlen(base);
	if (minsize + 1 > size)
		size = minsize + 1;
	if ((!n && !(size == minsize + 1)) || (size == minsize + 1 && n < 0))
		size++;
	str = (char *)ft_calloc(sizeof(char), size);
	if (!str)
		return (NULL);
	str = ft_memset(str, base[0], size - 1);
	while (--size)
	{
		str[size - 1] = base[n % len_base];
		n /= len_base;
	}
	return (str);
}
