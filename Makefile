# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 16:54:31 by mbenaoui          #+#    #+#              #
#    Updated: 2022/03/28 18:31:36 by mbenaoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILE =	so_long_/put_img.c\
		    so_long_/check_Map.c\
			so_long_/map_error.c\
			so_long_/read_map.c\
			Get_next_line/get_next_line_utils.c\
			Get_next_line/get_next_line.c\
			so_long_/window_game.c\
			so_long_/window_map.c\
			so_long_/siumo.c\
			so_long_/check_nome_MAP.c\
			ft_printf/ft_putnbr.c\
			ft_printf/ft_putchar.c\
			ft_printf/ft_printf.c\
			so_long_/exit_game2.c\
			so_long_/ft_split.c

SRC_FILE_B = so_long_bonus/check_Map.c\
			so_long_bonus/put_img.c\
			so_long_bonus/map_error.c\
			so_long_bonus/read_map.c\
			so_long_bonus/ft_itoa.c\
			so_long_bonus/exit_game2.c\
			so_long_bonus/ft_split.c\
			Get_next_line/get_next_line_utils.c\
			Get_next_line/get_next_line.c\
			so_long_bonus/window_game.c\
			so_long_bonus/window_map.c\
			so_long_bonus/siumo.c\
			so_long_bonus/check_nome_MAP.c\
			so_long_bonus/enimy.c 

CC = gcc
RM = rm -f
NAME = so_long
HEADER = so_long_/so_long.h get_next_line/get_next_line.h 
HEADER_B = so_long_bonus/so_long_bouns.h get_next_line/get_next_line.h
CFLAGS = -Wall -Wextra -Werror
INCLUDE =  -lmlx -framework openGL -framework AppKit 
OBJ_FILE = $(SRC_FILE:.c=.o)
OBJ_FILE_B = $(SRC_FILE_B:.c=.o)


all : $(NAME)



$(NAME) : $(OBJ_FILE) $(HEADER)
	@echo "\033[0;34m\n\nCompiling so_long..."
	@$(CC) $(INCLUDE) $(OBJ_FILE) -o $(NAME)
	@echo $(NAME) compiled
	
%.o:%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ_FILE_B) $(HEADER_B)
	@echo "\033[0;34m\n\nCompiling so_long_bouns..."
	@$(CC) $(INCLUDE) $(OBJ_FILE_B) -o $(NAME)
	@echo $(NAME) compiled

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@echo "\033[0;31m\nDeleting objects..."
	@rm -f $(OBJ_FILE) $(OBJ_FILE_B)
	@echo $(NAME) object files cleaned

fclean :	clean
	@rm -f $(NAME)
	@echo $(NAME) cleaned

re : fclean all
