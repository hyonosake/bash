/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 01:41:09 by alex              #+#    #+#             */
/*   Updated: 2020/11/09 13:01:48 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstlast(t_list *lst)
{
	t_list	*ptr_to_iterate;

	if (lst == NULL)
		return (lst);
	ptr_to_iterate = lst;
	while (ptr_to_iterate->next != NULL)
		ptr_to_iterate = ptr_to_iterate->next;
	return (ptr_to_iterate);
}
