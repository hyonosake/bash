/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:53:10 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 22:17:52 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_cmd	*new_cmd(void)
{
	t_cmd		*new;
	static int	i;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->path = NULL;
	new->reds[0].type = EMPTY;
	new->reds[0].name = NULL;
	new->reds[1].type = EMPTY;
	new->reds[1].name = NULL;
	new->args = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->index = i;
	++i;
	return (new);
}

void	*free_cmd_list(t_cmd **head)
{
	t_cmd	*tmp;
	t_cmd	*to_free;

	tmp = *head;
	while (tmp)
	{
		to_free = tmp;
		tmp = tmp->next;
		if (to_free->path)
			free(to_free->path);
		if (to_free->reds[0].name)
			free(to_free->reds[0].name);
		if (to_free->reds[1].name)
			free(to_free->reds[1].name);
		free_2d_array(to_free->args);
		free(to_free);
	}
	return (NULL);
}

void	push_cmd_back(t_data *data)
{
	t_cmd	*new;

	new = new_cmd();
	if (!new)
		return ;
	if (!data->cmds)
	{
		data->cmds = new;
		data->curr_cmd = data->cmds;
	}
	else
	{
		data->curr_cmd->next = new;
		new->prev = data->curr_cmd;
		data->curr_cmd = new;
	}
}

int	add_full_path(t_data *data, t_cmd *cmds)
{
	char	*tmp;
	t_cmd	*curr;

	curr = cmds;
	while (curr)
	{
		if (!curr->path)
			exit(0);
		if (symbol_position(curr->path, '\\') == -1 && !is_builtin(curr))
		{
			if (find_prog(data->env, &curr->path))
			{
				tmp = ft_strdup(curr->path);
				free(curr->path);
				curr->path = ft_strjoin(ft_strdup(getenv("PWD")), "/");
				curr->path = ft_strjoin(curr->path, tmp);
				free(tmp);
			}
		}
		curr->args = add_first_to_2d_array(curr->args, curr->path);
		curr = curr->next;
	}
	return (1);
}

int8_t	find_prog(char **envp, char **prog)
{
	int32_t	i;
	char	*path;
	char	**splitted_path;

	path = find_env_var(envp, "PATH", 4);
	splitted_path = ft_split(&path[5], ':');
	i = 0;
	if (!ft_strncmp(*prog, "./", 2) || !ft_strncmp(*prog, "../", 3)
		|| !ft_strncmp(*prog, "/", 1))
		return (0);
	return (check_access(splitted_path, prog));
}
