NAME = push_swap
Name2 = checker
CC = cc 
CFLAGS = -Wall -Wextra -Werror 

SOURCE = argv_to_pointer.c ft_atoi.c check_error.c ft_calloc.c ft_lst.c ft_split.c \
			push_swap.c push_r_s.c push_tools.c push_r_s2.c sort3_4_5.c
SOURCEB = checker_bonus.c argv_to_pointer.c ft_atoi.c check_error.c ft_calloc.c ft_lst.c \
			push_bonus.c push1_bonus.c push_tools.c ft_split.c get_next_line_utils.c \
			get_next_line.c sort3_4_5.c
OBJ = ${SOURCE:.c=.o}
BOBJ = ${SOURCEB:.c=.o}

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ}
		${CC} ${CFLAGS} ${OBJ} -o ${NAME}

bonus: ${Name2} 

${Name2}: ${BOBJ}
		${CC} ${CFLAGS} ${BOBJ} -o ${Name2}

clean:
	rm -rf ${OBJ} ${BOBJ}

fclean: clean
	rm -rf ${NAME} ${Name2}

re: fclean all 