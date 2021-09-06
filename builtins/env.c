/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:44:19 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 20:33:44 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

uint8_t	our_env(char **env)
{
	int32_t	i;

	i = 0;
	while (env[i])
	{
		if (symbol_position(env[i], '=') == -1)
		{
			++i;
			continue ;
		}
		write(STDOUT_FILENO, env[i], ft_strlen(env[i]));
		ft_putendl_fd(STDOUT_FILENO);
		++i;
	}
	return (0);
}
