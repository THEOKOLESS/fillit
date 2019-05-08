# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amartino <amartino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/20 11:34:23 by amartino          #+#    #+#              #
#    Updated: 2019/05/08 16:15:20 by amartino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB_DIR = libft

LIB = libft.a

LIB_PATH = $(LIB_DIR)/$(LIB)

SRC = ft_fillit ft_checks ft_get_pieces main ft_tools ft_solve

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FFLAG =  -Wall -Wextra -Werror -fsanitize=address,undefined -g3

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

OBJ = $(patsubst %, %.o, $(SRC))

INCLUDES = -I.

HEAD = ./fillit.h

T ?= sample

VAL ?= no

REQUEST = 'read -p "Enter a commit message:" pwd; echo $$pwd'

COMMIT_MESSAGE ?= $(shell bash -c $(REQUEST))

all: $(NAME)

$(NAME): $(OBJ) libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB_PATH)
	@echo "\n$(CYAN)MAKE COMPLETE$(END)"

%.o: %.c $(HEAD)
	@$(CC) $(CFLAGS) -c $< $(INCLUDES)
	@echo "$(CFLAGS) \t\t $(GREEN)$<$(END)"

libft: FORCE
	@echo  "\n$(CYAN)Makefile libft$(END)\n"
	@make -C $(LIB_DIR)

t: all $(VAL)
	$(VALGRIND) ./fillit examples/$(T).fillit

clean:
	@rm -f $(OBJ)
	@echo "$(YELLOW)OBJ$(END) \t\t were \t\t $(GREEN)clean$(END)\n"
	@$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	@rm -rf $(NAME)
	@echo "$(YELLOW)$(NAME)$(END) \t\t were \t\t $(GREEN)clean$(END)\n"
	@$(MAKE) fclean -C $(LIB_DIR)

re: fclean all

.PHONY: clean fclean all re libft t FORCE git

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
else ifeq ($(f), f)
CFLAGS = $(FFLAG)
endif

$(VAL):
ifeq ($(VAL), no)
VALGRIND =
else
CFLAGS += -g
SHOW_LEAK = --show-leak-kinds=definite
VALGRIND = valgrind --track-origins=yes --leak-check=full $(SHOW_LEAK)
endif
                             #####################
                             #                   #
                             #        GIT        #
                             #                   #
                             #####################
git:
	@git add -f -A
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
