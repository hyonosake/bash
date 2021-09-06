/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:30:29 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 14:51:37 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, const char *s2)
{
	char			*new;
	int				j;
	int				i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	new = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		++i;
	}
	if (s1)
		free(s1);
	j = 0;
	while (s2 && s2[j])
	{
		new[i + j] = s2[j];
		++j;
	}
	new[i + j] = 0;
	return (new);
}
