CC =	gcc

NAME =	client.out

CFLAGS = -Werror -Wextra -Wall

LIB =	libftprintf.a

LIBPATH =	../ft_printf/

INCLUDES:=	-I ../ft_printf/

FILES =	main.c\
		send.c

OBJ =	$(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) libftprintf.a
	$(CC) -o $(NAME) $(OBJ) $(INCLUDES) $(LIBPATH)$(LIB)

libftprintf.a:
	@make -C $(LIBPATH) libftprintf.a

%.o: %.c
	$(CC) -c $(INCLUDES) -o $@ $<

clean:
	@make -C $(LIBPATH) clean
	@rm -f $(OBJ)

fclean: clean
	@make -C $(LIBPATH) fclean
	@rm -f $(NAME)

re: fclean $(NAME)