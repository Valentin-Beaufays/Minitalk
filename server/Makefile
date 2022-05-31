CC =		gcc

NAME =		server.out

CFLAGS =	-Werror -Wextra -Wall

LIB =		libftprintf.a

LIBPATH =	../ft_printf/

INCLUDES =	-I ../ft_printf/

FILES =		main.c

OBJ =		$(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) ../ft_printf/libftprintf.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INCLUDES) $(LIBPATH)$(LIB)

../ft_printf/libftprintf.a:
	@make -C $(LIBPATH) libftprintf.a

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDES) -o $@ $<

clean:
	@make -C $(LIBPATH) clean
	@rm -f $(OBJ)

fclean: clean
	@make -C $(LIBPATH) fclean
	@rm -f $(NAME)

re: fclean $(NAME)