# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jadonvez <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/01/07 12:27:42 by jadonvez     #+#   ##    ##    #+#        #
#    Updated: 2019/01/14 16:59:52 by jadonvez    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fractol

#Color
BLUE 	= \033[2K\r\033[36m
GREEN 	= \e[92m
WITHE 	= \033[37m
YELLOW	= \033[33m
END 	= \033[0m

#Dir
OBJ_PATH = ./obj/
SRC_PATH = ./srcs/
INC_PATH = ./include/

#file
SRC_NAME = 	frac_main.c frac_display.c  \
			frac_event.c frac_thread.c frac_init.c \
			frac_fractal.c frac_error.c

# mlx library
MLX        = ./miniLibx_macos/
MLX_LIB    = $(addprefix $(MLX),mlx.a)
MLX_INC    = -I ./miniLibx_macos
MLX_LNK    = -L ./miniLibx_macos -l mlx -framework OpenGL -framework AppKit

# ft library
FT        = ./libft/
FT_LIB    = $(addprefix $(FT),libft.a)
FT_INC    = -I ./libft
FT_LNK    = -L ./libft -l ft

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ	= $(addprefix $(OBJ_PATH), $(SRC_NAME:.c=.o))

#compil
CC = gcc
CFLAGS = -Werror -Wextra -Wall $(INC_HDR) -ggdb -O3

all: $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c include/fractol.h include/struct.h | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(FT_INC) $(MLX_INC) -I $(INC_PATH)  -o $@ -c $<
	@printf "$(BLUE)>>Compiling $(WITHE) $< $(END)"

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@$(MAKE) -C minilibx_macos
	@$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -o $(NAME)
	@printf "$(YELLOW)$(NAME)$(END)		$(GREEN)[compiled]$(END)\n"


clean:
	@rm -rf $(OBJ_PATH)
	@cd libft && $(MAKE) clean
	@cd miniLibx_macos && $(MAKE) clean

fclean: clean
	@rm -f $(NAME)
	@cd libft && $(MAKE) fclean
	@cd miniLibx_macos && $(MAKE) fclean

re: fclean all
