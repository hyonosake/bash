/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 10:49:02 by alex              #+#    #+#             */
/*   Updated: 2020/11/09 11:49:17 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*u_dst;
	unsigned char	*u_src;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	u_src = (unsigned char*)src;
	u_dst = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		u_dst[i] = u_src[i];
		if (u_src[i] == (unsigned char)c)
			return ((void*)u_dst + ++i);
		i++;
	}
	return (NULL);
}
