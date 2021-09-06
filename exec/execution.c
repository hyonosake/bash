/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:54:18 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 22:53:36 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	executor(t_data *data)
{
	t_cmd	*tmp;

	init_fd_changes(data);
	tmp = data->cmds;
	if (data->cmds && !data->cmds->next)
	{
		sig_restore();
		one_cmd_token(data);
		return ;
	}
	while (tmp && !data->go_next)
	{
		sig_restore();
		exec_cmds(data, tmp);
		tmp = tmp->next;
	}
	restore_fd(data);
	tmp = data->cmds;
	while (tmp)
	{
		wait_process(tmp);
		tmp = tmp->next;
	}
	sig_restore();
}

void	exec_cmds(t_data *data, t_cmd *curr_cmd)
{
	curr_cmd->pid = fork();
	if (curr_cmd->pid < 0)
		perror("pid < 0");
	else if (!curr_cmd->pid)
	{
		if (curr_cmd->prev)
		{
			close(0);
			dup2(curr_cmd->in_fd, 0);
		}
		if (curr_cmd->next)
		{
			close(1);
			dup2(curr_cmd->out_fd, 1);
		}
		close_all_fd(data);
		execute_one_cmd(data, curr_cmd);
	}
}

uint8_t	exec_builtins(t_data *data, t_cmd *cmd)
{
	if (!ft_strncmp(cmd->path, "cd", ft_strlen(cmd->path)))
		return (our_cd(data->env, data->cmds));
	else if (!ft_strncmp(cmd->path, "echo", ft_strlen(cmd->path)))
		return (our_echo(data->cmds));
	else if (!ft_strncmp(cmd->path, "env", ft_strlen(cmd->path)))
		return (our_env(data->env));
	else if (!ft_strncmp(cmd->path, "pwd", ft_strlen(cmd->path)))
		return (our_pwd(data->env));
	else if (!ft_strncmp(cmd->path, "export", ft_strlen(cmd->path)))
		return (our_export(data, cmd->args));
	else if (!ft_strncmp(cmd->path, "env", ft_strlen(cmd->path)))
		return (our_env(data->env));
	else if (!ft_strncmp(cmd->path, "exit", ft_strlen(cmd->path)))
		return (our_exit(cmd));
	else if (!ft_strncmp(cmd->path, "unset", ft_strlen(cmd->path)))
	{
		data->env = our_unset(data->env, cmd->args[1]);
		return (0);
	}
	return (NEVER_WILL);
}

void	execute_one_cmd(t_data *data, t_cmd *curr)
{
	dup_fd_redirects(data, curr);
	if (data->go_next)
		exit(127);
	if (is_builtin(curr))
	{
		prev_exec = exec_builtins(data, curr);
		exit(prev_exec);
	}
	else
	{
		check_if_minishel(curr);
		if (execve(curr->path, curr->args, data->env) == -1)
		{
			error_msg(curr->path, NULL, "No such file or directory");
			exit(127);
		}
	}
}

int	wait_process(t_cmd *cmd)
{
	int		res;
	int		status;

	res = 0;
	signal(SIGINT, main_handler);
	if (waitpid(cmd->pid, &status, WUNTRACED) != 0)
	{
		if (waitpid(cmd->pid, &status, WNOHANG) == 0)
			return (0);
		if (WIFEXITED(status))
			prev_exec = WEXITSTATUS(status);
		else
		{
			if (WIFSIGNALED(status))
				res = WTERMSIG(status);
			if (WIFSTOPPED(status))
				res = WSTOPSIG(status);
		}
	}
	return (res);
}
