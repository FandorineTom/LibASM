# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snorthmo <snorthmo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 13:31:28 by snorthmo          #+#    #+#              #
#    Updated: 2020/11/02 13:48:41 by snorthmo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS = ft_strlen.s\
		ft_strcpy.s\
		ft_strcmp.s\
		ft_write.s\
		ft_read.s

OBJS = $(SRCS:.s=.o)

OBJDIR = ./objects/

OBJ = $(addprefix $(OBJDIR), $(OBJS))

CFLAGS = -Wall -Wextra -Werror
ASM_FLAGS = -fmacho64

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJDIR)%.o: %.s
	@test -d $(OBJDIR) || mkdir $(OBJDIR)
	nasm $(ASM_FLAGS) $< -o $@

test:
	gcc $(CFLAGS) main.c $(NAME) -L. -lasm

test_clean:
	/bin/rm -f a.out

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -rf $(OBJDIR)
	/bin/rm -f test_file.txt
	/bin/rm -f wrong_file.txt

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f a.out 

re: fclean all

.PHONY: all clean fclean re test_clean
