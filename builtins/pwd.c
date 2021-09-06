/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:44:23 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 19:15:20 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

uint8_t	our_pwd(char **env)
{
	char	*ret;

	ret = find_env_var(env, "PWD", 3);
	if (!ret)
		return (1);
	write(STDOUT_FILENO, ret, ft_strlen(ret));
	ft_putendl_fd(STDOUT_FILENO);
	return (0);
}
