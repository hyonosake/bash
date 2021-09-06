/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:40:01 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 22:16:24 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_lexem	*add_redirects_info(t_data *data, t_lexem *lredirect, uint8_t type)
{
	char	*path;

	if (!lredirect->next || !lredirect->next->data)
		unexpected_token(data, SYNTAX_ERR, lredirect->data[0]);
	else
	{
		path = lredirect->next->data;
		if (fill_redirect(data, data->curr_cmd, path, type) == -1)
			unexpected_token(data, PERM_DENIED, 0);
	}
	return (lredirect->next);
}

int	fill_redirect(t_data *data, t_cmd *cmd, char *filename, uint8_t type)
{
	int		tmp_fd;
	uint8_t	in_or_out;

	in_or_out = 1;
	if (type == 2)
		in_or_out = 0;
	if (type == 3)
	{
		ft_putstr_fd("Fill heredoc\n", 2);
		heredoc_redirect(data, cmd, filename);
		return (0);
	}
	if (cmd->reds[in_or_out].type != EMPTY)
	{
		tmp_fd = open_file(data, cmd, cmd->reds[in_or_out].name, type);
		free(cmd->reds[in_or_out].name);
		if (tmp_fd < 0)
			return (-1);
		close(tmp_fd);
	}
	cmd->reds[in_or_out].type = type;
	cmd->reds[in_or_out].name = ft_strdup(filename);
	return (0);
}

void	dup_fd_redirects(t_data *data, t_cmd *curr_cmd)
{
	int	tmp_fd;
	int	i;

	i = 0;
	while (i < 2)
	{
		if (curr_cmd->reds[i].type != EMPTY)
		{
			tmp_fd = open_file(data, curr_cmd, curr_cmd->reds[i].name,
					curr_cmd->reds[i].type);
			if (tmp_fd < i)
			{
				unexpected_token(data, PERM_DENIED, 0);
				return ;
			}
			else
			{
				close(i);
				dup2(tmp_fd, i);
			}
		}
		++i;
	}
}
