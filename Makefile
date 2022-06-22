NAME = ft_ssl
CC = gcc
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

CFLAGS += -g3 
CFLAGS += -fsanitize=address
CFLAGS += -Wpadded

#-----------------------------------------SRC/INC------------------------------#

FT_SSL_FILES 	= 	main parsing lib handle_errors init read_input execute md5 \
					clear md5_processing  print_hash sha256 sha256_processing	\
					sha_binary_operations sha384 sha384_processing sha512 	\
					sha512_processing

INC_FILES 	= ft_ssl.h

#--------------------------------------PATH/FILES------------------------------#

SRC_PATH = ./srcs/
INC_PATH = ./includes/
OBJ_PATH = ./obj/

SRC_FILES = $(FT_SSL_FILES:%=%.c)
OBJ_FILES = $(SRC_FILES:.c=.o)

INC = $(addprefix $(INC_PATH), $(INC_FILES))
OBJ = $(patsubst %.c, $(OBJ_PATH)%.o, $(SRC_FILES))

#-----------------------------------------RULES--------------------------------#

.PHONY: clean, fclean, all, re

all: $(NAME)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c -I $(INC_PATH) $< -o $@
	@echo "Compilation of $(notdir $<) done."

$(NAME): $(INC) $(OBJ_PATH) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lm -I $(INC_PATH)
	@echo "$(notdir $(NAME)) created."

clean:
	@$(RM) -R $(OBJ_PATH)
	@echo "Objects files of $(notdir $(NAME)) removed."

fclean: clean
	@$(RM) -R $(NAME)
	@echo "$(notdir $(NAME)) removed."

re: fclean $(NAME)

