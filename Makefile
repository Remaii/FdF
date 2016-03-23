#*****************************************************************************#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/06 13:02:35 by rthidet           #+#    #+#             *#
#*   Updated: 2016/03/22 19:36:29 by rthidet          ###   ########.fr       *#
#*                                                                            *#
#******************************************************************************#

NAME =
EXE = fdf
LFT = inc/libft.a
LIBS =-L./inc/ -lft -lmlx
EXP = ./Examples/

HPATH = -I ./inc/

SRC = *.c

#STANDARD VARIABLES
CC = gcc -Wall -Wextra -Werror
C_MLX = $(MLX) -framework OpenGL -framework AppKit
AR = ar -cvq libft.a
RM = rm -rf
SRCDIR = $(addprefix ./src/, $(SRC))
OBJDIR = object
OBJ = $(addprefix ./$(OBJDIR)/, $(SRC:.c=.o))

# COLORS
RESET=\033[0m
DARK=\033[132m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
MAGENTA=\033[35m
CYAN=\033[36m
WHITE=\033[37m
BOLDBLACK=\033[1m\033[30m
BOLDRED=\033[1m\033[31m
BOLDWHITE=\033[1m\033[37m

OK = $(GREEN)[OK!]$(RESET)
KO = $(RED)[KO!]$(RESET)

# START RULES

all:
	@$(CC) -c $(SRCDIR)
	@mkdir -p $(OBJDIR) && mv $(SRC:.c=.o) ./$(OBJDIR)/
	@echo "$(RED)Building $(WHITE)...$(EXE)...$(RESET)"
	@$(CC) -o $(EXE) $(OBJ) $(LIBS) $(C_MLX) $(HPATH)
	@echo "$(GREEN)OK!$(RESET)"

clean:
	@echo "$(CYAN)Removal Object folder of $(EXE)$(RESET)"
	@$(RM) $(OBJDIR)

fclean: clean
	@echo "$(CYAN)Removal $(EXE)$(RESET)"
	@$(RM) $(EXE)

re: fclean
	@make all
	@make clean

# Personnal rules
go: re
	@./$(EXE) 42_5

.PHONY: all clean fclean go
