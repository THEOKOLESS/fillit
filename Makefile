# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amartino <amartino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/20 11:34:23 by amartino          #+#    #+#              #
#    Updated: 2019/05/07 17:58:56 by amartino         ###   ########.fr        #
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

teste : all $(VAL)
		$(VALGRIND) ./$(NAME) .annex/tests/bad/err0
		$(VALGRIND) ./$(NAME) .annex/tests/bad/err1
		$(VALGRIND) ./$(NAME) .annex/tests/bad/err2
		$(VALGRIND) ./$(NAME) .annex/tests/bad/err3
		$(VALGRIND) ./$(NAME) .annex/tests/bad/err4
		$(VALGRIND) ./$(NAME) .annex/tests/bad/err5
		$(VALGRIND) ./$(NAME) .annex/tests/bad/err6
		$(VALGRIND) ./$(NAME) .annex/tests/bad/err7
		# $(VALGRIND) ./$(NAME)
		# $(VALGRIND) ./$(NAME) ./.annex/test lol
		# $(VALGRIND) ./$(NAME) ./.annex
		# $(VALGRIND) ./$(NAME) ./examples/bad/otherTest/binary1.txt
		# $(VALGRIND) ./$(NAME) ./examples/bad/otherTest/binary2.txt
		# $(VALGRIND) ./$(NAME) ./examples/bad/otherTest/binary3.txt
		# $(VALGRIND) ./$(NAME) ./examples/bad/otherTest/eof.txt
		# $(VALGRIND) ./$(NAME) ./examples/bad/otherTest/twentyseven.txt
		# $(VALGRIND) ./$(NAME) ./examples/bad/otherTest/twentysix.txt
		# $(VALGRIND) ./$(NAME) ./examples/bad/otherTest/wrongdot1.txt
		# $(VALGRIND) ./$(NAME) ./examples/bad/otherTest/wrongdot2.txt
		# $(VALGRIND) ./$(NAME) ./examples/bad/otherTest/wrongdot3.txt

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
else ifeq ($(f), f)
CFLAGS = $(FFLAG)
endif

$(VAL):
ifeq ($(VAL), no)
VALGRIND =
else
#CFLAGS += -g
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
