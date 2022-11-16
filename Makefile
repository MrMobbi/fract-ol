# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 12:18:20 by mjulliat          #+#    #+#              #
#    Updated: 2022/11/16 11:43:04 by mjulliat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	### COMPILATION ###

CC			= gcc -g
FLAGS		= -Wall -Werror -Wextra

	### EXECUTABLE ###

NAME		= fractol
FRAMEWORK	= -framework OpenGL -framework AppKit

	### INCLUDES ###

SRCS_PATH	= srcs
OBJS_PATH	= objs
HEADERS		= incl
MLX			= libmlx
PRINTF		= ft_printf

	### SOURCE FILE ###

SOURCES		= main.c\
			  hook.c\
			  fractal_init.c\
			  colors.c\
			  utils.c\
			  set_fractal.c

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

all:		mlx tmp printf $(NAME)

$(NAME):	$(OBJ) $(OBJS)
			@echo "$(BLUE)######## Obect file Created ######### $(WHITE)"
			$(CC) $(FLAGS) -L$(MLX) -L$(PRINTF) -lftprintf -lmlx $(FRAMEWOKR) -o $@ $^ 
			@echo "$(GREEN)######## Project Compilated ######## $(WHITE)"

printf:
			make -C $(PRINTF)
			cp ft_printf/libftprintf.a .
			@echo "$(CYAN)######## LIBFTPRINTF.A Created ######## $(WHITE)"

mlx:
			make -C $(MLX)
			@cp $(MLX)/libmlx.dylib .
			@echo "$(CYAN)######## LIBMLX.A Created ######## $(WHITE)"

tmp:		
			@mkdir -p objs

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
					$(CC) $(FLAGS) -I$(HEADERS) -I$(MLX) -I$(PRINTF) -c $< -o $@ 

clean:	
			@echo "$(VIOLET)######## Supressing files and library ######## $(YELLOW)"
			make clean -C $(MLX)
			make fclean -C $(PRINTF)
			@rm -rf $(OBJS_PATH)


fclean:		clean
			@rm -rf libftprintf.a
			@rm -rf libmlx.dylib
			@rm -rf $(NAME)

re:			fclean all

.PHONY:		mlx clean, fclean, re, run
