# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 09:19:06 by emagueri          #+#    #+#              #
#    Updated: 2024/02/04 14:40:04 by emagueri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ./push_swap.c \
		  ./errors.c \
		  ./parsing.c \
		  ./parsing_utils.c \
		  ./tiny_sort.c \
		  ./chunks_sort.c \
		  ./chunks_sort_utils.c \
		  ./rules/push.c \
		  ./rules/reverse_rotate.c \
		  ./rules/rotate.c \
		  ./rules/swap.c \
		  ./utils/stk_add_back.c \
		  ./utils/stk_add_front.c \
		  ./utils/stk_befor_last.c \
		  ./utils/stk_clear.c \
		  ./utils/stk_last.c \
		  ./utils/stk_new.c \
		  ./utils/stk_size.c \
		  ./utils/ft_putendl_fd.c \
		  ./utils/ft_strncmp.c \
		  ./utils/ft_strlen.c \
		  ./utils/ft_split.c \
		  ./utils/ft_putchar_fd.c \
		  ./utils/ft_putstr_fd.c \

SRCB	= ./checker_bonus.c \
		  ./checker_utils_bonus.c \
		  ./get_next_line_bonus/get_next_line_bonus.c \
		  ./get_next_line_bonus/get_next_line_utils_bonus.c \
		  ./errors.c \
		  ./parsing.c \
		  ./parsing_utils.c \
		  ./rules/push.c \
		  ./rules/reverse_rotate.c \
		  ./rules/rotate.c \
		  ./rules/swap.c \
		  ./utils/stk_add_back.c \
		  ./utils/stk_add_front.c \
		  ./utils/stk_befor_last.c \
		  ./utils/stk_clear.c \
		  ./utils/stk_last.c \
		  ./utils/stk_new.c \
		  ./utils/stk_size.c \
		  ./utils/ft_putendl_fd.c \
		  ./utils/ft_strncmp.c \
		  ./utils/ft_strlen.c \
		  ./utils/ft_split.c \
		  ./utils/ft_putchar_fd.c \
		  ./utils/ft_putstr_fd.c \

OBJ 	= $(SRC:.c=.o)
OBJB 	= $(SRCB:.c=.o)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= push_swap
NAME_B	= checker

all:$(NAME)

bonus: $(NAME_B)

$(NAME_B):$(OBJB)
	$(CC) $(CFLAGS) $(OBJB) -o $@

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o:%.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJB)

fclean:clean
	rm -rf $(NAME)
	rm -rf $(NAME_B)

re:fclean all

.PHONY: clean