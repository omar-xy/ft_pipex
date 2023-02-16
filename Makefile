# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 15:33:52 by otaraki           #+#    #+#              #
#    Updated: 2023/02/16 17:30:06 by otaraki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT =	libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

INC = pipex.h \

SRC = \
	parsin.c\
	pipex.c\
	errors.c

OBJ = $(SRC:.c=.o)

m = "MakeFileAutoPush"

all: $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	$(CC) $(OBJ) -o $(NAME) $(LIBFT)

%.o : %.c pipex.h
	@${CC} ${CFLAGS} -c -o $@ $<
	@printf "[compiling %-30s] \r"  ${notdir $@}

clean:
	make clean -C libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

git :
	git add .
	git status
	git commit -m "$(m)"
	git push 

.SILENT: $(NAME) git re fclean clean
.PHONY: all clean fclean re