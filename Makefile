NAME = libasm.a

ASM = nasm -f elf64
#LINUX	= -f elf64
#MAC	= -f macho64


CFLAGS = -Wall -Wextra -Werror

LIB = ar -rcs


SRCS =	ft_strlen.s \
	ft_strcpy.s \
	ft_strcmp.s \
	ft_write.s \
	ft_read.s \
	ft_strdup.s \

OBJS = ${SRCS:.s=.o}

SRCS_BONUS =	ft_list_size_bonus.s

OBJS_BONUS = ${SRCS_BONUS:.s=.o}


RM = rm -rf

all: 		${NAME}

${NAME}:	${OBJS}
		${LIB} ${NAME} ${OBJS}

clean:
		${RM} ${OBJS} ${OBJS_BONUS} main.o
		
fclean:		clean
		${RM} ${NAME} ${BONUS} test

re:		fclean all

test:		re
		gcc main.c -c
		gcc -Wall -Wextra -Werror -L. -o test main.o libasm.a
		./test
#for macOS
#test:		${NAME}
#		gcc -Wall -Wextra -Werror -L. -lasm -o test main.c
		
bonus:		${OBJS} ${OBJS_BONUS}
		${LIB} ${NAME} ${OBJS} ${OBJS_BONUS}

%.o: %.s
		${ASM} $< -o $@
