/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:11:31 by alex              #+#    #+#             */
/*   Updated: 2020/11/04 01:18:25 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*ptr;

	if (lst == NULL)
		return (0);
	count = 1;
	ptr = lst;
	while (ptr->next != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}
