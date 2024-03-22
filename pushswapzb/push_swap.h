/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:23:54 by asebaai           #+#    #+#             */
/*   Updated: 2024/03/22 17:09:22 by asebaai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_push
{
	int num;
	int index;
	struct s_push *next;
} t_push;

// functions
int ft_lstsize(t_push *lst);
t_push *ft_lstnew(int content);
t_push *ft_lstlast(t_push *lst);
void ft_lstadd_front(t_push **lst, t_push *new);
void ft_lstadd_back(t_push **lst, t_push *new);
long ft_atoi(const char *str);
int ft_isnumber(char *str);
int ft_isdigit(char c);
void error_print(void);
void ft_check_av(char **str, int ac);
char *av_to_pointer(int ac, char *av[]);
char *rm_space_dup(char *s);
int ft_ispace(int c);
int malloc_len(int ac, char **av);
int ft_strlen(char *s);
char *get_next_line(int fd);
char *ft_strjoin(char *s1, char *s2);
void *ft_memmove(void *dest, const void *src, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
char *ft_strdup(const char *s);
void *ft_calloc(size_t nmemb, size_t size);
char **ft_split(char const *s, char c);
void ft_bzero(void *s, size_t n);
void check_max(long *num, int d);
void check_repete(char **str);
void free_lst(t_push **stack);
void pb(t_push **a, t_push **b);
void pa(t_push **a, t_push **b);
void sa(t_push **a);
void sb(t_push **b);
void ra(t_push **a);
void rb(t_push **b);
void rra(t_push **a);
void rrb(t_push **b);
void rrr(t_push **a, t_push **b);
void ss(t_push **a, t_push **b);
void rr(t_push **a, t_push **b);
t_push *stack_to_a(t_push *head, long data);
void sort_indx(t_push **a);
void push_back_to_a(t_push **stack_a, t_push **stack_b);
int highest_index(t_push *stack);
int finder(t_push **stack, int pos);
int find_index(t_push *s_a, int x, int p);
void push_back_to_a(t_push **stack_a, t_push **stack_b);
void sort_nbr(t_push **s_a, t_push **s_b, int p);
void sort100(t_push **s_a, t_push **s_b);
void free_strs(char ***strs);
void check_repete1(long *tab, int i, int j, int d);
int checked_sorted(t_push **a, int min);
void sort5(t_push **a, t_push **b, int min);
void sort4(t_push **a, t_push **b, int min);
void sort3(t_push **a, t_push **b, int min);
void sort2(t_push **a);
int min_indx(t_push *a);

#endif