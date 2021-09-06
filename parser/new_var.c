/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 21:29:42 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 20:21:35 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	check_var_by_split(t_data *data, char *lexem)
{
	int32_t	sym;
	char	**key_value;

	sym = symbol_position(lexem, '=');
	if (sym == -1)
		return (0);
	key_value = ft_split(lexem, '=');
	if (!key_value[0] || !key_value[1] || !key_value[0][0] || !key_value[1][0]
		 || !is_env_name(key_value[0]))
		 return (0);
	add_or_change_var(data, key_value[0], key_value[1]);
	return (1);
}

static int	check_if_in_two_lexems(t_data *data, t_lexem *first, t_lexem *second)
{
	char	*key;
	char	*value;
	int32_t	sym;

	if (!first->data || !second->data || first->type == OPERATION
		|| second->type == OPERATION)
		return (0);
	sym = symbol_position(first->data, '=');
	if (sym == -1 || ft_strlen(first->data) - 1 != sym)
		return (0);
	key = ft_substr(first->data, 0, sym);
	value = ft_strdup(second->data);
	add_or_change_var(data, key, value);
	return (1);
}

int	check_if_new_var(t_data *data)
{
	t_lexem	*next;

	if (!data->lexems)
		return (0);
	next = data->lexems->next;
	if (!next)
		if (check_var_by_split(data, data->lexems->data))
			return (1);
	if (next && !next->next)
		if (check_if_in_two_lexems(data, data->lexems, next))
			return (1);
	return (0);
}
