/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:13:54 by alex              #+#    #+#             */
/*   Updated: 2020/11/09 12:52:14 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr_for_next;

	if (!del)
		return ;
	ptr_for_next = *lst;
	while (*lst)
	{
		ptr_for_next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = ptr_for_next;
	}
	*lst = NULL;
}
