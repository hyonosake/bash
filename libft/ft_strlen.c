/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:30:31 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 14:20:17 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

int32_t	len_of_2d_array(char **arr)
{
	int32_t	i;

	i = 0;
	if (!arr || !arr[0])
		return (i);
	while (arr[i])
		++i;
	return (i);
}
