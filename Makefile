CC = gcc 

NAME = so_long.a

C_FLAG = -Wall -Wextra -Werror 

FLAG_MLX = -lmlx -framework OpenGL -framework AppKit

HEADER  =	header.h 

C_FILES =	so_long_utils.c \
			check_map.c 	\
			ft_error.c\
			so_long.c

O_FILES =	so_long_utils.o \
			check_map.o 	\
			ft_error.o \
			so_long.o

all :
	$(CC) -c $(C_FILES) 
	ar -rc $(NAME) $(O_FILES)
	$(CC) $(FLAG_MLX)  -o so_long so_long.c $(NAME)

clean : 
	@rm -f so_long.a *.o 
fclean : clean
	@rm -f so_long