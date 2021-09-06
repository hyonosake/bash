/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexems_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:39:34 by ffarah            #+#    #+#             */
/*   Updated: 2021/08/31 16:39:35 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

t_lexem	*new_lexem(char *data, uint8_t type)
{
	t_lexem	*new;

	new = (t_lexem *)malloc(sizeof(t_lexem));
	if (!new)
		return (NULL);
	new->type = type;
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_lexem	*push_back_lexem(t_lexem **head, char *data, uint8_t type)
{
	static t_lexem	*last_lexem;

	if (!*head)
	{
		*head = new_lexem(data, type);
		last_lexem = *head;
		if (!last_lexem)
			return (NULL);
	}
	else
	{
		last_lexem->next = new_lexem(data, type);
		if (!last_lexem->next)
			return (NULL);
		last_lexem->next->prev = last_lexem;
		last_lexem = last_lexem->next;
	}
	return (last_lexem);
}

t_lexem	*rm_lexem(t_lexem **head, t_lexem **delete_me)
{
	t_lexem	*tmp;
	t_lexem	*to_return;

	tmp = *delete_me;
	to_return = NULL;
	if (!*head || !*delete_me)
		return (NULL);
	if (tmp == *head)
	{
		*head = (*head)->next;
		to_return = *head;
	}
	else if (tmp->next)
	{
		to_return = tmp->next;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
	}
	else if (tmp->prev)
		tmp->prev->next = NULL;
	free_one_lexem(tmp);
	return (to_return);
}

uint8_t	make_lexems_pretty(t_data *data)
{
	t_lexem	*tmp;
	t_lexem	*next;

	tmp = data->lexems;
	next = tmp->next;
	while (tmp)
	{
		next = tmp->next;
		if (tmp->type == OPERATION)
		{
			tmp = tmp->next;
			continue ;
		}
		if ((next && next->data && tmp->data && next->type != OPERATION))
		{
			tmp = stick_same_lexems(&data->lexems, tmp, next);
			if (!tmp)
				break ;
		}
		else if (!tmp->data)
			tmp = rm_lexem(&data->lexems, &tmp);
		else
			tmp = tmp->next;
	}
	return (1);
}

t_lexem	*stick_same_lexems(t_lexem **head, t_lexem *curr, t_lexem *next)
{
	char	*new_data;

	if (!curr || !next)
		return (NULL);
	if (!curr->data || !next->data)
		return (next);
	new_data = ft_strjoin(curr->data, next->data);
	curr->data = NULL;
	free(next->data);
	next->data = new_data;
	curr = rm_lexem(head, &curr);
	return (stick_same_lexems(head, curr, curr->next));
}
