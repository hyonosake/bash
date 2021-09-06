/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:39:06 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 14:19:43 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

void	print_lexems(t_lexem *lexems)
{
	int	i;

	i = 0;
	while (lexems)
	{
		++i;
		printf("==== LEXEM %d - ", i);
		if (lexems->type == OPERATION)
			printf("OPERATION ====\n");
		else if (lexems->type == IN_VAR_VALUE)
			printf("IN_VAR_VALUE ====\n");
		else if (lexems->type == PLAIN_TEXT)
			printf("PLAIN ====\n");
		if (lexems->data)
			printf("%s\n", lexems->data);
		else
			printf("spaces\n");
		lexems = lexems->next;
	}
}

void	print_env_vars(t_vec_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->length)
	{
		printf("%s = %s\n", vars->vars[i].key, vars->vars[i].value);
		++i;
	}
}

void	print_cmd_tokens(t_cmd *cmds)
{
	int			pos;

	pos = 0;
	while (cmds)
	{
		printf("===== CMD %d =====\n", ++pos);
		print_cmd(cmds);
		printf("-----------------------\n");
		cmds = cmds->next;
	}
}

void	print_cmd(t_cmd *cmd)
{
	uint32_t	i;

	printf("Full path:\n");
	printf("|%s\n|", cmd->path);
	i = 0;
	while (cmd->args[i])
		printf("arg: %s\n", cmd->args[i++]);
	if (!cmd->args[i])
		printf("(null)\n");
}
