CC = gcc
NAME = get_next_line
CFLAGS = -Wall -Wextra -Werror
VALGRIND = valgrind --leak-check=full --track-origins=yes

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -D BUFFER_SIZE=10 *.c

d:
	gcc -g -D BUFFER_SIZE=42 *.c

m: $(NAME)
	$(VALGRIND) ./a.out

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
