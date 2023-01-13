# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 14:40:32 by hajeong           #+#    #+#              #
#    Updated: 2023/01/13 17:02:29 by hajeong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS =  -g

INCLUDES_DIR = includes
LIBS_DIR = libft
SRCS_DIR = srcs
MLX_DIR = mlx

# srcs directory
PARSING_DIR = parsing
UTIL_DIR = util

PARSING_SRCS = parsing_cub_file.c read_file.c parsing_texture_lines.c
UTIL_SRCS = ft_split_isspace.c

LIBFT_DIR = libft
LIBFT = libft.a
LIBFT_LIB = -lft

SRCS = $(addprefix $(SRCS_DIR)/, cub3d.c) \
	$(addprefix $(SRCS_DIR)/$(PARSING_DIR)/, $(PARSING_SRCS)) \
	$(addprefix $(SRCS_DIR)/$(UTIL_DIR)/, $(UTIL_SRCS))

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR) bonus
	$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDES_DIR) -L $(LIBFT_DIR) $(LIBFT_LIB) -o $@
	
%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

clean :
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re :
	make fclean
	make all

.PHONY = all clean fclean re