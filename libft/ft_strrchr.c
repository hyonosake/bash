/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:30:38 by ffarah            #+#    #+#             */
/*   Updated: 2020/11/01 20:39:14 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *str, int c)
{
	char	*ptr;

	ptr = (char*)str + ft_strlen(str);
	while (ptr != str - 1)
	{
		if (*ptr == c)
			return (ptr);
		--ptr;
	}
	return (NULL);
}
