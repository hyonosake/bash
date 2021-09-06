/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_var_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 21:20:15 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 20:41:09 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	change_local_value(t_vec_vars *vvars, char *key, char *value)
{
	int	i;

	i = 0;
	while (i < vvars->length)
	{
		if (!strcmp(vvars->vars[i].key, key))
		{
			free(vvars->vars[i].value);
			vvars->vars[i].value = value;
			return (1);
		}
		++i;
	}
	return (0);
}

void	add_local_var(t_data *data, char *key, char *value)
{
	char	*existing_key;

	existing_key = find_local_var(data, key);
	if (existing_key)
	{
		change_local_value(data->vec_vars, existing_key, value);
		free(existing_key);
		return ;
	}
	if (data->vec_vars->capacity == data->vec_vars->length)
		local_var_realloc(data->vec_vars);
	data->vec_vars->vars[data->vec_vars->length].value = value;
	data->vec_vars->vars[data->vec_vars->length].key = key;
	++data->vec_vars->length;
}

char	*find_local_var(t_data *data, char *key)
{
	int32_t	i;

	i = 0;
	if (!ft_strncmp(key, "?", 1))
	{
		//printf("prev_exec = %d\n", prev_exec);
		return (ft_itoa(prev_exec));
	}
	else if (!ft_strncmp(key, "0", 1))
		return (ft_strdup("minishell by ehillman and ffarah"));
	while (i < data->vec_vars->length)
	{
		if (!ft_strncmp(data->vec_vars->vars[i].key, key, ft_strlen(key)))
			return (ft_strdup(data->vec_vars->vars[i].value));
		++i;
	}
	return (NULL);
}
