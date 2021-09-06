/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:52:56 by alex              #+#    #+#             */
/*   Updated: 2020/11/05 00:38:11 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*created;

	created = (t_list *)malloc(sizeof(t_list));
	if (!created)
		return (NULL);
	created->content = content;
	created->next = NULL;
	return (created);
}
