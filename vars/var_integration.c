/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_integration.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 21:26:58 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/01 17:30:22 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	add_or_change_var(t_data *data, char *key, char *new_value)
{
	char	*value;

	value = find_env_var(data->env, key, ft_strlen(key));
	if (value)
		change_env_var(data->env, key, new_value, ft_strlen(key));
	else
	{
		value = find_local_var(data, key);
		if (value)
			change_local_value(data->vec_vars, key, new_value);
		add_local_var(data, key, new_value);
	}
}

char	*find_var_value(t_data *data, char *key)
{
	char	*value;

	value = find_env_var(data->env, key, ft_strlen(key));
	if (value)
		return (value);
	value = find_local_var(data, key);
	if (value)
		return (value);
	return (NULL);
}
