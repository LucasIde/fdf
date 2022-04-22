# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lide <lide@student.s19.be>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 18:11:55 by lide              #+#    #+#              #
#    Updated: 2022/04/22 08:30:36 by lide             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	test2.c\
				dr_line.c\
				utils.c

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
