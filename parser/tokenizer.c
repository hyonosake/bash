/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:39:48 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 22:29:44 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


static	void	check_lexems(t_data *data, t_lexem *lexems)
{
	while(lexems)
	{
		if (lexems->type == OPERATION)
		{
			if (lexems->data[0] == '|')
			{
				if (!lexems->prev || !lexems->next
					|| !lexems->next->data[0] || !lexems->prev->data[0])
					{
						unexpected_token(data, SYNTAX_ERR, '|');
						return ;
					}
			}
		}
		lexems = lexems->next;		
	}
}

int	create_tokens(t_data *data)
{
	t_cmd	*tmp;

	if (!data->lexems || !data->lexems->data)
		return (0);
	make_lexems_pretty(data);
	check_lexems(data, data->lexems);
	if (data->go_next)
		return (0);
	if (check_if_new_var(data))
		return (1);
	push_cmd_back(data);
	tokenizer(data);
	tmp = data->cmds;
	add_full_path(data, data->cmds);
	return (1);
}

int	tokenizer(t_data *data)
{
	t_lexem	*curr;

	curr = data->lexems;
	while (!data->go_next && curr)
	{
		if (!strcmp(curr->data, ">") && curr->type == OPERATION)
			curr = add_redirects_info(data, curr, FILE_TRUNC);
		else if (!strcmp(curr->data, ">>") && curr->type == OPERATION)
			curr = add_redirects_info(data, curr, FILE_APP);
		else if (!strcmp(curr->data, "<") && curr->type == OPERATION)
			curr = add_redirects_info(data, curr, FILE_INP);
		else if (!strcmp(curr->data, "<<") && curr->type == OPERATION)
			curr = add_redirects_info(data, curr, HEREDOC);
		else if (!strcmp(curr->data, "|") && curr->type == OPERATION)
			check_if_pipe_valid(data);
		else
			parse_word_token(data, curr);
		curr = curr->next;
	}
	return (1);
}
