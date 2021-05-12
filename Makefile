# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/05 12:03:48 by dcavalei          #+#    #+#              #
#    Updated: 2021/05/12 16:50:15 by dcavalei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= $(shell find $(SRCS_DIRS) -type f -name "*.c")
INCLUDE		= $(addprefix -I, $(INCL_DIRS))
LIB			= $(shell find $(LIB_DIRS) -type f -name "*.a")
OBJS		= $(SRC:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
CUB_FLAGS	= -lmlx -framework OpenGL -framework AppKit
SRCS_DIRS	= src
INCL_DIRS	= includes
LIB_DIRS	= libft minilibx
NAME		= cub3D

RED			= \033[0;31m
GREEN		= \033[0;32m
ORANGE		= \033[0;33m
BLUE		= \033[1;34m
YELLOW		= \033[1;33m
NC			= \033[0m

all:		libft minilibx ${NAME} #clean

bonus:		all

libft:		
			@echo "\n$(YELLOW)Compiling libft:$(NC)"
			@$(MAKE) -C libft/

minilibx:
			@echo "\n$(YELLOW)Compiling minilibx:$(NC)"
			@$(MAKE) -C minilibx/

.c.o:
			@echo "Creating object: $@"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME):	$(OBJS)
			@$(CC) -o $(NAME) $(CFLAGS) $(CUB_FLAGS) $(INCLUDE) $(LIB) $(OBJS)

clean:
			@rm -f $(OBJS)
			@$(MAKE) -C libft/ clean && echo "$(GREEN)libft objects removed!$(NC)"
			@$(MAKE) -C minilibx/ clean && echo "$(GREEN)minilibx objects and library removed!$(NC)"

fclean:
			@rm -f $(OBJS)
			@rm -f $(NAME)
			@$(MAKE) -C minilibx/ clean
			@$(MAKE) -C libft/ fclean

re:			fclean all

.PHONY:		all clean fclean re libft minilibx
