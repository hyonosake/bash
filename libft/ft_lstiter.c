/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 22:43:31 by alex              #+#    #+#             */
/*   Updated: 2020/11/05 00:37:37 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *ptr_to_count;

	ptr_to_count = lst;
	if (!lst || !f)
		return ;
	while (ptr_to_count)
	{
		f(ptr_to_count->content);
		ptr_to_count = ptr_to_count->next;
	}
}
