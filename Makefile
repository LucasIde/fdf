# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lide <lide@student.s19.be>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 18:11:55 by lide              #+#    #+#              #
#    Updated: 2022/05/24 18:26:17 by lide             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	fdf_file/color_handler.c\
				fdf_file/dr_line.c\
				fdf_file/draw_map.c\
				fdf_file/fdf.c\
				fdf_file/free.c\
				fdf_file/free2.c\
				fdf_file/ft_copy.c\
				fdf_file/help_display.c\
				fdf_file/isometric_view.c\
				fdf_file/key_move.c\
				fdf_file/key_move2.c\
				fdf_file/key_press.c\
				fdf_file/parallel_view.c\
				fdf_file/parcing_map.c\
				fdf_file/split.c\
				fdf_file/utils_color.c\
				fdf_file/utils_dr_line.c\
				fdf_file/utils_draw_map.c\
				fdf_file/utils_libx.c\
				fdf_file/utils_list.c\
				fdf_file/utils_mountain.c\
				fdf_file/utils_rainbow.c\
				fdf_file/utils.c\
				fdf_file/utils2.c\
				get_next_line/get_next_line.c\
				get_next_line/get_next_line_utils.c

NAME		= fdf.a
EXEC		= fdf
OBJS		= ${SRCS:.c=.o}
CC			= @gcc
.c.o:
		@gcc -Wall -Wextra -Werror -c -I./ $< -o ${<:.c=.o}

all : ${NAME}

${NAME}: ${OBJS}
		@ar -rc ${NAME} ${OBJS}
		$(CC) -lmlx -framework OpenGL -framework AppKit ${NAME}
		@mv ./a.out ${EXEC}
		@echo "fdf created"

clean :
			@rm -f ${OBJS}
			@echo "Clean Executed"

fclean:
			@rm -f ${OBJS} ${NAME} ${EXEC}
			@echo "Fclean Executed"

re: fclean all

.phony: all clean fclean re
