NAME =	fractol
CC =	gcc -Wall -Werror -Wextra

RM =	rm -rf

SRC =	fractol.c \
		fractols.c \
		proccesing.c \
		addition.c \
		events.c \

INC =	-I fractol.h

OBJS =	$(SRC:.c=.o)
DEP =	$(SRC:.c=.d)

.PHONY :	all clean re fclean norm

.c.o :		
		${CC} ${CFLAGS} -Imlx ${INC} -c $< -o ${<:.c=.o}


$(NAME):	$(OBJS) Makefile
			${CC} ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

all: 		$(NAME)

clean:
			$(RM) $(OBJS) $(DEP)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

-include $(DEP)
