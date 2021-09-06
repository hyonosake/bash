/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:48:34 by alex              #+#    #+#             */
/*   Updated: 2020/11/05 00:40:29 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	to_conc;
	size_t	i;

	to_conc = 0;
	i = 0;
	while (dst[to_conc] && to_conc < dstsize)
		to_conc++;
	while ((to_conc + i + 1 < dstsize) && (src[i]))
	{
		dst[to_conc + i] = src[i];
		i++;
	}
	if (to_conc != dstsize)
		dst[to_conc + i] = '\0';
	return (ft_strlen(src) + to_conc);
}
