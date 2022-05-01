# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lide <lide@student.s19.be>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 18:11:55 by lide              #+#    #+#              #
#    Updated: 2022/05/01 18:54:47 by lide             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	fdf_file/fdf.c\
				fdf_file/free.c\
				fdf_file/utils.c\
				fdf_file/utils2.c\
				fdf_file/utils_list.c\
				fdf_file/utils_libx.c\
				fdf_file/split.c\
				get_next_line/get_next_line.c\
				get_next_line/get_next_line_utils.c
				# fdf_file/dr_line.c

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
