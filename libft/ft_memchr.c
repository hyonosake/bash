/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:21:36 by alex              #+#    #+#             */
/*   Updated: 2020/11/09 13:15:25 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*u_s;

	u_s = (unsigned char*)s;
	while (n--)
	{
		if (*u_s == (unsigned char)c)
			return ((void *)u_s);
		u_s++;
	}
	return (NULL);
}
