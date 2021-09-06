/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:30:40 by ffarah            #+#    #+#             */
/*   Updated: 2020/11/09 13:08:09 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_char(const char ch, char const *set)
{
	int		i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == ch)
			return (0);
		++i;
	}
	return (1);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	j = ft_strlen(s1) - 1;
	while (ft_check_char(s1[i], set) == 0 && i <= j)
		++i;
	while (ft_check_char(s1[j], set) == 0 && j >= i)
		--j;
	++j;
	return (ft_substr(s1, i, j - i));
}
