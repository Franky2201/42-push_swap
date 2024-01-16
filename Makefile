# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 18:55:23 by gde-win           #+#    #+#              #
#    Updated: 2024/01/17 00:21:00 by gde-win          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := 	push_swap

CC := 		cc

CFLAGS := 	-Wall -Wextra -Werror -I. -fsanitize=address -g

FUNCTIONS :=	push_swap.c \
				big_sort.c \
				check_args.c \
				compute_costs.c \
				init_stack.c \
				push.c \
				rotate.c \
				sort.c \
				sort_utils.c \
				swap.c

SRCS := 	$(FUNCTIONS)

OBJS := 	$(SRCS:.c=.o)

INCLUDE :=	push_swap.h

LIBFT :=	libft

all: 		$(LIBFT) $(NAME)

$(LIBFT):
			@make -C $@

$(NAME): 	$(OBJS)
			$(CC) $(CFLAGS) -Wl,libft/libft.a $^ -o $@

clean:
			rm -rf $(OBJS)
			@make clean -C $(LIBFT)

fclean: 	clean
			rm -rf $(NAME)
			rm -rf libft/libft.a

re: 		fclean all

.PHONY: 	all clean fclean re libft
