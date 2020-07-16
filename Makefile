# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/11 20:09:44 by blinnea           #+#    #+#              #
#    Updated: 2020/07/16 14:59:35 by blinnea          ###   ########.fr        #
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
CF =		-Wall -Wextra -Werror -ggdb

# **************************************************************************** #
#                               ABBREVIATIONS                                  #
# **************************************************************************** #
LFT =		libft
LLS =		libls

# **************************************************************************** #
#                                 HEADERS                                      #
# **************************************************************************** #
LFT_H =		$(LFT)/include/$(LFT).h
LLS_H =		include/$(LLS).h
DIR_H = 	include/$(LLS)_dir.h
ELST_H =	include/$(LLS)_elist.h
ENT_H =		include/$(LLS)_entity.h

ALL_H =		$(LFT_H) $(LLS_H) $(DIR_H) $(ELST_H) $(ENT_H)

# **************************************************************************** #
#                                 FILENAMES                                    #
# **************************************************************************** #
LSFILES =		$(shell find src/libls -name '*.c')
DIRFILES =		$(shell find src/dir -name '*.c')
ELSTFILES =		$(shell find src/elist -name '*.c')
ENTFILES =		$(shell find src/entity -name '*.c')

LSOFILES =		$(addprefix obj/, $(LSFILES:src/libls/%.c=%.o))
DIROFILES =		$(addprefix obj/, $(DIRFILES:src/dir/%.c=%.o))
ELSTOFILES =	$(addprefix obj/, $(ELSTFILES:src/elist/%.c=%.o))
ENTOFILES =		$(addprefix obj/, $(ENTFILES:src/entity/%.c=%.o))

ALL_O =			$(LSOFILES) $(DIROFILES) $(ELSTOFILES) $(ENTOFILES)

.PHONY: dir $(LFT) clean fclean all

all: dir ft_ls
	@echo "\n> $(GREEN)ft_ls was created$(DEFAULT)"

dir:
	@mkdir -p obj

ft_ls: $(ALL_O) obj/main.o $(LFT)
	@$(CC) $(ALL_O) obj/main.o -L$(LFT) -lft -o $@


obj/%.o: src/%.c $(LLS_H) $(LFT_H)
	@$(CC) $(CF) -c $< -o $@ -I include -I $(LFT)/include
	@echo "$(GREENB) $(DEFAULT)\c"

# create ls object files
obj/%.o: src/libls/%.c $(ALL_H) $(LFT_H)
	@$(CC) $(CF) -c $< -o $@ -I include -I $(LFT)/include
	@echo "$(GREENB) $(DEFAULT)\c"

# create dir object files
obj/%.o: src/dir/%.c $(ELST_H) $(LFT_H) $(DIR_H)
	@$(CC) $(CF) -c $< -o $@ -I include -I $(LFT)/include
	@echo "$(GREENB) $(DEFAULT)\c"

# create elist object files
obj/%.o: src/elist/%.c $(ENT_H) $(LFT_H) $(ELST_H)
	@$(CC) $(CF) -c $< -o $@ -I include -I $(LFT)/include
	@echo "$(GREENB) $(DEFAULT)\c"

# create entity object files
obj/%.o: src/entity/%.c $(DIR_H) $(LFT_H) $(ENT_H)
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
