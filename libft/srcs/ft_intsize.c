/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:04:15 by mykman            #+#    #+#             */
/*   Updated: 2021/01/14 15:05:20 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intsize(int n, int c)
{
	if (!n)
		return (c);
	return ((n < 0) ? ft_intsize(n / -10, c + 2) : ft_intsize(n / 10, c + 1));
}