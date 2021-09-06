NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror -c
ALLFILES = $(wildcard *.c)
BONUSSRC =	ft_lstmap.c 	ft_lstadd_front.c	ft_lstsize.c\
			ft_lstlast.c 	ft_lstadd_back.c	ft_lstdelone.c\
			ft_lstiter.c 	ft_lstclear.c		ft_lstnew.c
SRC = $(filter-out $(wildcard *lst*.c), $(ALLFILES))
OBJS = $(SRC:.c=.o)
BONUSOBJS = $(BONUSSRC:.c=.o)
LIB = ar rc
# test: fclean
# 		@echo $(SRC)

all:	$(NAME)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(SRC) libft.h
		$(LIB) $(NAME) $(OBJS)
		ranlib $(NAME)
clean:
		rm -f $(OBJS) $(BONUSOBJS)

fclean:		clean
		rm -f $(NAME) libft.h.gch

re:		fclean all

bonus: ${BONUSOBJS}	${OBJS}
		$(CC) $(FLAGS) $(BONUSSRC) libft.h
		$(LIB) $(NAME) $(OBJS) $(BONUSOBJS)
		ranlib $(NAME)

.PHONY: all clean fclean re bonus

