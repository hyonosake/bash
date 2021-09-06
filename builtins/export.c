/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:44:21 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 21:01:40 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


static uint8_t	not_valid_identifier(char *str)
{
	error_msg("export", str, "not a valid identifier");
	prev_exec = 1;
	return (1);
}

static void	sort_2d_array(char **arr)
{
	int len;
	int i;
	int j;
	char	*temp;
	
	len  = len_of_2d_array(arr);
	i = 0;
	while (i < len)
	{
		j = 0;
		while(j < len - 1)
		{
			if (ft_strncmp(arr[j], arr[j + 1], strlen(arr[j])) > 0)
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
			++j;
		}
		++i;
	}
}

static void	print_with_declare(char **sorted_env)
{
	static const char	prefix[12] = "declare -x ";
	int32_t				i;
	int32_t				j;

	i = 0;
	while (sorted_env[i])
	{
		j = 0;
		ft_putstr_fd(prefix, 2);
		if (symbol_position(sorted_env[i], '=') == -1)
		{
			ft_putstr_fd(sorted_env[i], 2);
			write(1, "\n", 2);
			++i;
			continue ;
		}
		while (sorted_env[i][j] != '=')
			write(1, &sorted_env[i][j++], 2);
		write(1, "=\"", 2);
		while (sorted_env[i][++j])
			write(1, &sorted_env[i][j], 2);
		write(1, "\"\n", 2);
		++i;
	}
	
}

static uint8_t	export_no_args(char **env)
{

	char	**sorted_env;

	sorted_env = copy_2d_array(env);
	sort_2d_array(sorted_env);
	print_with_declare(sorted_env);
	free_2d_array(sorted_env);
	return (1);
}

uint8_t	our_export(t_data *data, char **args)
{
	char	**key_value;
	char	*env_str;

	if (!args[1])
		return (export_no_args(data->env));
	if (args[1][0] == '=')
		return (not_valid_identifier(args[1]));
	key_value = ft_split(args[1], '=');
	if (key_value[0] && !key_value[1])
	{
		data->env = add_last_to_2d_array(data->env, key_value[0]);
		return (0);
	}
	if (!change_env_var(data->env, key_value[0],
			key_value[1], ft_strlen(key_value[0])))
	{
		env_str = ft_strjoin(key_value[0], ft_strdup("="));
		env_str = ft_strjoin(env_str, key_value[1]);
		data->env = add_last_to_2d_array(data->env, env_str);
		free(env_str);
		free(key_value[1]);
		free(key_value);
	}
	return (0);
}
