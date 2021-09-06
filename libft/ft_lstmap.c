/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:44:29 by alex              #+#    #+#             */
/*   Updated: 2020/11/05 00:38:04 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list_head;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_node = ft_lstnew(f(lst->content));
	if (!new_node)
		return (NULL);
	list_head = new_node;
	lst = lst->next;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&list_head, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&list_head, new_node);
	}
	return (list_head);
}
