/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarah <ffarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:40:56 by ffarah            #+#    #+#             */
/*   Updated: 2021/09/03 23:12:08 by ffarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdint.h>

typedef struct s_vars {
	char	*key;
	char	*value;
}				t_vars;

typedef struct s_vec_vars {
	struct s_vars	*vars;
	int32_t			capacity;
	int32_t			length;
}				t_vec_vars;

typedef struct s_lexem {
	uint8_t			type;
	char			*data;
	struct s_lexem	*next;
	struct s_lexem	*prev;
}				t_lexem;

typedef struct s_argv {
	uint32_t	capacity;
	uint32_t	length;
	char		**argv;
}				t_argv;

typedef struct s_redir
{
	uint8_t		type;
	char		*name;
}				t_redir;

typedef struct s_cmd {
	char			*path;
	char			**args;
	int32_t			in_fd;
	int32_t			out_fd;
	t_redir			reds[2];
	int				index;
	pid_t			pid;
	struct s_cmd	*next;
	struct s_cmd	*prev;

}				t_cmd;

typedef struct s_data
{
	struct sigaction	sa;
	uint8_t				state;
	struct s_cmd		*cmds;
	struct s_cmd		*curr_cmd;
	struct s_lexem		*lexems;
	char				*str;
	char				**env;
	t_vec_vars			*vec_vars;
	int					**pipes;
	int					n_pip;
	int					go_next;
	int					prev_exec;
	int32_t				std_fd[2];
}				t_data;

#endif