/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 23:18:00 by alex              #+#    #+#             */
/*   Updated: 2020/11/09 13:00:08 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0 || ft_strlen(haystack) < ft_strlen(needle))
		return (NULL);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i] && haystack[i] != needle[0] && i < len)
			i++;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char*)(haystack + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
