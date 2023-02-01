##
## EPITECH PROJECT, 2022
## undefined
## File description:
## Makefile
##

CC = gcc
HEADERS = includes
OBJECTS = objects

NAME = wjson.a

vpath %.c sources/wjson_pars
vpath %.c sources/tools
vpath %.c sources/tools/stream
vpath %.c sources/tools/manage_lls
vpath %.c sources/tools/buffers

SRC = wjson_pars_main.c \
		wjson_get_dictionary.c \
		wjson_get_list.c \
		get_file_content.c \
		list.c \
		dictionary.c \
		str_tools.c \
		get_elements.c \
		index.c \
		manage_buffers.c \

OBJ = $(patsubst %.c, $(OBJECTS)/%.o, $(SRC))

all : create_dir $(NAME)

create_dir :| $(OBJECTS)

$(OBJECTS):
	@mkdir $@

$(OBJECTS)/%.o: %.c
	@$(CC) -c -o $@ $< -I./$(HEADERS)
	@echo "\033[34m-[DONE] $@-\033[0m"

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "\033[32m-[SUCCESS]-\033[0m"

test: $(OBJ) $(OBJECTS)
	@make re
	@gcc -o test $(OBJ) test.c -I./includes
	@echo "\033[32m-[SUCCESS CREATE TEST BINARY]-\033[0m"

re:
	@rm -rf $(OBJECTS)
	@echo "\033[31m-[RM] objects files-\033[0m"
	@make

clean:
	@rm -rf $(OBJECTS)
	@echo "\033[31m-[RM] objects files-\033[0m"
	@rm test

fclean:
	@rm -rf $(OBJECTS)
	@echo "\033[31m-[RM] objects files-\033[0m"
	@rm $(NAME)
	@echo "\033[31m-[RM] $(NAME)-\033[0m"
	@rm test
