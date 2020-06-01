# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmbangel <lmbangel@student.wethinkcode.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/14 19:18:22 by lmbangel          #+#    #+#              #
#    Updated: 2020/05/30 13:09:56 by lmbangel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC  = Main.c\
		Shell.c\
		Echo.c\
		Signals.c\
		Env.c\
		SetEnv.c\
		Unsetenv.c\
		Cd.c\

LIB     = ./libft/libft.a

OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/ re
		@$(CC) -g -o $(NAME) $(OBJ) $(FLAGS) -I. $(LIB) -lreadline
		@echo "\033[32mSuccessful compilation.\033[0m"
		@echo "\033[32mMINISHELL CREATED.\033[0m"
clean:
	rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
		@echo "\033[31mOBJECT FILES REMOVED.\033[0m"
re:     fclean all 