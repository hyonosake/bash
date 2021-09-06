/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:39:50 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 22:19:55 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_if_pipe_valid(t_data *data)
{
	t_cmd	*curr;

	curr = data->curr_cmd;
	if (!curr->path)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("syntax error near unexpected token '|'\n", 2);
		data->go_next = 1;
	}
	else
		push_cmd_back(data);
	data->state = NEXT_PROG;
}

void	parse_word_token(t_data *data, t_lexem *curr_word)
{
	if (data->state == NEXT_PROG)
	{
		data->curr_cmd->path = ft_strdup(curr_word->data);
		data->state = NEXT_ARGS;
	}
	else if (data->state == NEXT_ARGS)
		data->curr_cmd->args = add_last_to_2d_array(data->curr_cmd->args,
				curr_word->data);
}

int	check_access(char **splitted_path, char **prog)
{
	char			*tmp;
	int32_t			i;
	char			*restore;

	i = 0;
	restore = ft_strdup(*prog);
	while (splitted_path[i])
	{
		tmp = ft_strjoin(ft_strdup(splitted_path[i]), "/");
		tmp = ft_strjoin(tmp, *prog);
		if (!access(tmp, X_OK))
		{
			free(*prog);
			*prog = tmp;
			free_2d_array(splitted_path);
			return (0);
		}
		free(tmp);
		++i;
	}
	//free(*prog);
	//*prog = restore;
	free_2d_array(splitted_path);
	return (1);
}
