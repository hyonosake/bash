/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 23:37:28 by ffarah            #+#    #+#             */
/*   Updated: 2020/11/07 16:37:02 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*u_src;
	unsigned char	*u_dst;

	if (!dst && !src)
		return (NULL);
	u_src = (unsigned char*)src;
	u_dst = (unsigned char*)dst;
	while (n--)
		*(u_dst++) = *(u_src++);
	return (dst);
}
