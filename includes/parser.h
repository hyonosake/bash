/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:40:54 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 15:17:33 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "./minishell.h"
//enums
# define STDIN	0
# define STDOUT	1
# define STDERR	2

//enums
# define FILE_TRUNC	0
# define FILE_APP	1
# define FILE_INP	2
# define HEREDOC	3
# define EMPTY		4
//enums

# define NEXT_PROG	0
# define NEXT_ARGS	1

//commands.c
t_cmd		*new_cmd(void);
void		*free_cmd_list(t_cmd **head);
void		push_cmd_back(t_data *data);
int			add_full_path(t_data *data, t_cmd *cmds);
int8_t		find_prog(char **envp, char **prog);
//fdget.c
int			open_file(t_data *data, t_cmd *cmd, char *filename, uint8_t type);
void		open_pipes(t_cmd *curr);
void		close_all_fd(t_data *data);
void		init_fd_changes(t_data *data);
//heredoc.c
void		heredoc_redirect(t_data *data, t_cmd *cmd, char *keyword);
//new_var.c
int			check_if_new_var(t_data *data);
//tokenizer.c
int			create_tokens(t_data *data);
int			tokenizer(t_data *data);
//parser.c
void		check_if_pipe_valid(t_data *data);
void		parse_word_token(t_data *data, t_lexem *curr_word);
int			check_access(char **splitted_path, char **prog);
//redirects.c
t_lexem		*add_redirects_info(t_data *data, t_lexem *lredirect, uint8_t type);
int			fill_redirect(t_data *data, t_cmd *cmd,
				char *filename, uint8_t type);
void		dup_fd_redirects(t_data *data, t_cmd *curr_cmd);

#endif