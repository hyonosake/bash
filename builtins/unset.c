/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:44:25 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 14:51:22 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**our_unset(char **env, char *key)
{
	char	**new;
	char	*find;
	int32_t	i;
	int32_t	j;

	find = find_env_var(env, key, ft_strlen(key));
	if (!find)
		return (env);
	i = 0;
	j = 0;
	new = (char **)ft_calloc(sizeof(char *), len_of_2d_array(env) + 1);
	while (env[i])
	{
		if (!strncmp(env[i], key, ft_strlen(key)) && check_key(env[i], key))
		{
			++i;
			continue ;
		}
		new[j] = ft_strdup(env[i]);
		++i;
		++j;
	}
	free_2d_array(env);
	return (new);
}
