/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:39:21 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 14:51:33 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	void	*void_ptr;

	void_ptr = (void *)malloc(size * count);
	if (void_ptr == NULL)
		return (NULL);
	ft_bzero(void_ptr, count * size);
	return (void_ptr);
}
