/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:41:00 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 15:47:32 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_H
# define VAR_H

# include "minishell.h"

//env_var_funcs.c
char	**init_env(char **envp);
int8_t	change_env_var(char **env, char *key, char *value, int32_t len);
char	*find_env_var(char **envp, char *key, int32_t len);
char	*find_env_line(char **envp, char *key, int32_t len);
//locl_var_funcs.c
int		change_local_value(t_vec_vars *vvars, char *key, char *value);
void	add_local_var(t_data *data, char *key, char *value);
char	*find_local_var(t_data *data, char *key);
int32_t	check_key(char *env_key, char *given_key);
//var_integrationc.c
void	add_or_change_var(t_data *data, char *key, char *value);
char	*find_var_value(t_data *data, char *key);
#endif