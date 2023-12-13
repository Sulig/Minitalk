# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 15:16:14 by sadoming          #+#    #+#              #
#    Updated: 2023/12/13 20:50:46 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = client
NAME2 = server

BONUS1 = client_bonus
BONUS2 = server_bonus

DEF = 10959 "h"
# ------------------ #
# Flags:

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
# ------------------ #
# Directories:

DIR1 = ./src
DIR2 = ./src

DIRB1 = ./bonus
DIRB2 = ./bonus

LIBFT = ./Libft
# ------------------- #
# Sorces:

MAK = Makefile

ARL = $(LIBFT)/libft.a

SRC1 = client
SRC2 = server

SRCB1 = client_bonus
SRCB2 = server_bonus

OBJ1 = $(addprefix $(DIR1)/, $(addsuffix .o, $(SRC1)))
OBJ2 = $(addprefix $(DIR2)/, $(addsuffix .o, $(SRC2)))

OBJB1 = $(addprefix $(DIRB1)/, $(addsuffix .o, $(SRCB1)))
OBJB2 = $(addprefix $(DIRB2)/, $(addsuffix .o, $(SRCB2)))
# ******************************************************************************* #
#-------------------------------------------------------------#
all: $(NAME1) $(NAME2)

bonus: $(BONUS1) $(BONUS2)
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
	@echo "\n~ Extra comands:\n"
	@echo "\t~ debug_client \t #-> Ejecutes lldb $(NAME1) $(DEF)\n"
	@echo "\t~ debug_server \t #-> Ejecutes lldb $(NAME2)\n"
	@echo "\t~ leaks_client \t #-> Ejecutes leaks $(NAME1) $(DEF)\n"
	@echo "\t~ leaks_server \t #-> Ejecutes leaks $(NAME2)\n"
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
	@make -s $(BONUS1)
	@make -s $(BONUS2)

#-------------------------------------------------------------#
norm:
	@echo "\n\033[1;93m\n~ Norminette:\n"
	@norminette
	@echo "\n~~~~~~~~~~~~~~~~~~~~~~\n"
	@norminette -R CheckForbiddenSourceHeader
	@echo "\033[1;32m\n ~ Norminette:\t~ OK\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~\n"
#-------------------------------------------------------------#
# ******************************************************************************* #
# Compiling Region:

# Libft:
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
	@echo "~ **************************************** ~\033[1;37m\n"
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
	@echo "~ **************************************** ~\033[1;37m\n"
#-------------------------------------------------------------#
#-------------------------------------------------------------#
#### BONUS ####
# Client_bonus:

$(DIRB1)/%.o: $(DIRB1)/%.c $(MAK)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS1): $(MAK) $(ARL) $(OBJB1)
	@echo "\033[1;37m\n~ **************************************** ~\n"
	@echo "\033[1;93m * Making $(BONUS1) -->\033[1;97m\n"
	@$(CC) $(ARL) $(OBJB1) -o $(BONUS1)
	@echo "\033[1;35m\n~ **************************************** ~\n"
	@echo "  ~\t Client_bonus is ready!\t         ~\n"
	@echo "~ **************************************** ~\033[1;37m\n"
#-------------------------------------------------------------#
# Server_bonus:

$(DIRB2)/%.o: $(DIRB2)/%.c $(MAK)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS2): $(MAK) $(ARL) $(OBJB2)
	@echo "\033[1;37m\n~ **************************************** ~\n"
	@echo "\033[1;93m * Making $(BONUS2) -->\033[1;97m\n"
	@$(CC) $(ARL) $(OBJB2) -o $(BONUS2)
	@echo "\033[1;35m\n~ **************************************** ~\n"
	@echo "  ~\t Server_bonus is ready!\t         ~\n"
	@echo "~ **************************************** ~\033[1;37m\n"
#-------------------------------------------------------------#
# ******************************************************************************* #
# Debuging region:

debug_client: $(NAME1)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME1) $(DEF)"
	@echo "\n~ **************************************** ~\n"
	@lldb $(NAME1) $(DEF)

debug_server: $(NAME2)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME2)"
	@echo "\n~ **************************************** ~\n"
	@lldb $(NAME2)

# ------------------

leaks_client: $(NAME1)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME1) $(DEF)"
	@echo "\n~ **************************************** ~\n"
	@leaks -atExit -- ./$(NAME1) $(DEF)

leaks_server: $(NAME2)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME2)"
	@echo "\n~ **************************************** ~\n"
	@leaks -atExit -- ./$(NAME2)
#-------------------------------------------------------------#
# ******************************************************************************* #
# Clean region

clean:
	@make -s clean -C $(LIBFT)
	@/bin/rm -f $(OBJ1)
	@/bin/rm -f $(OBJ2)
	@/bin/rm -f $(OBJB1)
	@/bin/rm -f $(OBJB2)
	@echo "\033[1;34m\n All obj removed\033[1;97m\n"


fclean: clean
	@make -s fclean -C $(LIBFT)
	@/bin/rm -f $(NAME1)
	@/bin/rm -f $(NAME2)
	@/bin/rm -f $(BONUS1)
	@/bin/rm -f $(BONUS2)
	@find . -name ".DS_Store" -type f -delete
	@echo "\033[1;34m All cleaned succesfully\033[1;97m\n"

clear: fclean
	@clear

re: fclean all
re_trueall: clear trueall
# -------------------- #
.PHONY: all autor bonus clean clear fclean norm re re_trueall trueall
.PHONY: help debug_client debug_server leaks_client leaks_server
# ********************************************************************************** #
