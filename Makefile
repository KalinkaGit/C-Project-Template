##
## EPITECH PROJECT, 2023
## PROJECT NAME
## File description:
## Make
##

## PROJECT SOURCES ##
SRC_DIR 		:= src

SRC_MAIN 		:= main.c

SRC_HANDLERS 	:= handlers/args.c \
				   handlers/errors.c

SRC				:= $(addprefix $(SRC_DIR)/, $(SRC_MAIN) $(SRC_HANDLERS))

## PROJECT HEADERS ##
INC_DIR 		:= include

## PROJECT BUILD ##
BUILD_DIR 		:= build

## PROJECT OUTPUT ##
RELEASE_DIR 	:= ./
RELEASE_NAME 	:= NAME

## PROJECT COMPILER ##
CC 				:= gcc

## PROJECT FLAGS ##
CFLAGS 			:= -Wall -Wextra -Wpedantic -std=c99 -I./$(INC_DIR)
RELEASE_FLAGS 	:= -O2 -lmy

## PROJECT OBJECTS ##
RELEASE_OBJ 	:= $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))

## PROJECT RULES ##
all: 				release

release: 			$(RELEASE_NAME)
					@printf "\033[32m[OK]\033[0m Project built successfully\n"

$(RELEASE_NAME): 	CFLAGS += -O3
					@make -C /lib/my
$(RELEASE_NAME): 	$(RELEASE_OBJ)
					@mkdir -p $(RELEASE_DIR)
					@printf "\033[32m[OK]\033[0m Linking project...\n"
					@$(CC) $(CFLAGS) $(RELEASE_FLAGS) \
					-o $(RELEASE_DIR)/$(RELEASE_NAME) $(RELEASE_OBJ)

## PROJECT OBJECTS RULES ##
$(BUILD_DIR)/%.o: 	%.c
					@mkdir -p $(dir $@)
					@printf "\033[32m[OK]\033[0m Building $<...\n"
					@$(CC) $(CFLAGS) -c $< -o $@

## PROJECT CLEAN RULES ##
clean:
					@printf "\033[32m[OK]\033[0m Cleaning project...\n"
					@rm -rf $(BUILD_DIR)

fclean: 			clean
					@printf "\033[32m[OK]\033[0m Removing project...\n"
					@rm -f $(RELEASE_NAME)

re: 				fclean all

.PHONY: 			all clean fclean re
