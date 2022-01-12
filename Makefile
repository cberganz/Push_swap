# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 03:58:32 by cberganz          #+#    #+#              #
#    Updated: 2021/12/11 10:17:22 by cberganz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##
## ROMOVE DEBUG.TXT AND -G3
##

PS_NAME		= push_swap

CHECKER_NAME = checker

INCLUDE		= include/

HEADER		= $(INCLUDE)push_swap.h

CC			= clang

CFLAGS		= -Wall -Wextra -Werror

SRC_PS_FILES= input_treatment.c			\
		  	utils_input_treatment.c		\
			utils_push_swap.c			\
			utils_lists.c				\
			utils_freememory.c			\
			utils_libft.c				\
			operations_swap.c			\
			operations_push.c			\
			operations_rotate.c			\
			operations_reverse_rotate.c	\
			push_swap_little.c			\
			push_swap_big.c				\
			list_playback.c				\
			optimized_movement.c		\
			main.c						\
			debug.c

SRC_CHECKER_FILES	= input_treatment.c	\
			  utils_input_treatment.c	\
			  utils_lists.c				\
			  utils_freememory.c		\
			  utils_libft.c				\
			  operations_reverse_rotate.c\
			  operations_rotate.c		\
			  operations_push.c			\
			  operations_swap.c			\
			  debug.c					\
			  checker.c

SRC_PS_DIR		= src/
SRC_PS		= $(addprefix $(SRC_PS_DIR), $(SRC_PS_FILES))

SRC_CHECKER_DIR		= src/
SRC_CHECKER		= $(addprefix $(SRC_CHECKER_DIR), $(SRC_CHECKER_FILES))

OBJ_PS_DIR		= objs/
OBJ_PS_FILES	= $(SRC_PS_FILES:.c=.o)
OBJ_PS		= $(addprefix $(OBJ_PS_DIR), $(OBJ_PS_FILES))

OBJ_CHECKER_DIR		= objs/
OBJ_CHECKER_FILES	= $(SRC_CHECKER_FILES:.c=.o)
OBJ_CHECKER		= $(addprefix $(OBJ_CHECKER_DIR), $(OBJ_CHECKER_FILES))

all: $(PS_NAME) $(CHECKER_NAME)

$(PS_NAME): $(OBJ_PS)
	$(CC) $(CFLAGS) $(OBJ_PS) -o $(PS_NAME) -g3

$(CHECKER_NAME): $(OBJ_CHECKER)
	$(CC) $(CFLAGS) $(OBJ_CHECKER) -o $(CHECKER_NAME) -g3

$(OBJ_PS_DIR):
	mkdir -p $@

$(OBJ_PS): | $(OBJ_PS_DIR)
$(OBJ_CHECKER): | $(OBJ_CHECKER_DIR)

$(OBJ_PS_DIR)%.o: $(SRC_PS_DIR)%.c $(HEADER)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@ -g3

$(OBJ_CHECKER_DIR)%.o: $(SRC_CHECKER_DIR)%.c $(HEADER)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@ -g3

clean:
	rm -rf $(OBJ_PS_DIR)

fclean: clean
	rm -f $(PS_NAME)
	rm -f $(CHECKER_NAME)

re: fclean all

.PHONY : all clean fclean re
