CC = gcc -lmlx -framework OpenGL -framework AppKit

C_FLAG = -Wall -Wextra -Werror 

NAME = So_long.a

HEADER  =	header.h \
			./get_next_line/get_next_line.h

C_FILES =	./get_next_line/get_next_line_utils.c \
			./get_next_line/get_next_line.c \
			so_long.c

O_FILES =	get_next_line_utils.o \
			get_next_line.o \
			so_long.o


all :
	$(CC) -c $(C_FILES) 
	ar -rc $(NAME) $(O_FILES)
	$(CC) -o So_long So_long.c $(NAME)

clean : 
	rm -r So_long.a *.o So_long
	