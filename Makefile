# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 12:18:20 by mjulliat          #+#    #+#              #
#    Updated: 2022/11/02 17:43:39 by mjulliat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	### COMPILATION ###

CC			= gcc 
FLAGS		= -Wall -Werror -Wextra

	### EXECUTABLE ###

NAME		= fractol
FRAMEWORK	= -framework OpenGL -framework AppKit

	### INCLUDES ###

SRCS_PATH	= srcs
OBJS_PATH	= objs
HEADERS		= incl
MLX			= libmlx

	### SOURCE FILE ###

SOURCES		= main.c

	### OBJETCTS ###

SRCS		= $(addprefix $(SRCS_PATH)/,$(SOURCES))
OBJS		= $(addprefix $(OBJS_PATH)/,$(SOURCES:.c=.o))
	### COLORS ###

RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
VIOLET		= \033[1;35m
CYAN		= \033[1;36m
NOC			= \033[0m
WHITE		= \033[1;37m

	### RULES ###

all:		mlx tmp $(NAME)

$(NAME):	$(OBJ) $(OBJS)
			$(CC) $(FLAGS) -L$(MLX) -lmlx $(FRAMEWOKR) -o $@ $^ 
			@echo "$(GREEN) ######## Project compilated ######## $(WHITE)"

mlx:
			make -C $(MLX)
			@cp $(MLX)/libmlx.dylib .
			@echo "$(GREEN)######## LIBMLX.A Created ######## $(WHITE)"

tmp:		
			@mkdir -p objs

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
					$(CC) $(FLAGS) -I$(HEADERS) -I$(MLX) -c $< -o $@ 
					@echo "$(BLUE) ######## Creating obect file ######### $(WHITE)"


clean:	
			@echo "$(BLUE)######## Supressing files and library ######## $(YELLOW)"
			make clean -C $(MLX)
			@rm -rf libmlx.dylib
			@rm -rf $(OBJS_PATH)


fclean:		clean
			@rm -rf $(NAME)

re:			fclean all

.PHONY:		mlx clean, fclean, re,
