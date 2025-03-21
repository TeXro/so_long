CC = cc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -lmlx -lXext -lX11
NAME = so_long
SRC = main.c utils.c next_byte.c is_valid.c werr.c moves.c out.c
OBJ = ${SRC:.c=.o}
HEADER = so_long.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) $(CFLAGS) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.SECONDARY: $(OBJ)
.PHONY: all clean fclean re
