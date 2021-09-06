/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:27:31 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 18:48:28 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*adddot(char *file)
{
	char	*new;
	int		i;

	i = 1;
	new = malloc(ft_strlen(file) + 2);
	new[0] = '.';
	while (file && i <= ft_strlen(file))
	{
		new[i] = file[i - 1];
		++i;
	}
	new[i] = 0;
	return (new);
}

static void	heredoc_routine(char *keyword, t_data *data, int fd)
{
	char	*in_line;

	in_line = NULL;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		if (in_line)
			free(in_line);
		in_line = readline("\033[0;32mheredoc> \033[0m");
		parse_vars_in_str(data, &in_line);
		if (!strcmp(in_line, keyword))
			break ;
		write(fd, in_line, ft_strlen(in_line));
		write(fd, "\n", 1);
	}
	close(fd);
	exit(0);
}

void	heredoc_redirect(t_data *data, t_cmd *cmd, char *keyword)
{
	char	*filename;
	int		fd;
	int		status;
	int		pid;

	filename = adddot(keyword);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
		heredoc_routine(keyword, data, fd);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		prev_exec = WEXITSTATUS(status);
	if (WIFSIGNALED(status) && prev_exec != 0)
		prev_exec = WTERMSIG(status);
	signal(SIGQUIT, main_handler);
	signal(SIGINT, main_handler);
	cmd->reds[0].type = FILE_INP;
	cmd->reds[0].name = filename;
}
