CC = gcc

NAME = server.out

CFLAGS = -Werror -Wextra -Wall

LIB =	libftprintf.a

LIBFTPATH =	../ft_printf/

INCLUDES:=	-I ../ft_printf/

FILES =	main.c

OBJ =	$(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:

fclean: clean

re: