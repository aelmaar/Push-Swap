# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 17:04:48 by ael-maar          #+#    #+#              #
#    Updated: 2023/01/18 18:21:00 by ael-maar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = ./push_swap_srcs
PUSH_SWAP_SRCS = $(PUSH_SWAP)/push_swap.c $(PUSH_SWAP)/push_swap_utils.c \
$(PUSH_SWAP)/calc_operations_stack_a.c $(PUSH_SWAP)/calc_operations_stack_b.c \
$(PUSH_SWAP)/calc_operations_utils.c $(PUSH_SWAP)/run_moves_stack_a.c \
$(PUSH_SWAP)/run_moves_stack_b.c $(PUSH_SWAP)/run_moves_utils.c $(PUSH_SWAP)/run.c

CHECKER = ./checker_srcs
CHECKER_SRCS = $(CHECKER)/check_utils.c $(CHECKER)/checker.c $(CHECKER)/run.c

UTILS = ./utils
UTILS_SRCS = $(UTILS)/actions.c $(UTILS)/error.c $(UTILS)/run_actions.c


LIBFT = ./libft
LIBFT_LIB = $(LIBFT)/libft.a


GET_NEXT_LINE = ./get_next_line
GET_NEXT_LINE_SRCS = $(GET_NEXT_LINE)/get_next_line.c $(GET_NEXT_LINE)/get_next_line_utils.c

INCL = ./Includes
HEADER_FILES = -I $(INCL) -I $(LIBFT) -I $(GET_NEXT_LINE)

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(LIBFT_LIB):
	make bonus -C $(LIBFT)

$(NAME): $(LIBFT_LIB) $(PUSH_SWAP_SRCS) $(UTILS_SRCS)
	$(CC) $(CFLAGS) $^ $(HEADER_FILES) -o $@

checker: $(LIBFT_LIB) $(CHECKER_SRCS) $(GET_NEXT_LINE_SRCS) $(UTILS_SRCS)
	$(CC) $(CFLAGS) $^ $(HEADER_FILES) -o $@

bonus: checker

clean:
	make clean -C $(LIBFT)

fclean:
	make fclean -C $(LIBFT)
	rm -rf checker $(NAME)

re: fclean all

.PHONY: all bonus re clean fclean