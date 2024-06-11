# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 16:55:40 by jveirman          #+#    #+#              #
#    Updated: 2024/06/11 17:06:39 by jveirman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#===================================================================#
#								SETTINGS							#
#===================================================================#

NAME			=	philosophers

#-----------------				COMPILING			----------------#
CC				=	cc
OUT				=	-o $(NAME)
CFLAGS			=	-Wall -Wextra -Werror -I./includes
CFLAGS_DEV		=	-Wall -Wextra -Werror -I./includes -fsanitize=address -g

RM				=	rm -rf

#-----------------				ASSETS				----------------#
LIBFT			=	./libft/libft.a

#-----------------				DEPENDENCIES		----------------#
MKFILES			=	art.mk
include				$(MKFILES)

#-----------------				DIRECTORIES			----------------#
BUILD_DIR		:=	./build
SRC_DIR			:=	./sources

#-----------------				SOURCES				----------------#
SRCS_PHILO		=	$(SRC_DIR)/main.c \
					$(SRC_DIR)/parser.c

#-----------------				OBJECTS				----------------#
# OBJS_FRONTEND	=	$(SRCS_FRONTEND:%.c=$(BUILD_DIR)/%.o)
# OBJS_EXEC	=	$(SRCS_EXEC:%.c=$(BUILD_DIR)/%.o)
OBJS_PHILO		=	$(patsubst $(SRC_PHILO_DIR)/%.c, $(BUILD_DIR)/philo_%.o, $(SRCS_PHILO))

#===================================================================#
#								TARGETS								#
#===================================================================#

.SILENT: 
.PHONY: help all art create_dir re clean fclean how_to

all: create_dir	$(NAME)## Command to start all the compiling
	make art

#-----------------				COMPILE OBJECTS		----------------#
$(BUILD_DIR)/philo_%.o: $(SRC_PHILO_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

#-----------------				BUILD PHILO			----------------#
$(NAME): $(OBJS_PHILO)
	make all -C libft
	$(CC) $(CFLAGS_DEV) $(OBJS_PHILO) $(LIBFT) -o $@

#-----------------				SETUP DIR			----------------#
create_dir:	## Build the directory that will gather .o files
	if [ -d $(BUILD_DIR) ]; then \
		echo "Build folder already exists"; \
	else \
		mkdir -p $(BUILD_DIR); \
		echo "Build folder has been created"; \
	fi

#-----------------				ART/LOADING			----------------#
art:	## ASCII art for pilosophers
	echo $(ART_AFTER_COMPILE)

#-----------------				COMMANDS			----------------#
clean:	## Remove all the .o files from build directory (build include)
	$(RM) $(BUILD_DIR)
	make clean -C libft

fclean: clean ## Remove all .o files and the pilosophers binary
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all ## Clean everything and recompile the project
	
help:	## Show the commands
	@grep -E '^[a-zA-Z_-]+:.*?##' $(MAKEFILE_LIST) | \
	awk 'BEGIN {FS = ":.*?## "}; {split($$0, parts, ":"); sub(/^ */, "", parts[2]); printf "\033[32m%-20s\033[0m %s\n", parts[2], $$2}' | \
	sed -e 's/\[32m##/[33m/'

how_to: ## Command to help you to add update to the makefile
	echo "No information yet."
