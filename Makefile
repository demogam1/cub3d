NAME = CubAr.a

SRC = cub.c parsing.c get_next_line.c get_map.c \
		parsing_1.c parsing_2.c parsing_3.c parsing_4.c parsing_5.c parsing_6.c parsing_7.c \
		two_d_map.c raycasting.c minimap.c drawing_3d.c ray_left.c ray_left_extension.c \
		minimap_extension.c minimap_extension_1.c deal_key_2.c deal_key_2_extension.c\
		cub_extension.c \

PROGRAM_NAME = cub3d

CFLAGS = -Wall -Werror -Wextra
 
CC = gcc

AR = ar -rcs

OBJ_DIR = Objects

SRC_DIR = Sources

INC_DIR = Headers

DELETE = rm -rf

O_FILE = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all : $(NAME)

$(NAME) : $(O_FILE)
	@make -C libft/
	@mv libft/libft.a ./CubAr.a
	@$(AR) $(NAME) $(O_FILE) 
	@$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(NAME) -o $(PROGRAM_NAME) $?

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf "\x1b[33m \x1b[1m Converting \x1b[0m  \x1b[36m $< \x1b[0m \x1b[33m \x1b[1m to \x1b[0m \x1b[34m $@ \x1b[0m \r"	
	@printf "\x1b[32m    [DONE]      \x1b[0m"
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@


clean:
	@echo "\x1b[1m \x1b[31m [CLEAN] : \x1b[0m \x1b[33m \x1b[1m $(O_FILE) \x1b[0m \n " 
	@make -C libft/ clean
	@$(DELETE) $(O_FILE) $(OBJ_DIR)

fclean: clean
	@echo "\x1b[1m \x1b[31m [FCLEAN] : \x1b[0m \x1b[33m \x1b[1m $(NAME) | $(PROGRAM_NAME) \x1b[0m \n "
	@make -C libft/ fclean
	@$(DELETE) $(NAME) $(PROGRAM_NAME)

re: fclean all

.Phony : all, clean, re, fclean