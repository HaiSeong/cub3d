# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 14:40:32 by hajeong           #+#    #+#              #
#    Updated: 2023/01/24 13:25:19 by jungchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit

INCLUDES_DIR = includes
LIBS_DIR = libft
SRCS_DIR = srcs
MLX_DIR = mlx
EVENT_DIR = event

# srcs directory
PARSING_DIR = parsing
UTIL_DIR = util
RAY_DIR = raycast

PARSING_SRCS =	parsing_cub_file.c read_file.c parsing_texture_lines.c \
				parsing_rgb_lines.c parsing_map_lines.c validate_texture_lines.c \
				validate_rgb_lines.c validate_map.c check_needless_lines.c set_play_direction.c
				
UTIL_SRCS =		ft_split_isspace.c init_game_struct.c ft_free_strs.c ft_free_game.c \
				ft_error.c validate_arg.c set_texture_image.c

RAY_SRCS =		raycasting.c calculate_ray_values.c dda.c calculate_perp_wall_dist.c \
				set_floor_ceil.c

EVENT_SRCS =	press_key.c


LIBFT_DIR = libft
LIBFT = libft.a
LIBFT_LIB = -lft

SRCS = $(addprefix $(SRCS_DIR)/, main.c) \
	$(addprefix $(SRCS_DIR)/$(PARSING_DIR)/, $(PARSING_SRCS)) \
	$(addprefix $(SRCS_DIR)/$(UTIL_DIR)/, $(UTIL_SRCS)) \
	$(addprefix $(SRCS_DIR)/$(RAY_DIR)/, $(RAY_SRCS)) \
	$(addprefix $(SRCS_DIR)/$(EVENT_DIR)/, $(EVENT_SRCS))

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR) bonus
	make -C $(MLX_DIR) all
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) -I $(INCLUDES_DIR) -L $(LIBFT_DIR) $(LIBFT_LIB) -o $@
	
%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

clean :
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re :
	make fclean
	make all

.PHONY = all clean fclean re