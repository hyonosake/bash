/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:29:49 by ffarah            #+#    #+#             */
/*   Updated: 2020/11/01 16:26:17 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *str, int c)
{
	char	*find;

	find = (char*)str;
	if (c == 0)
		return (find + ft_strlen(str));
	while (*(find))
	{
		if (*find == c)
			return (find);
		find++;
	}
	return (NULL);
}
