/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:44:11 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 18:58:57 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*cut_pwd(char *pwd)
{
	int32_t	i;
	char	*res;

	i = ft_strlen(pwd) - 1;
	while (pwd[i] && pwd[i] != '/')
		--i;
	if (pwd[i])
	{
		if (pwd[i] == '/' && i == 0)
			res = strdup("/");
		else
			res = ft_substr(pwd, 0, i);
		return (res);
	}
	return (NULL);
}

static char	*make_valid_string(char **stack, char *pwd)
{
	char	*tmp;
	int32_t	i;

	i = 0;
	while (stack[i])
	{
		if (!strncmp(stack[i], "..", ft_strlen(stack[i])))
		{
			tmp = cut_pwd(pwd);
			if (tmp)
			{
				free(pwd);
				pwd = tmp;
			}
		}
		else if (!strncmp(stack[i], ".", ft_strlen(stack[i])))
		{
			++i;
			continue ;
		}
		else
			pwd = ft_strjoin(ft_strjoin(pwd, strdup("/")), stack[i]);
		++i;
	}
	return (pwd);
}

static int32_t	chdir_fill_pwd(char **env, char *path, char *pwd)
{
	int32_t	ret;

	ret = chdir(path);
	if (ret != 0)
	{
		ft_putstr_fd(strerror(errno), 2);
		write(2, "\n", 1);
		return (1);
	}
	change_env_var(env, "OLDPWD", &pwd[4], 6);
	change_env_var(env, "PWD", path, 3);
	free(path);
	free(pwd);
	return (ret);
}

uint8_t	our_cd(char **env, t_cmd *cd_cmd)
{
	char	**stack;
	char	*pwd;
	char	*path;

	if (!cd_cmd->args[1])
	{
		path = find_env_var(env, "HOME", 4);
		if (!path)
		{
			ft_putstr_fd("bash: cd: HOME not set\n", 2);
			return (1);
		}
		pwd = find_env_line(env, "PWD", 3);
		return (chdir_fill_pwd(env, path, pwd));
	}
	stack = ft_split(cd_cmd->args[1], '/');
	pwd = find_env_line(env, "PWD", 3);
	path = make_valid_string(stack, strdup(&pwd[4]));
	return (chdir_fill_pwd(env, path, pwd));
}
