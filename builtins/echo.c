/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:44:17 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 19:03:31 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

uint8_t	our_echo(t_cmd *echo)
{
	int32_t		len;
	uint32_t	i;
	uint8_t		flag;

	i = 1;
	flag = 0;
	if (!echo->args[1])
	{
		write(echo->out_fd, "\n", 1);
		return (0);
	}
	if (echo->args[1] && !strcmp(echo->args[1], "-n") && ++i)
		flag = 1;
	while (echo->args[i])
	{
		len = ft_strlen(echo->args[i]);
		write(echo->out_fd, echo->args[i], len);
		write(echo->out_fd, " ", 1);
		++i;
	}
	!flag && write(echo->out_fd, "\n", 1);
	return (0);
}
