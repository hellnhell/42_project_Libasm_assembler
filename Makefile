# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 16:34:43 by emartin-          #+#    #+#              #
#    Updated: 2020/08/26 19:04:27 by emartin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   libasm.a

SRCS    =   ft_strlen.s		\
            ft_strcpy.s		\
            ft_strcmp.s		\
            ft_strdup.s		\
            ft_read.s		\
            ft_write.s
            
OBJS    =   $(SRCS:.s=.o)
NASM    =   nasm -fmacho64
CFLAGS  =   -Wall -Werror -Wextra
RUN     =   && ./a.out

%.o : %.s
			@$(NASM) $<
            
all     :   $(NAME)
$(NAME) :   $(OBJS)
			@ar rcs $(NAME) $(OBJS)
            
clean   :
			@rm -rf $(OBJS)
            
fclean  :   clean
			@rm -rf $(NAME) main.o
            
re		:   fclean $(NAME)

test	:   main.c  $(NAME) clean
			@clear
			@gcc $(CFLAGS) $< $(NAME) $(RUN)
			@rm -rf $(NAME) a.out
        
.PHONY  :   clean fclean re test