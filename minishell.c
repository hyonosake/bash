/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:38:31 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 22:11:29 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	exit_message(uint8_t exit_code)
{
	ft_putstr_fd(CYAN, 1);
	ft_putstr_fd("exiting shell\n", 1);
	ft_putstr_fd(RESET, 1);
	exit(exit_code);
}

char	*rl_gets(char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
	rl_on_new_line();
	line = readline("\033[0;33mshell:> \033[0m");
	if (line && *line)
		add_history(line);
	return (line);
}

int32_t	main(int32_t ac, char **av, char **envp)
{
	t_data			*data;

	(void)ac, (void)av;
	shell_init(&data, envp);
	while (1)
	{
		data_init(data);
		data->str = rl_gets(data->str);
		sig_restore();
		if (!data->str)
			break ;
		if (!find_lexems(data) || !data->lexems)
			continue ;
		if (!data->go_next && create_tokens(data))
			executor(data);
	}
	free_for_exit(data);
	exit_message(1);
	return (0);
}
