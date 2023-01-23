# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 13:44:04 by ymehlil           #+#    #+#              #
#    Updated: 2023/01/22 18:58:32 by mcatal-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
SRCS		= display.c so_long.c parsing.c check_map.c valid_path.c moves.c
# SRCS		= s
OBJS		= $(SRCS:.c=.o)
CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -g3
MLX_FLAGS	= -lX11 -lXext
LIBFT_DIR	= libft
LIBFT_LIB	= libft/libft.a
MLX_DIR		= minilibx-linux
MLX_LIB		= minilibx-linux/libmlx_Linux.a
	
all:			$(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(MLX_LIB):
	make -C $(MLX_DIR)	

$(NAME):		$(OBJS) $(LIBFT_LIB) $(MLX_LIB)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) $(MLX_FLAGS)


clean:
				$(RM) $(OBJS)
				make -C $(LIBFT_DIR) clean
				make -C $(MLX_DIR) clean

fclean:			clean
				$(RM) $(NAME)
				make -C $(LIBFT_DIR) fclean

re:				fclean $(NAME)
				make -C $(LIBFT_DIR) re
				make -C $(MLX_DIR) re

.PHONY: all clean fclean re
