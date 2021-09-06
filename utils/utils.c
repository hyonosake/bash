/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:40:14 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 22:33:36 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

uint8_t	allowed_lexem_char(char sym)
{
	return (ft_isalnum(sym) || sym == '='
			|| sym == '-' || sym == '_'
			|| sym == '.' || sym == '/');
}

void	unexpected_token(t_data *data, const char *err_msg, const int sym)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(err_msg, 2);
	ft_putchar_fd('\'', 2);
	ft_putchar_fd(sym, 2);
	ft_putchar_fd('\'', 2);
	ft_putendl_fd(2);
	data->go_next = 1;
	prev_exec = 2;
}

void	error_msg(const char *prog_name, const char *arg, const char *error)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(prog_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error, 2);
	ft_putendl_fd(2);
}

uint8_t	is_env_name(char *name)
{
	uint32_t	i;

	i = 0;
	if (!name || ft_isdigit(name[0]))
		return (0);
	while (name[i])
	{
		if (!ft_isalnum(name[i]))
			break ;
		++i;
	}
	if (i == 0 || name[i])
		return (0);
	return (1);
}
