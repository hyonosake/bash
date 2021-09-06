/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:30:42 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 14:51:39 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, uint32_t start, uint32_t len)
{
	char		*substr;
	uint32_t	j;
	int32_t		i;

	if (!s)
		return (NULL);
	j = start;
	i = 0;
	substr = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!substr)
		return (NULL);
	while (len > 0 && s[j])
	{
		substr[i] = s[j];
		j++;
		i++;
		len--;
	}
	substr[i] = '\0';
	return (substr);
}
