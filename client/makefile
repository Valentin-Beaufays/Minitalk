CC =	gcc

NAME =	client.out

CFLAGS = -Werror -Wextra -Wall

LIB =	libftprintf.a

LIBFTPATH =	../ft_printf/

INCLUDES:=	-I ../ft_printf/

FILES =	main.c\
		send.c

OBJ =	$(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) libftprintf.a
	$(CC) -o $(NAME) $(OBJ) $(INCLUDES) $(LIBFTPATH)$(LIB)

libftprintf.a:
	@make -C $(LIBFTPATH) libftprintf.a

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDES) -o $@ $<

clean:
	@make -C $(LIBFTPATH) clean
	@rm -f $(OBJ)

fclean: clean
	@make -C $(LIBFTPATH) fclean
	@rm -f $(NAME)

re: fclean $(NAME)