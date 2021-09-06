/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:38:26 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 20:57:49 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static uint8_t	ft_isallnum(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		++str;
	}
	return (1);
}

uint8_t	our_exit(t_cmd *cmd_exit)
{
	int		i;
	int64_t	arg_val;

	i = 0;
	if (!cmd_exit->args[1])
		exit_message(0);
	if (!ft_isallnum(cmd_exit->args[1]))
	{
		error_msg(cmd_exit->path, cmd_exit->args[1], "numeric argument required");
		exit(255);
	}
	arg_val = ft_atoi(cmd_exit->args[1]);
	if (cmd_exit->args[1] && cmd_exit->args[2])
	{
		error_msg(cmd_exit->path, cmd_exit->args[1], "too many arguments");
		return (1);
	}
	exit_message(arg_val);
	return (arg_val);
}