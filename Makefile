CC = gcc
NAME = get_next_line
CFLAGS = -Wall -Wextra -Werror
VALGRIND = valgrind -q --leak-check=full --track-origins=yes --verbose

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -D BUFFER_SIZE=1 *.c && $(VALGRIND) ./a.out

d:
	gcc -g $(CFLAGS) -D BUFFER_SIZE=42 *.c && $(VALGRIND) ./a.out

m: 
	$(VALGRIND) ./a.out

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
