/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:40:51 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 21:58:30 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <curses.h>
# include <term.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/types.h>

# include "structs.h"
# include "../libft/libft.h"
# include "env_builtins.h"
# include "exec.h"
# include "lexer.h"
# include "parser.h"
# include "utils.h"
# include "var.h"

# define NEVER_WILL -1

# define PERM_DENIED	": Permission denied.\n"
# define SYNTAX_ERR		"syntax error near unexpected token "
# define NO_FILE		": no such file or directory\n"


# define RESET   "\033[0m"
# define BLACK   "\033[30m"      /* Black */
# define RED     "\033[31m"      /* Red */
# define GREEN   "\033[32m"      /* Green */
# define YELLOW  "\033[33m"      /* Yellow */
# define BLUE    "\033[34m"      /* Blue */
# define MAGENTA "\033[35m"      /* Magenta */
# define CYAN    "\033[36m"      /* Cyan */
# define WHITE   "\033[37m"      /* White */


uint8_t		prev_exec;
void		exit_message(uint8_t exit_code);
char		*rl_gets(char *line);
void		ctrl_d(void);
#endif