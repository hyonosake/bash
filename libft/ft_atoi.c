/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:21:45 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 20:04:46 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int64_t		ft_atoi(char const *str)
{
	int			i;
	uint64_t	result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (result * 10 < result)
		{
			if (sign < 0)
				return (-1);
			return (0);
		}
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
