#ifndef PUSH_H
# define PUSH_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct s_push
{
	int				num;
	int				index;
	struct	s_push	*next;
}	t_push;

// functions
int	ft_lstsize(t_push *lst);
t_push	*ft_lstnew(int	content);
t_push	*ft_lstlast(t_push *lst);
void	ft_lstadd_front(t_push **lst, t_push *new);
void	ft_lstadd_back(t_push **lst, t_push *new);
long	ft_atoi(const char *str);
int ft_isNumber(char *str);
int ft_isDigit(char c);
void	error_print(void);
void 	ft_check_av(char **str, int ac);
char *av_to_pointer(int ac, char *av[]);
char *rm_space_dup(char *s);
int ft_ispace(int c);
int malloc_len(int ac, char **av);
int ft_strlen(char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *s, char c);
void	ft_bzero(void *s, size_t n);
void	check_max(long * num, int d);
void	check_repete(char **str);


#endif