CC = gcc 

C_FLAG = -Wall -Wextra -Werror 

FLAG_MLX = -lmlx -framework OpenGL -framework AppKit

NAME = So_long.a

HEADER  =	header.h

C_FILES =	./get_next_line/get_next_line_utils.c \
			./get_next_line/get_next_line.c \
			./checker/checker.c \
			./create_graphique_map/cheak_char_map.c\
			./checker/check_name_map.c \
			./checker/ft_split.c  \
			./ft_error/ft_error.c \
			./create_graphique_map/function_move.c \
			./create_graphique_map/check_char_map_2.c \
			./so_long.c

# O_FILES =	get_next_line_utils.o \
# 			get_next_line.o \
# 			checker.o \
# 			cheak_char_map.o \
# 			check_name_map.o \
# 			ft_split.o \
# 			ft_error.o\
# 			so_long.o

O_FILES = $(C_FILES:.c=.o)
all : $(NAME)

$(NAME)	: $(O_FILES)
			@$(CC) $(C_FLAG) -c $(C_FILES) 
			@ar -rc $(NAME) $(O_FILES)
			@$(CC) $(C_FLAG) $(FLAG_MLX)  -o so_long so_long.c $(NAME)

re : fclean all

clean : 
	@rm -f so_long.a *.o checker/*.o ft_error/*.o \
	get_next_line/*.o create_graphique_map/*.o   

fclean : clean
	@rm -f so_long
	