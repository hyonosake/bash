/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:30:33 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 21:04:13 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*u_s1;
	unsigned char	*u_s2;
	size_t			i;

	u_s1 = (unsigned char*)s1;
	u_s2 = (unsigned char*)s2;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (1);
	i = 0;
	if (n == 0)
		return (0);
	while (*u_s1 && *u_s1 == *u_s2 && i < n - 1)
	{
		++u_s1;
		++u_s2;
		++i;
	}
	return (*u_s1 - *u_s2);
}
