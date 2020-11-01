# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snorthmo <snorthmo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 13:31:28 by snorthmo          #+#    #+#              #
#    Updated: 2020/11/01 22:26:22 by snorthmo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS = ft_strlen.s\
		ft_strcpy.s\
		ft_strcmp.s

OBJS = $(SRCS:.s=.o)

CFLAGS = -Wall -Wextra -Werror
ASM_FLAGS = -fmacho64

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.s
	nasm $(ASM_FLAGS) $< -o $@

test:
	gcc $(CFLAGS) main.c $(NAME) -L. -lasm

test_clean:
	/bin/rm -f a.out

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f a.out 

re: fclean all

.PHONY: all clean fclean re test_clean
