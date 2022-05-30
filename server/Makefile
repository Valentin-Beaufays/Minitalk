CC =		gcc

NAME =		server.out

CFLAGS =	-Werror -Wextra -Wall

LIB =		libftprintf.a

LIBPATH =	../ft_printf/

INCLUDES =	-I ../ft_printf/

FILES =		main.c

OBJ =		$(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) libftprintf.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INCLUDES) $(LIBPATH)$(LIB)

libftprintf.a:
	@make -C $(LIBPATH) libftprintf.a

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@make -C $(LIBPATH) clean
	@rm -f $(OBJ)

fclean: clean
	@make -C $(LIBPATH) fclean
	@rm -f $(NAME)

re: fclean $(NAME)