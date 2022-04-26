# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lide <lide@student.s19.be>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 18:11:55 by lide              #+#    #+#              #
#    Updated: 2022/04/26 18:38:55 by lide             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	fdf_file/fdf.c\
				fdf_file/dr_line.c\
				fdf_file/utils.c\
				fdf_file/split.c\
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
