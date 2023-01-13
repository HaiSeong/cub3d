# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 14:40:32 by hajeong           #+#    #+#              #
#    Updated: 2023/01/13 14:57:18 by hajeong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d
LIBFT		= libft
MLX			= mlx

SRCS =	cub3d.c\
		# parsing_map.c

OBJS		= $(SRCS:%.c=%.o)

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)/
		make all -C $(MLX)/
		cc -o $(NAME) $(OBJS) -L ./libft -l ft -L ./mlx -l mlx -framework OpenGL -framework AppKit

%.o			:	%.c
		cc $(FLAGS) -c $^ -o $@


clean		:
		rm -f $(OBJS)
		make clean -C $(LIBFT)

fclean		:	clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)

re			:	fclean all

.PHONY		:	all clean fclean re