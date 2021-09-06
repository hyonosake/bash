/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 01:49:13 by alex              #+#    #+#             */
/*   Updated: 2020/11/05 00:47:11 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr_to_last;

	ptr_to_last = *lst;
	if (ptr_to_last == NULL)
	{
		*lst = new;
		return ;
	}
	ptr_to_last = ft_lstlast(*lst);
	ptr_to_last->next = new;
}
