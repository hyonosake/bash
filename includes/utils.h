/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:40:58 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 22:56:58 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "./minishell.h"

//degug.c
void		print_lexems(t_lexem *lexems);
void		print_env_vars(t_vec_vars *vars);
void		print_cmd_tokens(t_cmd *cmds);
void		print_cmd(t_cmd *cmd);
//init_and_delete.c
void		*free_lexems_list(t_lexem **head);
void		free_data_struct(t_data	*data);
void		free_for_exit(t_data *data);
void		data_init(t_data *data);
void		shell_init(t_data **data, char **envp);
//signals.c
void		main_handler(int signum);
void		parent_handler(int signum);
void		sig_parent();
void		sig_restore();
void		sig_child();
//t_vec_vars_funcs.c
void		free_local_var(t_vec_vars *v_vars);
t_vec_vars	*local_var_create(void);
void		local_var_realloc(t_vec_vars *vec_vars);
int			valid_name_for_var(char *str);
//utils.c
uint8_t		allowed_lexem_char(char sym);
void		unexpected_token(t_data *data, const char *err_msg, const int sym);
void		error_msg(const char *prog_name, const char *arg, const char *error);
uint8_t		is_env_name(char *name);
#endif