# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 22:01:15 by alopez-g          #+#    #+#              #
#    Updated: 2022/08/08 15:35:06 by alopez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED			= \033[0;31m
CYAN			= \033[0;36m
GREEN 			= \033[1;32m
YELLOW 			= \033[1;33m
NC 			= \033[0m

DIR 			= .
NAME 			= fract-ol

#---------- LIBS ---------------------------------------------------------------
	#---------- FTPF -----------------------------------------------------------
M_FTPF 			= $(FTPF_DIR)/Makefile

FTPF_LIB		= ftprintf
FTPF_DIR 		= $(DIR)/src/ft_printf
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

	#---------- MLX ------------------------------------------------------------
M_MLX_DIR 		= $(MLX_DIR)/Makefile

MLX_LIB			= mlx
MLX_DIR 		= $(SRC_DIR)/mlx

I_MLX 			= $(MLX_DIR)/includes
I_MLX_H		 	= $(wildcard $(I_MLX)/*.h)
#---------- fract-ol -----------------------------------------------------------
#---------- INCLUDES ----------
I_DIR 			= $(DIR)/includes
I_H 			= error.h fractol.h ft_math.h hooks.h keycodes.h \
			  parser.h shade.h temp.h utils.h
I 			= $(patsubst %.h, $(I_DIR)/%.h, $(I_H)) \
			  $(I_FTPF_H) $(I_LIBFT_H)

#---------- SRC ----------
SRC_DIR 		= $(DIR)/src
SRC_PARSER 		= $(SRC_DIR)/parser
#SRC_2 			= $(SRC_DIR)/instr
SRC_PARSER_C 		= parser.c c_parser.c d_parser.c e_parser.c f_parser.c \
			  n_parser.c ri_parser.c z_parser.c type_parser.c
#SRC_2_C 		= exec.c s.c p.c r.c rr.c 
SRC_FRACTOL_C 		= main.c fractal.c math.c setup.c hooks.c fill_color.c shade.c
SRC 			= $(patsubst %.c, $(SRC_DIR)/%.c, $(SRC_FRACTOL_C)) \
				$(patsubst %.c, $(SRC_1)/%.c, $(SRC_1_C)) \
				$(patsubst %.c, $(SRC_2)/%.c, $(SRC_2_C)) 
#---------- OBJ ----------
BUILD_DIR 		= $(SRC_DIR)/build

OBJ_PS 			= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, \
		 		$(patsubst %.c, $(SRC_DIR)/%.c, $(SRC_FRACTOL_C)))
OBJ_INSTR 		= $(patsubst $(SRC_2)/%.c, $(BUILD_DIR)/%.o, \
				$(patsubst %.c, $(SRC_2)/%.c, $(SRC_2_C)))
OBJ_COLOR 		= $(patsubst $(SRC_PARSER)/%.c, $(BUILD_DIR)/%.o, \
				$(patsubst %.c, $(SRC_PARSER)/%.c, $(SRC_PARSER_C)))
OBJ 			= $(OBJ_PS) $(OBJ_INSTR) $(OBJ_COLOR)

#---------- FLAGS ----------
CC 			= gcc
FLAGS 			= -Wall -Wextra -Werror
I_FLAG 			= -I $(I_DIR)/ -I $(I_FTPF)/ -I $(I_LIBFT)/ -I $(I_MLX)/
MLX_FLAGS		= -framework OpenGL -framework AppKit

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
			@echo "$(RED)Compiling MLX$(NC)\c"
			@make -s -C $(MLX_DIR)
			@echo " ---> ${CYAN}Success${NC}"
			@$(CC) $(FLAGS) $(MLX_FLAGS) $(OBJ) \
				-L$(FTPF_DIR) -l$(FTPF_LIB) \
				-L$(MLX_DIR) -l$(MLX_LIB) -o $(NAME)
			@echo "${GREEN}${NAME} READY!${NC}"
clean:
			@make -s -C $(FTPF_DIR) clean
			@make -s -C $(MLX_DIR) clean
			@rm -rf $(BUILD_DIR)/*
			@echo "${YELLOW}OBJS Removed!${NC}"
fclean: clean
			@make -s -C $(FTPF_DIR) fclean
			@make -s -C $(MLX_DIR) fclean
			@rm -rf $(NAME)
			@echo "${YELLOW}$(NAME) Removed!${NC}"
re: fclean $(NAME)

debug: FLAGS = -g -D DEBUG
debug: re

.PHONY: clean fclean re
