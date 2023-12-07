# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 15:16:14 by sadoming          #+#    #+#              #
#    Updated: 2023/12/07 19:30:44 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = client
NAME2 = server
# ------------------ #
# Flags:

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
# ------------------ #
# Directories:

DIR1 = ./
DIR2 = ./
LIBFT = ./Libft
# ------------------- #
# Sorces:

MAK = Makefile

ARL = $(LIBFT)/libft.a

SRC1 = client
SRC2 = 

OBJ1 = $(addprefix $(DIR1)/, $(addsuffix .o, $(SRC1)))
OBJ2 = $(addprefix $(DIR2)/, $(addsuffix .o, $(SRC2)))
# ******************************************************************************* #
#-------------------------------------------------------------#
all: $(NAME1) $(NAME2)
#-------------------------------------------------------------#
#-------------------------------------------------------------#
help:
	@echo "\033[1;37m\n ~ Posible comands:\n"
	@echo "\t~ all  \t\t #-> Make $(NAME1) & $(NAME2)\n"
	@echo "\t~ clean \t #-> Clean *.o\n"
	@echo "\t~ fclean \t #-> Clean all\n"
	@echo "\t~ clear \t #-> Clean all & clear\n"
	@echo "\t~ norm \t\t #-> Run norminette\n"
	@echo "\t~ trueall \t #-> Make norm + make all\n"
	@echo "\t~ re   \t\t #-> Redo $(NAME1) & $(NAME2)\n"
	@echo "\t~ re_trueall \t #-> Redo & make trueall\n"
	@make -s author

#-------------------------------------------------------------#
#-------------------------------------------------------------#
author:
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo "\n   ~ \t      Made by Sadoming \t        ~\n"
	@echo "\n~ **************************************** ~\033[1;37m\n\n"
#-------------------------------------------------------------#
#-------------------------------------------------------------#
trueall:
	@make -s norm
	@echo "\033[0;37m\n~ **************************************** ~\n"
	@make -s $(NAME1)
	@make -s $(NAME2)

#-------------------------------------------------------------#
norm:
	@echo "\n\033[1;93m\n~ Norminette:\n"
	@norminette
	@echo "\n~~~~~~~~~~~~~~~~~~~~~~\n"
	@norminette -R CheckForbiddenSourceHeader
	@echo "\033[1;32m\n ~ Norminette:\t~ OK\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~\n"
#-------------------------------------------------------------#
#-------------------------------------------------------------#
# ******************************************************************************* #
# Compiling Region:

$(ARL):
	@echo "\033[1;93m\n * Compiling Libft -->\033[1;97m\n"
	@make -s -C $(LIBFT)
	@echo "\033[1;37m\n~ **************************************** ~\n"
#-------------------------------------------------------------#
# Client:

$(DIR1)/%.o: $(DIR1)/%.c $(MAK)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME1): $(MAK) $(ARL) $(OBJ1)
	@echo "\033[1;37m\n~ **************************************** ~\n"
	@echo "\033[1;93m * Making $(NAME1) -->\033[1;97m\n"
	@$(CC) $(ARL) $(OBJ1) -o $(NAME1)
	@echo "\033[1;35m\n~ **************************************** ~\n"
	@echo "  ~\t      Client is ready!\t         ~\n"
	@echo "~ **************************************** ~\n"
#-------------------------------------------------------------#
# Server:

$(DIR2)/%.o: $(DIR2)/%.c $(MAK)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME2): $(MAK) $(ARL) $(OBJ2)
	@echo "\033[1;37m\n~ **************************************** ~\n"
	@echo "\033[1;93m * Making $(NAME2) -->\033[1;97m\n"
	@$(CC) $(ARL) $(OBJ2) -o $(NAME2)
	@echo "\033[1;35m\n~ **************************************** ~\n"
	@echo "  ~\t      Server is ready!\t         ~\n"
	@echo "~ **************************************** ~\n"
#-------------------------------------------------------------#
#-------------------------------------------------------------#
# ******************************************************************************* #
# Clean region

clean:
	@make -s clean -C $(LIBFT)
	@/bin/rm -f $(OBJ1)
	@/bin/rm -f $(OBJ2)
	@echo "\033[1;34m\n All obj removed\033[1;97m\n"


fclean: clean
	@make -s fclean -C $(LIBFT)
	@/bin/rm -f $(NAME1)
	@/bin/rm -f $(NAME2)
	@find . -name ".DS_Store" -type f -delete
	@echo "\033[1;34m All cleaned succesfully\033[1;97m\n"

clear: fclean
	@clear

re: fclean all
re_trueall: clear trueall
# -------------------- #
.PHONY: all autor clean clear fclean norm re trueall
# ********************************************************************************** #