# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/13 10:33:44 by nalysann          #+#    #+#              #
#    Updated: 2020/09/13 13:33:56 by nalysann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_DIR = src

SRC = cl_init.c \
      cl_run.c \
      fractol.c \
      hook.c \
      keyboard.c \
      keyboard_utils.c \
      mouse.c \
      mouse_utils.c \
      palette.c \
      utils.c

INC_DIR = include \
          $(FT_DIR)/include \
          $(MLX_DIR)

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

DEP = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.d))

FT_DIR = libft

FT = libft.a

MLX_DIR = libmlx

MLX = libmlx.dylib

UNAME_S = $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
	CC = clang
endif

ifeq ($(UNAME_S), Linux)
	CC = gcc
endif

CFLAGS += $(addprefix -I , $(INC_DIR)) \
          -MD \
          -march=native -O2 -pipe

LDFLAGS += -L $(FT_DIR) -L $(MLX_DIR)

LDLIBS += -lft -lmlx -lm -framework OpenCL

RESET = \033[0;0m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

.PHONY: all clean fclean re

all:
	@printf "$(CYAN)>>> Making $(FT_DIR) <<<\n$(RESET)"
	@$(MAKE) -C $(FT_DIR)
	@printf "$(CYAN)>>> Making $(MLX_DIR) <<<\n$(RESET)"
	@$(MAKE) -C $(MLX_DIR)
	@cp $(MLX_DIR)/$(MLX) .
	@printf "$(CYAN)>>> Making $(NAME) <<<\n$(RESET)"
	@$(MAKE) $(NAME)


$(NAME): $(OBJ) $(FT_DIR)/$(FT) $(MLX_DIR)/$(MLX)
	@printf "$(GREEN)"
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $@
	@printf "$(RESET)"

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@printf "$(MAGENTA)"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(RESET)"

include $(wildcard $(DEP))

clean:
	@printf "$(CYAN)>>> Cleaning $(FT_DIR) <<<\n$(RESET)"
	@$(MAKE) -C $(FT_DIR) clean
	@printf "$(CYAN)>>> Cleaning $(MLX_DIR) <<<\n$(RESET)"
	@$(MAKE) -C $(MLX_DIR) clean
	@printf "$(CYAN)>>> Cleaning $(NAME) <<<\n$(RESET)"
	@printf "$(RED)"
	rm -rf $(OBJ_DIR)
	@printf "$(RESET)"

fclean: clean
	@printf "$(CYAN)>>> Purging $(FT_DIR) <<<\n$(RESET)"
	@$(MAKE) -C $(FT_DIR) fclean
	@printf "$(CYAN)>>> Purging $(MLX_DIR) <<<\n$(RESET)"
	@$(MAKE) -C $(MLX_DIR) fclean
	@rm -f $(MLX)
	@printf "$(CYAN)>>> Purging $(NAME) <<<\n$(RESET)"
	@printf "$(RED)"
	rm -f $(NAME)
	@printf "$(RESET)"

re: fclean all
