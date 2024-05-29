P_S_SRC = push_swap.c split.c shorts_fs.c handlers_ps.c moves_ps.c helper_functions_ps.c helper_functions_2.c helper_functions_3.c helper_functions_4.c

P_S_OBJ = $(P_S_SRC:.c=.o)

NAME = push_swap
HEADER = push_swap.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(P_S_OBJ)
	$(CC) $(CFLAGS) $(P_S_OBJ) -o $(NAME) 

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(P_S_OBJ)
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
