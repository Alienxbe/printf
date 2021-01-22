# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mykman <mykman@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 09:08:58 by mykman            #+#    #+#              #
#    Updated: 2021/01/22 13:51:10 by mykman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c \
			pft_conversion.c \
			pft_type.c \
			pft_type_c.c \
			pft_type_s.c \
			pft_type_d.c \
			pft_type_u_base.c \
			pft_type_pct.c \
			pft_type_p.c

OBJS	=	$(addprefix srcs/, ${SRCS:.c=.o})

NAME	=	libftprintf.a
LIBFT	=	./libft

CC		=	@gcc
CFLAGS	=	-Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c -I./ $< -o ${<:.c=.o}
	@echo "[${NAME}]\t\tCompilation of $<..."

${NAME}:	${OBJS}
	@make NAME=../${NAME} -C ${LIBFT}
	@ar -rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
	@rm -rf ${OBJS}
	@make clean -C ${LIBFT}

fclean:	clean
	@rm -rf ${NAME}
	@make fclean -C ${LIBFT}

re:		fclean all

.PHONY:	all clean fclean re