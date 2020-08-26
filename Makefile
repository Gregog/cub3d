# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/24 18:03:21 by rvernius          #+#    #+#              #
#    Updated: 2020/08/26 19:23:14 by rvernius         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c check_argc.c parse.c parse_utils.c parce_line.c parce_map.c

NAME = cub3d

FLAGS = -lmlx -framework OpenGL -framework AppKit

MLX	= libmlx.dylib

LIBFT = libft.a

all:			$(NAME)

$(NAME):		$(LIBFT) $(OBJS)
				gcc ${FLAGS} -o ${NAME} ${SRCS} $(LIBFT)


#$(MLX):
#				@$(MAKE) -C mlx
#				@mv mlx/$(MLX) .

$(LIBFT):
				@$(MAKE) -C libft
				@mv libft/$(LIBFT) .


clean:
				@$(MAKE) -C libft clean

fclean:			clean
				$(RM) $(NAME) $(LIBFT)

re:				fclean $(NAME)