/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:29:44 by ffarah            #+#    #+#             */
/*   Updated: 2020/10/30 22:07:49 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*char_b;

	char_b = (unsigned char*)b;
	while (n)
	{
		*(char_b++) = c;
		--n;
	}
	return (b);
}
