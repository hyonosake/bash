/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:39:41 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 15:47:19 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**init_env(char **envp)
{
	char	**res;
	int		i;

	i = 0;
	while (envp[i])
		++i;
	res = (char **)ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (envp[i])
	{
		res[i] = ft_strdup(envp[i]);
		++i;
	}
	return (res);
}

int32_t	check_key(char *env_key, char *given_key)
{
	int32_t	i;

	i = 0;
	while (env_key[i] != '=')
		++i;
	if (i != ft_strlen(given_key))
		return (0);
	return (1);
}

int8_t	change_env_var(char **env, char *key, char *value, int32_t len)
{
	char	*new_value;
	uint8_t	i;

	i = 0;
	while (env[i])
	{
		if (!strncmp(env[i], key, len))
		{
			if (check_key(env[i], key))
			{
				new_value = ft_strjoin(ft_strdup(key), ft_strdup("="));
				new_value = ft_strjoin(ft_strdup(new_value), ft_strdup(value));
				free(env[i]);
				env[i] = new_value;
				return (1);
			}
		}
		++i;
	}
	return (0);
}

char	*find_env_var(char **envp, char *key, int32_t len)
{
	int32_t	i;
	int32_t	sym;

	i = 0;
	while (envp[i])
	{
		if (!strncmp(envp[i], key, len))
		{
			if (check_key(envp[i], key))
			{
				sym = symbol_position(envp[i], '=');
				return (ft_substr(envp[i], sym + 1, ft_strlen(envp[i])));
			}
		}
		++i;
	}
	return (NULL);
}

char	*find_env_line(char **envp, char *key, int32_t len)
{
	int32_t	i;
	int32_t	sym;

	i = 0;
	while (envp[i])
	{
		if (!strncmp(envp[i], key, len))
		{
			if (check_key(envp[i], key))
			{
				sym = symbol_position(envp[i], '=');
				return (ft_strdup(envp[i]));
			}
		}
		++i;
	}
	return (NULL);
}
