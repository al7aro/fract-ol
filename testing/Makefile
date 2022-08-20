# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 22:01:15 by alopez-g          #+#    #+#              #
#    Updated: 2022/08/20 20:36:20 by alopez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED			= \033[0;31m
CYAN			= \033[0;36m
GREEN 			= \033[1;32m
YELLOW 			= \033[1;33m
NC 			= \033[0m

DIR 			= .
NAME 			= test

#---------- LIBS ---------------------------------------------------------------
	#---------- FTPF -----------------------------------------------------------
M_FTPF 			= $(FTPF_DIR)/Makefile

FTPF_LIB		= ftprintf
FTPF_DIR 		= ../src/ft_printf
FTPF_SRC_DIR 		= $(FTPFT_DIR)/srcs
FTPF_SRC 		= $(wildcard $(FTPF_SRC_DIR)/*.c)
FTPF_A 			= $(FTPF_DIR)/lib$(FTPF_LIB).a

I_FTPF 			= $(FTPF_DIR)/includes
I_FTPF_H 		= $(I_FTPF)/ft_printf.h

	#---------- LIBFT ----------------------------------------------------------
M_LIBFT 		= $(LIBFT_DIR)/Makefile

LIBFT_DIR 		= $(FTPF_DIR)/srcs/Libft
LIBFT_SRC_DIR 		= $(LIBFT_DIR)/srcs
LIBFT_SRC 		= $(wildcard $(LIBFT_SRC_DIR)/*.c)

I_LIBFT 		= $(LIBFT_DIR)/includes
I_LIBFT_H	 	= $(I_LIBFT)/libft.h

#---------- fract-ol -----------------------------------------------------------
#---------- INCLUDES ----------
I_DIR 			= $(DIR)/includes
I_H 			=  
I 			= $(patsubst %.h, $(I_DIR)/%.h, $(I_H)) \
			  $(I_FTPF_H) $(I_LIBFT_H)

#---------- SRC ----------
SRC_DIR 		= ./
SRC_FRACTOL_C 	= ft_ultoa.c
SRC 			= $(patsubst %.c, $(SRC_DIR)/%.c, $(SRC_FRACTOL_C)) \
#---------- OBJ ----------
BUILD_DIR 		= $(SRC_DIR)/build

OBJ_PS 			= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, \
		 		$(patsubst %.c, $(SRC_DIR)/%.c, $(SRC_FRACTOL_C)))
OBJ 			= $(OBJ_PS)

#---------- FLAGS ----------
CC 			= gcc
FLAGS 			= -Wall -Wextra -Werror
I_FLAG 			= -I $(I_DIR)/ -I $(I_FTPF)/ -I $(I_LIBFT)/

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c
			@$(CC) $(FLAGS) $(I_FLAG) -c $< -o $@
$(BUILD_DIR)/%.o : $(SRC_2)/%.c
			@$(CC) $(FLAGS) $(I_FLAG) -c $< -o $@
$(BUILD_DIR)/%.o : $(SRC_PARSER)/%.c
			@$(CC) $(FLAGS) $(I_FLAG) -c $< -o $@
#-------------------------------------------------------------------------------

all: $(NAME)
$(NAME): $(OBJ) $(FTPF_SRC) $(M_FTPF) $(LIBFT_SRC) $(M_LIBFT) $(I)
			@echo "${RED}Compiling LIBFTPRINTF${NC}\c"
			@make -s -C $(FTPF_DIR)
			@echo " ---> ${CYAN}Success${NC}"
			@echo " ---> ${CYAN}Success${NC}"
			@$(CC) $(FLAGS) $(MLX_FLAGS) $(OBJ) \
				-L$(FTPF_DIR) -l$(FTPF_LIB) -o $(NAME)
			@echo "${GREEN}${NAME} READY!${NC}"
clean:
			@make -s -C $(FTPF_DIR) clean
			@rm -rf $(BUILD_DIR)/*
			@echo "${YELLOW}OBJS Removed!${NC}"
fclean: clean
			@make -s -C $(FTPF_DIR) fclean
			@rm -rf $(NAME)
			@echo "${YELLOW}$(NAME) Removed!${NC}"
re: fclean $(NAME)

fast: FLAGS += -Ofast
fast: re 
debug: FLAGS = -g -D DEBUG
debug: re

.PHONY: clean fclean re
