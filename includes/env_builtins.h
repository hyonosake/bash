/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtins.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:40:44 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 19:58:54 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_BUILTINS_H
# define ENV_BUILTINS_H

# include "minishell.h"

uint8_t	our_cd(char **env, t_cmd *cd_cmd);
uint8_t	back_case(char **env);
uint8_t	our_echo(t_cmd *echo);
uint8_t	our_pwd(char **env);
char	**our_unset(char **env, char *key);
uint8_t	our_export(t_data *data, char **args);
uint8_t	our_env(char **env);
uint8_t	our_exit(t_cmd *cmd_exit);
#endif