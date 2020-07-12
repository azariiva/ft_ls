# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/11 20:09:44 by blinnea           #+#    #+#              #
#    Updated: 2020/07/12 15:48:56 by blinnea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL=/bin/zsh
# **************************************************************************** #
#                                 COLOURS                                      #
# **************************************************************************** #
DEFAULT =	\033[0m
YELLOW =	\033[1;33m
GREEN =		\033[1;32m
RED =		\033[1;31m
GREENB =	\033[42m

# **************************************************************************** #
#                               COMPILER OPTIONS                               #
# **************************************************************************** #
CC =		gcc
CF =		-Wall -Wextra -Werror

# **************************************************************************** #
#                               ABBREVIATIONS                                  #
# **************************************************************************** #
LFT =		libft

# **************************************************************************** #
#                                 HEADERS                                      #
# **************************************************************************** #
LFT_H =		$(LFT)/include/$(LFT).h
LLS_H =		include/libls.h

ALL_H =		$(LFT_H) $(LLS_H)

# **************************************************************************** #
#                                 FILENAMES                                    #
# **************************************************************************** #
LSFILES =	$(shell find src/libls -name '*.c')
LSOFILES =	$(addprefix obj/, $(LSFILES:src/libls/%.c=%.o))

.PHONY: dir $(LFT) clean fclean all

all: ft_ls
	@echo "\n> $(GREEN)ft_ls was created$(DEFAULT)"

dir:
	@mkdir -p obj

ft_ls: $(LSOFILES) obj/main.o $(LFT)
	@$(CC) $(LSOFILES) obj/main.o -L$(LFT) -lft -o $@

obj/%.o: src/%.c dir $(LLS_H) $(LFT_H)
	@$(CC) $(CF) -c $< -o $@ -I include -I $(LFT)/include
	@echo "$(GREENB) $(DEFAULT)\c"

# create ls object files
obj/%.o: src/libls/%.c dir $(LLS_H) $(LFT_H)
	@$(CC) $(CF) -c $< -o $@ -I include -I $(LFT)/include
	@echo "$(GREENB) $(DEFAULT)\c"

# create libft.a
$(LFT):
	@make all -C $(LFT)

fclean: clean
	@rm -f ft_ls
	@echo "> $(RED)ft_ls fclean$(DEFAULT)"

clean:
	@make fclean -C $(LFT)
	@rm -f $(LSOFILES) obj/main.o
	@rm -fd obj
	@echo "> $(YELLOW)ft_ls clean$(DEFAULT)"

re: fclean all
