/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:10:09 by ffarah            #+#    #+#             */
/*   Updated: 2020/10/30 23:36:14 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_bzero(void *b, size_t n)
{
	unsigned char	*to_cast;

	to_cast = (unsigned char *)b;
	while (n)
	{
		*(to_cast++) = '\0';
		--n;
	}
	return (b);
}
