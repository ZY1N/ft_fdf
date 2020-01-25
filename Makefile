# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/24 14:42:36 by yinzhang          #+#    #+#              #
#    Updated: 2020/01/24 14:42:37 by yinzhang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_fdf

CFLAGS = -Wall -Werror -Wextra

INCLUDE = fdf.h

FILES = main.c draw_line.c helper.c keys_1.c keys_2.c matrix.c render.c get_next_line.c

LIBFTDIR = libft/

LIBFTSRC = libft/libft.a

MINILIBX = ./minilibx_macos/

OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME):
	@make re -C $(LIBFTDIR)
	@gcc $(CFLAGS) -L $(MINILIBX) -I $(MINILIBX) -lmlx -framework OpenGL -framework AppKit $(FILES) $(LIBFTSRC) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFTDIR)

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@make fclean -C $(LIBFTDIR)

re: fclean all