/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:38:08 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/04 00:40:04 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


// global exit code SIGINT = 1;
void	main_handler(int signum)
{
	if (signum == SIGINT)
	{
		ft_putendl_fd(2);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		prev_exec = 1;
	}
}

void	parent_handler(int signum)
{
	if (signum == SIGQUIT)
	{
		ft_putstr_fd("Quit: 3\n", 2);
		prev_exec = 131;
	}
	else if (signum == SIGINT)
		prev_exec = 130;
}

void	sig_parent()
{
	signal(SIGINT, parent_handler);
	signal(SIGQUIT, parent_handler);
}

void	sig_child()
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	sig_restore()
{
	signal(SIGINT, main_handler);
	signal(SIGQUIT, main_handler);
}