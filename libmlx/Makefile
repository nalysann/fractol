# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/13 15:58:30 by nalysann          #+#    #+#              #
#    Updated: 2020/09/13 16:05:43 by nalysann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmlx.dylib

MODULE_SRC = mlx_image.swift mlx_window.swift mlx_init.swift
MODULE_OBJ = $(MODULE_SRC:.swift=.swiftmodule)

SRC = interface.swift $(MODULE_SRC)
OBJ = $(SRC:.swift=.o)

C_SRC = mlx_xpm.c mlx_png.c mlx_string_put.c
C_OBJ = $(C_SRC:.c=.o)

CFLAGS += -march=native -O2 -pipe

INC = -I .
OPTI = -Ounchecked

UNAME_S = $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
	CC = clang
endif

ifeq ($(UNAME_S), Linux)
	CC = gcc
endif

RESET = \033[0;0m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(MODULE_OBJ) $(OBJ) $(C_OBJ)
	@printf "$(BLUE)"
	swiftc $(OPTI) $(INC) -o $@ -emit-library $(OBJ) $(C_OBJ) -lz
	@printf "$(RESET)"

%.o: %.swift
	@printf "$(MAGENTA)"
	swiftc $(OPTI) $(INC) -parse-as-library -c $< -o $@

%.swiftmodule: %.swift
	@printf "$(MAGENTA)"
	swiftc $(OPTI) $(INC) -parse-as-library -c $< -o $@ -emit-module -module-name $(patsubst %.swift,%,$<) -module-link-name $(patsubst %.swift,%,$<)
	@printf "$(RESET)"

clean:
	@printf "$(RED)"
	rm -f $(OBJ) $(MODULE_OBJ) $(C_OBJ) *~
	@printf "$(RESET)"

fclean: clean
	@printf "$(RED)"
	rm -f $(NAME) *.swiftdoc
	@printf "$(RESET)"

re: fclean all
