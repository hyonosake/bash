NAME =	minishell
SRCS =	minishell.c \
	builtins/cd.c \
	builtins/echo.c \
	builtins/env.c \
	builtins/export.c \
	builtins/pwd.c \
	builtins/exit.c \
	builtins/unset.c \
	exec/exec_one_cmd.c \
	exec/exec_utils.c \
	exec/execution.c \
	lexer/find_lexems_1.c \
	lexer/find_lexems_2.c \
	lexer/find_lexems_3.c \
	lexer/lexems_utils.c \
	parser/commands.c \
	parser/fdget.c \
	parser/heredoc.c \
	parser/new_var.c \
	parser/parser.c \
	parser/redirects.c \
	parser/tokenizer.c \
	utils/debug.c \
	utils/init_and_delete.c \
	utils/signals.c \
	utils/t_vec_vars_funcs.c \
	utils/utils.c \
	vars/env_var_funcs.c \
	vars/local_var_funcs.c \
	vars/var_integration.c

OBJS = $(SRCS:.c=.o)

SRC_D = $(SRCS:.c=.d)

USR = $(shell whoami)
CC =	gcc

LRD_INC =	-I/Users/$(USR)/.brew/opt/readline/include
LLRD_INC =	-I/usr/local/Cellar/readline/8.1/include
LRD_LIB =	-lreadline -L/Users/$(USR)/.brew/opt/readline/lib
LLRD_LIB =	-lreadline -L/usr/local/Cellar/readline/8.1/lib

FLAGS = -g -MMD \
		-Wall -Wextra -Werror \
		-O2 \
		-fsanitize=address

.c.o:
			$(CC)  $(FLAGS) -c -I minishell.h  $(LLRD_INC) $< -o ${<:.c=.o} 

#$(LIB)		make bonus -C libft

$(NAME):	$(OBJS)
			make -C libft
			$(CC)  $(FLAGS) $(OBJS) libft/libft.a -o $(NAME) $(LLRD_LIB)
	@echo	"MS created"

all:		$(NAME)

c:			all clean
clean:
			make clean -C libft
			rm -f $(OBJS)
			rm -f $(SRC_D)
	@echo "Object files were deleted"

fclean:		clean
			make fclean -C libft
			rm -f $(NAME)
	@echo "Everithing was deleted"

re:			fclean all

-include $(SRC_D)
#.SILENT: