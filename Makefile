LIBFT = libft

NAME = ft_printf

FLAGS = -g -Wall -Wextra -Werror

LFLAGS = -L $(LIBFT) -lft

FILES = ./my_printf.c

OBJS = $(FILES:%.c=%.o)

INCLUDES = includes

all: libft.a $(NAME)

libft.a:
	make -C $(LIBFT)

$(NAME): $(OBJS)
	gcc $(FLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

%.o: %.c
	gcc $(FLAGS) -I $(LIBFT) -I $(INCLUDES) -o $@ -c $<

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re