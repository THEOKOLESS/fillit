# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amartino <amartino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/20 11:34:23 by amartino          #+#    #+#              #
#    Updated: 2019/03/13 19:41:50 by amartino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = Libft/libft.a

SRC = ft_fillit ft_checks ft_get_pieces main ft_tools ft_get_coordinate\
ft_solve

CC = gcc

CFLAGS = -Wall -Wextra -Werror

DFLAGS = -Wall -Wextra -Werror -fsanitize=address,undefined -g3 -pedantic\
		 -ansi -O2 -Wchar-subscripts -Wformat=2 -Wimplicit-int\
		 -Werror-implicit-function-declaration -Wmain -Wparentheses\
		 -Wsequence-point -Wreturn-type -Wswitch -Wtrigraphs -Wunused\
		 -Wuninitialized -Wunknown-pragmas -Wfloat-equal -Wundef -Wshadow\
		 -Wpointer-arith -Wbad-function-cast -Wwrite-strings \
		 -Wsign-compare -Waggregate-return -Wstrict-prototypes\
		 -Wmissing-declarations -Wmissing-noreturn\
		 -Wformat -Wmissing-format-attribute -Wno-deprecated-declarations\
		 -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long\
		 -Wunreachable-code

DEPS = fillit.h

OBJ = $(patsubst %, %.o, $(SRC))

T ?= sample

VAL ?= NO

FLAG ?= CFLAGS

all: $(NAME)

#il faudrait que le make se fasse seulement s'il y a des trucs a faire
make_libft:
	@cd Libft && $(MAKE)
	@echo  "$(CYAN)makefile libft$(END)"

$(NAME): $(OBJ) make_libft
	$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo "$(GREEN)MAKE COMPLETE$(END)"

t: re $(VAL)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re

                             #####################
                             #                   #
                             #       IFEQ        #
                             #                   #
                             #####################

$(OBJ):
ifeq ($(FLAG), CFLAGS)
	$(CC) -g $(CFLAGS) -c $(patsubst %, %.c, $(SRC))
else ifeq ($(FLAG), NO)
	$(CC) -g -c $(patsubst %, %.c, $(SRC))
else
	$(CC) -g $(DFLAGS) -c $(patsubst %, %.c, $(SRC))
endif

$(VAL):
ifeq ($(VAL), NO)
	./fillit examples/$(T).fillit
else
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=definite ./fillit examples/$(T).fillit
endif
#                            #####################
                             #                   #
                             #        GIT        #
                             #                   #
                             #####################

COMMIT_MESSAGE ?= $(shell bash -c \
				  'read -p "Enter a commit message:" pwd; echo $$pwd')

git:
	@git add -f *
	@git commit -m "$(COMMIT_MESSAGE)"
	@git push

#                            #####################
                             #                   #
                             #       COLOR       #
                             #                   #
                             #####################

RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
MAGENTA = \x1b[35m
CYAN = \x1b[36m
END = \x1b[0m


#ifneq (,$(findstring i,$(MAKEFLAGS)))
