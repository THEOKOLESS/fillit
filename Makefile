# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amartino <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/20 11:34:23 by amartino          #+#    #+#              #
#    Updated: 2019/02/23 16:21:12 by amartino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = Libft/libft.a

SRC = ft_fillit ft_checks ft_get_pieces main

CC = gcc

CFLAGS = -Wall -Wextra -Werror

DFLAGS = -Wall -Wextra -Werror -fsanitize=address,undefined -g3 -pedantic\
		 -ansi -O2 -Wchar-subscripts -Wcomment -Wformat=2 -Wimplicit-int\
		 -Werror-implicit-function-declaration -Wmain -Wparentheses\
		 -Wsequence-point -Wreturn-type -Wswitch -Wtrigraphs -Wunused\
		 -Wuninitialized -Wunknown-pragmas -Wfloat-equal -Wundef -Wshadow\
		 -Wpointer-arith -Wbad-function-cast -Wwrite-strings -Wconversion\
		 -Wsign-compare -Waggregate-return -Wstrict-prototypes\
		 -Wmissing-prototypes -Wmissing-declarations -Wmissing-noreturn\
		 -Wformat -Wmissing-format-attribute -Wno-deprecated-declarations\
		 -Wpacked -Wredundant-decls -Wnested-externs -Winline -Wlong-long\
		 -Wunreachable-code

DEPS = fillit.h

OBJ = $(patsubst %, %.o, $(SRC))

FLAG?= NO

all: $(NAME)

#il faudrait que le make se fasse seulement s'il y a des trucs a faire 
subsystem:
	@cd Libft && $(MAKE)
	@echo  "$(CYAN)makefile libft$(END)"

$(NAME): $(OBJ) subsystem
	$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo "$(GREEN)MAKE COMPLETE$(END)"

$(OBJ):
ifeq ($(FLAG),NO)
	$(CC) $(CFLAGS) -c $(patsubst %, %.c, $(SRC))
else
	$(CC) $(DFLAGS) -c $(patsubst %, %.c, $(SRC))
endif

.PHONY: clean fclean all re

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all


                      #####################
                      #                   #
                      #       GITHUB      #
                      #                   #
                      #####################

COMMIT = $(COMMIT_MESSAGE)

COMMIT_MESSAGE ?= $(shell bash -c \
				  'read -p "Enter a commit message:" pwd; echo $$pwd')

git:
	@git add *
	@git commit -m "$(COMMIT)"
	@git push
	@echo "just re-use your commit message : $(COMMIT)"

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


#ifneq (,$(findstring i,$(MAKEFLAGS)))
