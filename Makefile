# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 16:59:31 by aybelaou          #+#    #+#              #
#    Updated: 2024/12/31 19:07:18 by aybelaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -----------------------------------Colors------------------------------------

RED		=\033[0;31m
GREEN	=\033[0;32m
YELLOW	=\033[1;33m
BLUE	=\033[0;34m
ORANGE	=\033[38;2;255;165;0m
RESET	=\033[0m

# ---------------------------------Compilation---------------------------------

NAME	= so_long
CC 		= cc
CFLAGS 	= -Werror -Wall -Wextra -I includes
RM 		= rm -rf

OBJS_DIR = objs
SRCS_DIR = srcs
SRCS 	= $(wildcard $(SRCS_DIR)/parsing/*.c) $(wildcard $(SRCS_DIR)/main/*.c)

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
MLX_DIR = ./minilibx-linux
MLX_PATH = minilibx-linux/libmlx.a
MLX =  -L /usr/lib -lXext -lX11 -lm -lz 
MLX_OBJ = -I/usr/include -Imlx_linux -O3

# ---------------------------------Librairies----------------------------------
 
LIBFT = libft/libft.a
MLX_LIB = -L $(MLX_DIR) -lmlx

# -----------------------------------Rules-------------------------------------

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	@make -C $(MLX_DIR)
	@echo "$(GREEN)Building libft...$(RESET)"
	@make -C libft
	@$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -g $(MLX_LIB) $(MLX) -o $(NAME)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@	

$(LIBFT):
	@make -C libft

fclean : clean
	@make fclean -C libft
	@$(RM) $(NAME)

clean :
	@make clean -C libft
	@$(RM) -r $(OBJS_DIR)
	@$(RM) srcs/*.o

re : fclean all

.PHONY: all clean fclean re