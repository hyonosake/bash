/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:29:51 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 20:37:27 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char		*new;
	uint32_t	i;

	i = 0;
	new = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!new)
		return (NULL);
	if (!src[0])
	{
		new[0] = 0;
		return (new);
	}
	while (src && src[i])
	{
		new[i] = src[i];
		++i;
	}
	new[i] = 0;
	return (new);
}
