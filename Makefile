# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amartino <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/20 11:34:23 by amartino          #+#    #+#              #
#    Updated: 2019/02/20 17:30:30 by amartino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = Libft/libft.a

SRC = ft_fillit ft_checks ft_get_pieces main

CC = gcc

CFLAGS = -Wall -Wextra -Werror

DFLAGS = -Wall -Wextra -Werror -fsanitize=address,undefined -g3 -pedantic\
		 -O2 -Wchar-subscripts -Wcomment -Wformat=2 -Wimplicit-int -Werror\
		 -implicit-function-declaration -Wmain -Wparentheses -Wsequence-point\
		 -Wreturn-type -Wswitch -Wtrigraphs -Wunused -Wuninitialized\
		 -Wunknown-pragmas -Wfloat -equal -Wundef -Wshadow -Wpointer-arith\
		 -Wbad-function-cast -Wwrite -strings -Wconversion -Wsign-compare\
		 -Waggregate -return -Wstrict-prototypes -Wmissing-prototypes\
		 -Wmissing-declarations -Wmissing-noreturn -Wformat -Wmissing -format\
		 -attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls\
		 -Wnested-externs -Winline -Wlong-long -Wunreachable-code\

DEPS = fillit.h

OBJ = $(patsubst %, %.o, $(SRC))

all: $(NAME) clean

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $^ $(LIB)

$(OBJ):
	$(CC) $(CFLAGS) -c $(patsubst %, %.c, $(SRC))

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
