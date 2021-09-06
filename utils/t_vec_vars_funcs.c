/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vec_vars_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 23:05:25 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 15:14:08 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_local_var(t_vec_vars *v_vars)
{
	int	i;

	i = v_vars->length;
	while (i > 0)
	{
		if (v_vars->vars[i].key)
			free(v_vars->vars[i].key);
		if (v_vars->vars[i].value)
			free(v_vars->vars[i].value);
		--i;
	}
	free(v_vars);
}

t_vec_vars	*local_var_create(void)
{
	t_vars		*vars;
	t_vec_vars	*vec_vars;

	vars = (t_vars *)ft_calloc(sizeof(t_vars), 10);
	vec_vars = (t_vec_vars *)ft_calloc(sizeof(t_vec_vars), 1);
	if (!vars)
		return (NULL);
	if (!vec_vars)
		return (NULL);
	vec_vars->vars = vars;
	vec_vars->length = 0;
	vec_vars->capacity = 10;
	return (vec_vars);
}

void	local_var_realloc(t_vec_vars *vec_vars)
{
	t_vars	*new_vars;
	int32_t	new_capacity;

	new_capacity = vec_vars->capacity * 2;
	new_vars = (t_vars *)ft_calloc(sizeof(t_vars), new_capacity);
	ft_memcpy((void *)new_vars, (void *)vec_vars->vars, sizeof(t_vars)
		* vec_vars->length);
	free(vec_vars->vars);
	vec_vars->capacity = new_capacity;
	vec_vars->vars = new_vars;
}

int	valid_name_for_var(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[0]))
		return (0);
	while (str[i] && allowed_lexem_char(str[i]))
	{
		if (str[i] == '=' && i)
			return (1);
		++i;
	}
	if (str[i] != '=' || !i)
		return (0);
	return (1);
}
