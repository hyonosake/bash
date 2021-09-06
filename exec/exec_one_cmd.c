/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_one_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:39:42 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/04 00:07:59 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_if_one_cmd(t_data *data, t_cmd *curr_cmd)
{
	dup_fd_redirects(data, curr_cmd);
	if (data->go_next)
		return ;
	if (is_builtin(curr_cmd))
	{
		prev_exec = exec_builtins(data, curr_cmd);
		return ;
	}
	sig_parent();
	curr_cmd->pid = fork();
	if (curr_cmd->pid < 0)
		perror("pid < 0");
	else if (!curr_cmd->pid)
	{
		sig_child();
		if (check_if_minishel(curr_cmd))
			change_sh_lvl(data);
		if (execve(curr_cmd->path, curr_cmd->args, data->env) == -1)
		{
			error_msg(curr_cmd->path, NULL, "command not found");
			exit(127);
		}
	}
	if (check_if_minishel(curr_cmd))
	{
		signal(SIGINT, SIG_IGN);
		ft_putstr_fd("new shell session\n", 2);
	}
	wait_process(curr_cmd);
}
void	one_cmd_token(t_data *data)
{
	exec_if_one_cmd(data, data->cmds);
	close(0);
	close(1);
	dup2(data->std_fd[0], 0);
	dup2(data->std_fd[1], 1);
	close(data->std_fd[0]);
	close(data->std_fd[1]);
}