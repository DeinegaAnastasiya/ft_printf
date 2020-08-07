# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/04 11:09:22 by poatmeal          #+#    #+#              #
#    Updated: 2020/08/06 10:17:00 by poatmeal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft

NAME = ft_printf

FLAGS = -g -Wall -Wextra -Werror

LFLAGS = -L $(LIBFT) -lft

FILES = ./parse_f.c ./main.c ./pow_2.c ./pow_5.c ./init_f.c ./mem_alloc.c ./print_f.c

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