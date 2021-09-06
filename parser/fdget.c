/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdget.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:39:43 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 15:17:14 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	open_file(t_data *data, t_cmd *cmd, char *filename, uint8_t type)
{
	int	tmp_fd;

	tmp_fd = 0;
	if (type == FILE_TRUNC)
		tmp_fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	else if (type == FILE_APP)
		tmp_fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	else if (type == FILE_INP)
		tmp_fd = open(filename, O_RDONLY | S_IRWXU);
	else
		heredoc_redirect(data, cmd, filename);
	return (tmp_fd);
}

void	open_pipes(t_cmd *curr)
{
	int32_t	fd[2];

	if (!curr->next)
	{
		curr->out_fd = 1;
		return ;
	}
	pipe(fd);
	if (!curr->prev)
		curr->in_fd = 0;
	curr->out_fd = fd[1];
	curr->next->in_fd = fd[0];
}

void	close_all_fd(t_data *data)
{
	t_cmd	*cmds;

	cmds = data->cmds;
	while (cmds)
	{
		if (cmds->prev)
			close(cmds->in_fd);
		if (cmds->next)
			close(cmds->out_fd);
		cmds = cmds->next;
	}
	close(data->std_fd[0]);
	close(data->std_fd[1]);
}

void	init_fd_changes(t_data *data)
{
	t_cmd	*tmp;

	tmp = data->cmds;
	while (tmp)
	{
		open_pipes(tmp);
		tmp = tmp->next;
	}
	tmp = data->cmds;
	data->std_fd[0] = dup(0);
	data->std_fd[1] = dup(1);
}
