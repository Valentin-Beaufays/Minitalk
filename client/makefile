CC =	gcc

NAME =	client.out

CFLAGS = -Werror -Wextra -Wall

LIB =	libftprintf.a

LIBPATH =	../ft_printf/

LIBFILE =	$(LIBPATH)$(LIB)

INCLUDES:=	-I ../ft_printf/

FILES =	main.c

OBJ =	$(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFILE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INCLUDES) $(LIBPATH)$(LIB)

$(LIBFILE):
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