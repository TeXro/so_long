CC = cc
CFLAGS = -Wall -Werror -Wextra -w
MLXFLAGS = -lmlx -lXext -lX11
NAME = so_long
SRC = main.c utils.c next_byte.c is_valid.c werr.c moves.c out.c
OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re