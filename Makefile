# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amartino <amartino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/20 11:34:23 by amartino          #+#    #+#              #
#    Updated: 2019/03/16 01:29:38 by amartino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = Libft/libft.a

SRC = ft_fillit ft_checks ft_get_pieces main ft_tools ft_get_coordinate\
ft_solve

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

DFLAGS = -g -Wall -Wextra -Werror -fsanitize=address,undefined -g3 -pedantic\
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

OBJ = $(patsubst %, %.o, $(SRC))

INCLUDES = -I.

HEAD = ./fillit.h

T ?= sample

VAL ?= no

COMMIT_MESSAGE ?= $(shell bash -c \
				  'read -p "Enter a commit message:" pwd; echo $$pwd')

all: $(NAME)

$(NAME): $(OBJ) libft
	@$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo "\n$(CYAN)MAKE COMPLETE$(END)"

%.o: %.c $(HEAD)
	@$(CC) $(CFLAGS) -c $< $(INCLUDES)
	@echo "$(CFLAGS) \t\t $(GREEN)$<$(END)"

libft: FORCE
	@echo  "\n$(CYAN)Makefile libft$(END)\n"
	@make -C Libft/
#	@cd Libft && $(MAKE)

t: all $(VAL)
	$(VALGRIND) ./fillit examples/$(T).fillit

clean:
	@rm -f $(OBJ)
	@echo "$(YELLOW)OBJ$(END) \t\t were \t\t $(GREEN)clean$(END)\n"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(YELLOW)$(NAME)$(END) \t\t were \t\t $(GREEN)clean$(END)\n"

re: fclean all

.PHONY: clean fclean all re

FORCE:

                             #####################
                             #                   #
                             #       IFEQ        #
                             #                   #
                             #####################
ifeq ($(f), no)
CFLAGS = -g
else ifeq ($(f), d)
CFLAGS = $(DFLAGS)
endif

$(VAL):
ifeq ($(VAL), no)
VALGRIND =
else
VALGRIND = valgrind --track-origins=yes --leak-check=full --show-leak-kinds=definite
endif
                             #####################
                             #                   #
                             #        GIT        #
                             #                   #
                             #####################
git:
	@git add -f *
	@git commit -m "$(COMMIT_MESSAGE)"
	@git push

                             #####################
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
