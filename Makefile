# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lide <lide@student.s19.be>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 18:11:55 by lide              #+#    #+#              #
#    Updated: 2022/05/26 16:43:55 by lide             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_BONUS	=	bonus/fdf_file/color_handler.c\
				bonus/fdf_file/dr_line.c\
				bonus/fdf_file/draw_map.c\
				bonus/fdf_file/fdf.c\
				bonus/fdf_file/free.c\
				bonus/fdf_file/free2.c\
				bonus/fdf_file/ft_copy.c\
				bonus/fdf_file/help_display.c\
				bonus/fdf_file/isometric_view.c\
				bonus/fdf_file/key_move.c\
				bonus/fdf_file/key_move2.c\
				bonus/fdf_file/key_press.c\
				bonus/fdf_file/parallel_view.c\
				bonus/fdf_file/parcing_map.c\
				bonus/fdf_file/split.c\
				bonus/fdf_file/utils_color.c\
				bonus/fdf_file/utils_dr_line.c\
				bonus/fdf_file/utils_draw_map.c\
				bonus/fdf_file/utils_libx.c\
				bonus/fdf_file/utils_list.c\
				bonus/fdf_file/utils_mountain.c\
				bonus/fdf_file/utils_rainbow.c\
				bonus/fdf_file/utils.c\
				bonus/fdf_file/utils2.c\
				get_next_line/get_next_line.c\
				get_next_line/get_next_line_utils.c

SRCS		=	mandatory/fdf_file/color_handler.c\
				mandatory/fdf_file/dr_line.c\
				mandatory/fdf_file/draw_map.c\
				mandatory/fdf_file/fdf.c\
				mandatory/fdf_file/free.c\
				mandatory/fdf_file/free2.c\
				mandatory/fdf_file/ft_copy.c\
				mandatory/fdf_file/isometric_view.c\
				mandatory/fdf_file/key_press.c\
				mandatory/fdf_file/parcing_map.c\
				mandatory/fdf_file/split.c\
				mandatory/fdf_file/utils_color.c\
				mandatory/fdf_file/utils_dr_line.c\
				mandatory/fdf_file/utils_libx.c\
				mandatory/fdf_file/utils_list.c\
				mandatory/fdf_file/utils.c\
				mandatory/fdf_file/utils2.c\
				get_next_line/get_next_line.c\
				get_next_line/get_next_line_utils.c

NAME		= fdf.a
NAME_BONUS	= fdf_bonus.a
EXEC		= fdf
EXEC_BONUS	= fdf_bonus
OBJS		= ${SRCS:.c=.o}
OBJS_BONUS	= ${SRCS_BONUS:.c=.o}
CC			= @gcc
.c.o:
		@gcc -Wall -Wextra -Werror -c -I./ $< -o ${<:.c=.o}

all : ${NAME}

${NAME}: ${OBJS}
		@ar -rc ${NAME} ${OBJS}
		$(CC) -lmlx -framework OpenGL -framework AppKit ${NAME}
		@mv ./a.out ${EXEC}
		@echo "fdf created"

${NAME_BONUS}: ${OBJS_BONUS}
		@ar -rc ${NAME_BONUS} ${OBJS_BONUS}
		$(CC) -lmlx -framework OpenGL -framework AppKit ${NAME_BONUS}
		@mv ./a.out ${EXEC_BONUS}
		@echo "fdf_bonus created"

bonus:	${NAME_BONUS}

clean:
			@rm -f ${OBJS}
			@rm -f ${OBJS_BONUS}
			@echo "Clean Executed"

fclean:
			@rm -f ${OBJS} ${NAME} ${EXEC}
			@rm -f ${OBJS_BONUS} ${NAME_BONUS} ${EXEC_BONUS}
			@echo "Fclean Executed"

re: fclean all

.phony: all clean fclean re bonus
