/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:57:54 by jihyeole          #+#    #+#             */
/*   Updated: 2022/12/08 18:41:57 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*newlst;
	void	*temp;

	if (lst == NULL)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		temp = f(lst->content);
		node = ft_lstnew(temp);
		if (node == NULL)
		{
			del(temp);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, node);
		lst = lst->next;
	}
	return (newlst);
}
