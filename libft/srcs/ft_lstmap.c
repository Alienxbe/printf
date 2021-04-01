/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:50:35 by mykman            #+#    #+#             */
/*   Updated: 2021/03/22 19:56:39 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freeall(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*clst;
	t_list	*tmp;

	clst = ft_lstnew(NULL);
	if (!f || !clst)
		return (NULL);
	while (lst)
	{
		ft_lstlast(clst)->next = ft_lstnew(f(lst->content));
		if (!ft_lstlast(clst)->next)
		{
			if (!del)
				ft_freeall(&clst);
			else
				ft_lstclear(&clst, del);
			return (NULL);
		}
		lst = lst->next;
	}
	tmp = clst->next;
	free(clst);
	return (tmp);
}
