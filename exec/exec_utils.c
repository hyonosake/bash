/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:16:13 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 21:11:06 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

uint8_t	is_builtin(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->path, "cd", ft_strlen(cmd->path)))
		return (1);
	else if (!ft_strncmp(cmd->path, "echo", ft_strlen(cmd->path)))
		return (2);
	else if (!ft_strncmp(cmd->path, "env", ft_strlen(cmd->path)))
		return (3);
	else if (!ft_strncmp(cmd->path, "export", ft_strlen(cmd->path)))
		return (4);
	else if (!ft_strncmp(cmd->path, "pwd", ft_strlen(cmd->path)))
		return (5);
	else if (!ft_strncmp(cmd->path, "unset", ft_strlen(cmd->path)))
		return (6);
	else if (!ft_strncmp(cmd->path, "env", ft_strlen(cmd->path)))
		return (7);
	else if (!ft_strncmp(cmd->path, "exit", ft_strlen(cmd->path)))
		return (8);
	return (0);
}

void	change_sh_lvl(t_data *data)
{
	char	*curr_value;
	char	*iterate;

	curr_value = find_env_var(data->env, "SHLVL", 5);
	iterate = ft_itoa(ft_atoi(curr_value) + 1);
	free(curr_value);
	change_env_var(data->env, "SHLVL", iterate, 5);
	free(iterate);
}

uint8_t	check_if_minishel(t_cmd *cmd)
{
	char	*minishell_name;

	minishell_name = ft_strjoin(ft_strdup(getenv("PWD")), "/");
	minishell_name = ft_strjoin(minishell_name, "minishell");
	if (!ft_strncmp(cmd->path, minishell_name, ft_strlen(minishell_name))
		|| !ft_strncmp(cmd->path, "./minishell", ft_strlen(cmd->path)))
		return (1);
	free(minishell_name);
	return (0);
}

void	restore_fd(t_data *data)
{
	dup2(data->std_fd[0], 0);
	dup2(data->std_fd[1], 1);
	close_all_fd(data);
}

