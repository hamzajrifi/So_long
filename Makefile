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

O_FILES = $(C_FILES:.c=.o)
all : $(NAME)

$(NAME)	:	$(O_FILES) $(HEADER)
			@$(CC) $(C_FLAG) -c $(C_FILES) 
			@ar -rc $(NAME) $(O_FILES)
			@$(CC) $(C_FLAG) $(FLAG_MLX)  -o so_long so_long.c $(NAME)

re : fclean all

clean : 
	@rm -f  *.o checker/*.o ft_error/*.o \
	get_next_line/*.o create_graphique_map/*.o   \
	bonus/checker/*.o bonus/ft_error/*.o \
	bonus/get_next_line/*.o bonus/create_graphique_map/*.o 

fclean : clean
	@rm -f so_long so_long_bonus so_long.a so_long_bonus.a


#---------- PARTE BONUS ------------*
BNS_NAME = so_long_bonus.a

BNS_HEADER = ./bonus/header_bonus.h

BNS_C_FILES =	./bonus/get_next_line/get_next_line_utils_bonus.c \
				./bonus/get_next_line/get_next_line_bonus.c \
				./bonus/checker/checker_bonus.c \
				./bonus/create_graphique_map/cheak_char_map_bonus.c\
				./bonus/checker/check_name_map_bonus.c \
				./bonus/checker/ft_split_bonus.c  \
				./bonus/ft_error/ft_error_bonus.c \
				./bonus/create_graphique_map/function_move_bonus.c \
				./bonus/create_graphique_map/check_char_map_2_bonus.c \
				./bonus/so_long_bonus.c

BNS_O_FILES = $(BNS_C_FILES:.c=.o)

bonus : $(BNS_NAME)

$(BNS_NAME) :	$(BNS_O_FILES) $(BNS_HEADER)
				@$(CC) $(C_FLAG) -c $(BNS_C_FILES) 
				@ar -rc $(BNS_NAME)  $(BNS_O_FILES)
				@$(CC) $(C_FLAG) $(FLAG_MLX) -o so_long_bonus ./bonus/so_long_bonus.c $(BNS_NAME)