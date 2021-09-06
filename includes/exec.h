/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:15:35 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 21:43:56 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "struct.h"
# include "minishell.h"

//exec_one_cmd.c
void	exec_if_one_cmd(t_data *data, t_cmd *curr_cmd);
void	one_cmd_token(t_data *data);
//exec_utils.c
uint8_t	is_builtin(t_cmd *cmd);
void	change_sh_lvl(t_data *data);
uint8_t	check_if_minishel(t_cmd *cmd);
void	restore_fd(t_data *data);
//execution.c
void	executor(t_data *data);
void	exec_cmds(t_data *data, t_cmd *curr_cmd);
uint8_t	exec_builtins(t_data *data, t_cmd *cmd);
void	execute_one_cmd(t_data *data, t_cmd *curr);
int		wait_process(t_cmd *cmd);

#endif