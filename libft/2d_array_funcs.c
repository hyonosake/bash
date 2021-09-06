/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_array_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 22:59:18 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 21:00:19 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**realloc_2d_array(char **arr, int start_from)
{
	char	**new;
	int32_t	i;

	i = 0;
	new = (char **)ft_calloc(sizeof(char *), len_of_2d_array(arr) + 2);
	while (arr && arr[i])
	{
		new[i + start_from] = ft_strdup(arr[i]);
		++i;
	}
	new[i + start_from] = NULL;
	free_2d_array(arr);
	return (new);
}

char	**copy_2d_array(char **arr)
{
	char	**new;
	int32_t	i;

	i = 0;
	while (arr[i])
		++i;
	new = (char **)ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (arr[i])
	{
		new[i] = ft_strdup(arr[i]);
		++i;
	}
	return (new);
}

void	free_2d_array(char **arr)
{
	int32_t	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		++i;
	}
	if (arr)
		free(arr);
}

char	**add_last_to_2d_array(char **args, char *new_arg)
{
	char	**new_args;
	int32_t	len;

	len = len_of_2d_array(args);
	new_args = realloc_2d_array(args, 0);
	new_args[len] = ft_strdup(new_arg);
	return (new_args);
}

char	**add_first_to_2d_array(char **args, char *path_name)
{
	char	**new;

	new = realloc_2d_array(args, 1);
	new[0] = ft_strdup(path_name);
	return (new);
}