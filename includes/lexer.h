/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:40:48 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 21:54:07 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# define PLAIN_TEXT 0
# define IN_VAR_VALUE 1
# define OPERATION 2
# define STATE_DLR 21
# define STATE_ERR 42

# include "minishell.h"

//find_lexems_1.c
int			find_lexems(t_data *data);
void		parse_lexems(t_data *data, char *str);
uint32_t	parse_double_quotes_lexem(t_data *data, char *str);
uint32_t	parse_single_quotes_lexem(t_data *data, char *str);
uint32_t	parse_word_lexem(t_data *data, char *str);
//find_lexems_2.c
uint32_t	parse_pipe_lexem(t_data *data, char *str);
uint32_t	parse_redirects_lexem(t_data *data, char *str);
uint32_t	parse_spaces_lexem(t_data *data, char *str);
uint32_t	parse_variable_argument_lexem(t_data *data, char *str);
uint32_t	parse_var_dlr(t_data *data, char *str);
//find_lexems_3.c
uint32_t	parse_key_lexem(char *str, char **key_str);
void		unfold_var_name_to_str(t_data *data, char **str, uint32_t var_pos);
void		parse_vars_in_str(t_data *data, char **str);
int			just_a_dollar_sign(char *in_quotes);
void		free_one_lexem(t_lexem *to_free);
//lexem_utils.c
t_lexem		*new_lexem(char *data, uint8_t type);
t_lexem		*push_back_lexem(t_lexem **head, char *data, uint8_t type);
t_lexem		*rm_lexem(t_lexem **head, t_lexem **delete_me);
uint8_t		make_lexems_pretty(t_data *data);
t_lexem		*stick_same_lexems(t_lexem **head, t_lexem *curr, t_lexem *next);
#endif 