# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/20 18:57:57 by emartin-          #+#    #+#              #
#    Updated: 2020/08/11 19:49:15 by emartin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_strlen.s
OBJS		= $(SRCS:.s=.o)
NA			= nasm
NA_FLAGS	= -f macho64
FLAGS		= -Wall -Werror -Wextra
NAME		= libasm.a
TEST		= TEST

%.o:	%.s
			$(NA) $(NA_FLAGS) $<

all:	$(NAME)

$(NAME):	$(OBJS)
		ar rcs $(NAME) $(OBJS)
clean:
		rm -rf $(OBJS)
fclean:		clean
		rm -rf $(NAME) $(TEST)
re:			fclean $(NAME)

test:	$(NAME)
			gcc $(FLAGS) -L. -lasm -o $(TEST) main.c
			./$(TEST) < Makefile

.PHONY:		clean fclean re test	