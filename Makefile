CC = gcc
NAME = get_next_line
CFLAGS = -Wall -Wextra -Werror
VALGRIND = valgrind -q --leak-check=full

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -D BUFFER_SIZE=1 *.c -o $@ && $(VALGRIND) ./$@

m: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
