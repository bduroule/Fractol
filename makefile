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

CC = gcc

SRC = srcs/frac_main.c srcs/frac_display.c  \
		 srcs/frac_event.c srcs/frac_thread.c srcs/frac_init.c \
		srcs/frac_fractal.c

OBJ = $(SRC:.c=.o)

INC_HDR = -I./include -I./libft/include -I./minilibx_macos

INC_LIB = -L./libft -lft -L./minilibx_macos -lmlx \
		  -framework OpenGL -framework AppKit

CFLAGS = -Werror -Wextra -Wall $(INC_HDR) -ggdb

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@$(MAKE) -C minilibx_macos
	@printf "\033[33m$(NAME)\033[0m\t\t\t\t\t\t\t\t[\033[92mCOMPILED\033[39m]\n"
	@$(CC) $(CFLAGS) $(INC_LIB) $(SRC) -o $(NAME)

%.o: %.c include/fractol.h include/struct.h
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@cd libft && $(MAKE) clean

fclean: clean
	@rm -f $(NAME)
	@cd libft && $(MAKE) fclean

re: fclean all
