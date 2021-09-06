/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:08:47 by alex              #+#    #+#             */
/*   Updated: 2020/11/09 12:40:47 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*u_src;
	unsigned char	*u_dst;

	u_src = (unsigned char*)src;
	u_dst = (unsigned char*)dst;
	if (src > dst)
		while (n--)
			*(u_dst++) = *(u_src++);
	else if (src < dst)
	{
		u_dst += n - 1;
		u_src += n - 1;
		while (n--)
			*(u_dst--) = *(u_src--);
	}
	return (dst);
}
