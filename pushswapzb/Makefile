NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar -rcs

SRCS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
		ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
		push_swap.c
#SRCSB = ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c \
	ft_lstmap_bonus.c
OBJS1 = $(SRCS:.c=.o)
#OBJS2 = $(SRCSB:.c=.o)

all : $(NAME)
$(NAME) : $(OBJS1)
$(OBJS1) : $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)
	$(AR) $(NAME) $(OBJS1)
#bonus : $(OBJS2)
#$(OBJS2) : $(SRCSB)
#	$(CC) $(CFLAGS) -c $(SRCSB)
#	$(AR) $(NAME) $(OBJS2)
clean :
	$(RM) $(OBJS1)
fclean : clean
	$(RM) $(NAME)
re : fclean all
.PHONY : all bonus clean fclean re