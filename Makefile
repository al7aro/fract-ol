# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 22:01:15 by alopez-g          #+#    #+#              #
#    Updated: 2022/09/24 14:17:47 by alopez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED				= \033[0;31m
CYAN			= \033[0;36m
GREEN 			= \033[1;32m
YELLOW 			= \033[1;33m
NC 				= \033[0m

DIR 			= .
NAME 			= fract-ol

#---------- LIBS ---------------------------------------------------------------
	#---------- FTPF -----------------------------------------------------------
M_FTPF 			= $(FTPF_DIR)/Makefile

FTPF_LIB		= ftprintf
FTPF_DIR 		= $(DIR)/src/libs/ft_printf
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
MLX_DIR 		= $(SRC_DIR)/libs/mlx
MLX_LIBDIR 		= $(SRC_DIR)/libs/mlx
I_MLX 			= $(MLX_DIR)/includes

I_MLX_H		 	= $(wildcard $(I_MLX)/*.h)
#---------- fract-ol -----------------------------------------------------------
#---------- INCLUDES ----------
I_DIR 			= $(DIR)/includes
I_H 			= fractol.h ft_math.h hooks.h keycodes.h \
				  parser.h render.h shade.h temp.h utils.h 
I 				= $(patsubst %.h, $(I_DIR)/%.h, $(I_H)) \
				  $(I_FTPF_H) $(I_LIBFT_H)

#---------- SRC ----------
SRC_DIR 		= $(DIR)/src
SRC_PARSER 		= $(SRC_DIR)/parser
SRC_MATH 		= $(SRC_DIR)/math
SRC_EVENTS 		= $(SRC_DIR)/events
SRC_COLOR 		= $(SRC_DIR)/color
SRC_RENDER 		= $(SRC_DIR)/render
SRC_FRACTOL_C 	= main.c utils.c setup.c 
SRC_PARSER_C 	= parser.c c_parser.c d_parser.c e_parser.c \
				  n_parser.c ri_parser.c z_parser.c type_parser.c
SRC_MATH_C 		= math.c fractal.c funcs.c 
SRC_EVENTS_C	= hooks.c iter.c menu.c move.c type.c visual.c 
SRC_COLOR_C		= shade.c color_range.c
SRC_RENDER_C	= render_menu.c render.c export.c
SRC 			= $(patsubst %.c, $(SRC_DIR)/%.c, $(SRC_FRACTOL_C)) \
				$(patsubst %.c, $(SRC_PARSER)/%.c, $(SRC_PARSER_C)) \
				$(patsubst %.c, $(SRC_EVENTS)/%.c, $(SRC_EVENTS_C)) \
				$(patsubst %.c, $(SRC_COLOR)/%.c, $(SRC_COLOR_C)) \
				$(patsubst %.c, $(SRC_RENDER)/%.c, $(SRC_RENDER_C)) \
				$(patsubst %.c, $(SRC_MATH)/%.c, $(SRC_MATH_C)) 
#---------- OBJ ----------
BUILD_DIR 		= $(SRC_DIR)/build

OBJ_FO 			= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, \
		 		$(patsubst %.c, $(SRC_DIR)/%.c, $(SRC_FRACTOL_C)))
OBJ_MATH 		= $(patsubst $(SRC_MATH)/%.c, $(BUILD_DIR)/%.o, \
				$(patsubst %.c, $(SRC_MATH)/%.c, $(SRC_MATH_C)))
OBJ_PARSER 		= $(patsubst $(SRC_PARSER)/%.c, $(BUILD_DIR)/%.o, \
				$(patsubst %.c, $(SRC_PARSER)/%.c, $(SRC_PARSER_C)))
OBJ_EVENTS 		= $(patsubst $(SRC_EVENTS)/%.c, $(BUILD_DIR)/%.o, \
				$(patsubst %.c, $(SRC_EVENTS)/%.c, $(SRC_EVENTS_C)))
OBJ_COLOR 		= $(patsubst $(SRC_COLOR)/%.c, $(BUILD_DIR)/%.o, \
				$(patsubst %.c, $(SRC_COLOR)/%.c, $(SRC_COLOR_C)))
OBJ_RENDER 		= $(patsubst $(SRC_RENDER)/%.c, $(BUILD_DIR)/%.o, \
				$(patsubst %.c, $(SRC_RENDER)/%.c, $(SRC_RENDER_C)))
OBJ 			= $(OBJ_FO) $(OBJ_MATH) $(OBJ_PARSER) $(OBJ_EVENTS) \
				  $(OBJ_COLOR) $(OBJ_RENDER)

#---------- FLAGS ----------
CC 				= gcc
FLAGS 			= -Wall -Wextra -Werror
I_FLAG 			= -I $(I_DIR)/ -I $(I_FTPF)/ -I $(I_LIBFT)/ -I $(I_MLX)/
MLX_FLAGS		= -framework OpenGL -framework AppKit

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c
			@$(CC) $(FLAGS) $(I_FLAG) -c $< -o $@
$(BUILD_DIR)/%.o : $(SRC_MATH)/%.c
			@$(CC) $(FLAGS) $(I_FLAG) -c $< -o $@
$(BUILD_DIR)/%.o : $(SRC_PARSER)/%.c
			@$(CC) $(FLAGS) $(I_FLAG) -c $< -o $@
$(BUILD_DIR)/%.o : $(SRC_EVENTS)/%.c
			@$(CC) $(FLAGS) $(I_FLAG) -c $< -o $@
$(BUILD_DIR)/%.o : $(SRC_COLOR)/%.c
			@$(CC) $(FLAGS) $(I_FLAG) -c $< -o $@
$(BUILD_DIR)/%.o : $(SRC_RENDER)/%.c
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
				-L$(MLX_LIBDIR) -l$(MLX_LIB) -o $(NAME)
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

n:
	@norminette $(SRC)
	@norminette $(I)
	@norminette $(FTPF_DIR)
	@norminette $(LIBFT_SRC)
fast: FLAGS += -Ofast -D DEBUG
fast: re 
debug: FLAGS = -g -D DEBUG
debug: re

.PHONY: clean fclean re
