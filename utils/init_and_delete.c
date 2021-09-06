/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:40:26 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/04 00:00:47 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	test_handler(int signum, siginfo_t *siginfo, void *data)
{
	(void)siginfo;
	(void)data;
	if (signum == SIGINT)
	{
		ft_putendl_fd(2);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		prev_exec = 1;
	}
}

void	*free_lexems_list(t_lexem **head)
{
	t_lexem	*tmp;
	t_lexem	*to_free;

	tmp = *head;
	while (tmp)
	{
		to_free = tmp;
		tmp = tmp->next;
		if (to_free->data)
			free(to_free->data);
		free(to_free);
	}
	return (NULL);
}

void	free_data_struct(t_data	*data)
{
	if (data->lexems)
		free_lexems_list(&data->lexems);
	if (data->cmds)
		free_cmd_list(&data->cmds);
	if (data->str)
		free(data->str);
}

void	free_for_exit(t_data *data)
{
	free_data_struct(data);
	free_local_var(data->vec_vars);
	free_2d_array(data->env);
	//rl_clear_history()
}

void	data_init(t_data *data)
{
	data->go_next = 0;
	if (data->lexems)
		data->lexems = free_lexems_list(&data->lexems);
	if (data->cmds)
		data->cmds = free_cmd_list(&data->cmds);
	signal(SIGINT, main_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	shell_init(t_data **data, char **envp)
{

	rl_outstream = stderr;
	(*data) = (t_data *)ft_calloc(sizeof(t_data), 1);
	(*data)->env = init_env(envp);
	(*data)->vec_vars = local_var_create();
	(*data)->prev_exec = 0;
	(*data)->str = NULL;
	sig_restore();
	prev_exec = 0;
	signal(SIGINT, main_handler);
	signal(SIGQUIT, SIG_IGN);
}