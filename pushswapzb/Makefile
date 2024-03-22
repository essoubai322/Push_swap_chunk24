NAME = push_swap
#Name2 = checker
CC = cc 
CFLAGS = -fsanitize=address -Wall -Wextra -Werror
SOURCE = argv_to_pointer.c ft_atoi.c check_error.c ft_calloc.c ft_lst.c ft_split.c \
			push_swap.c push_r_s.c push_tools.c push_r_s2.c sort3_4_5.c
#SOURCEB = 	./bonus/check_sorted_bonus.c ./bonus/free_bonus.c ./bonus/checker_bonus.c ./bonus/check_arg_bonus.c ./bonus/ft_tools_bonus.c ./bonus/ft_tools2_bonus.c ./bonus/moves_push_bonus.c\
			./bonus/moves_reverse_bonus.c ./bonus/moves_rotate_bonus.c ./bonus/reverse_and_rotate_bonus.c ./bonus/moves_swap_bonus.c\
			./bonus/get_next_line/get_next_line.c ./bonus/get_next_line/get_next_line_utils.c ./bonus/ft_split2_bonus.c
OBJ = ${SOURCE:.c=.o}
#BOBJ = ${SOURCEB:.c=.o}

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ}
		${CC} ${CFLAGS} ${OBJ} -o ${NAME}

#bonus: ${Name2}

#${Name2}: ${BOBJ}
#		${CC} ${CFLAGS} ${BOBJ} -o ${Name2}

clean:
	rm -rf ${OBJ} 

fclean: clean
	rm -rf ${NAME}

re: fclean all 