/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:56:26 by asebaai           #+#    #+#             */
/*   Updated: 2024/03/25 23:05:13 by asebaai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t range)
{
	size_t	i;
	size_t	check;
	size_t	to_find_lenght;

	i = 0;
	if (!str && !range)
		return (NULL);
	if (!*to_find)
		return ((char *)str);
	to_find_lenght = ft_strlen(to_find);
	while (str[i] && to_find_lenght <= range - i)
	{
		check = 0;
		while (str[i + check] == to_find[check] && to_find[check])
			check++;
		if (to_find[check] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

void	is_valid(t_push **a, t_push **b, char *line)
{
	if (ft_strnstr(line, "sa\n", 3))
		sa(a);
	else if (ft_strnstr(line, "pa\n", 3))
		pa(a, b);
	else if (ft_strnstr(line, "pb\n", 3))
		pb(a, b);
	else if (ft_strnstr(line, "sb\n", 3))
		sb(b);
	else if (ft_strnstr(line, "ra\n", 3))
		ra(a);
	else if (ft_strnstr(line, "rb\n", 3))
		rb(b);
	else if (ft_strnstr(line, "rr\n", 3))
		rr(a, b);
	else if (ft_strnstr(line, "rra\n", 4))
		rra(a);
	else if (ft_strnstr(line, "rrb\n", 4))
		rrb(b);
	else if (ft_strnstr(line, "rrr\n", 4))
		rrr(a, b);
	else if (ft_strnstr(line, "ss\n", 4))
		ss(a, b);
	else
		error_print();
}

void	read_instructions(t_push **a, t_push **b)
{
	char	*line;

	sort_indx(a);
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		is_valid(a, b, line);
		free(line);
	}
	if (*b)
	{
		write(1, "KO", 2);
		free_lst(b);
	}
	else if (checked_sorted(a, min_indx(*a)))
	{
		write(1, "KO", 2);
		free_lst(b);
	}
	else
		write(1, "OK", 2);
}

int	main(int ac, char **av)
{
	t_push	*head_a;
	t_push	*head_b;
	char	*s;
	char	**strs;
	int		i;

	head_a = NULL;
	head_b = NULL;
	i = 0;
	if (ac == 1)
		return (0);
	ft_check_av(av, ac);
	s = av_to_pointer(ac, av);
	strs = ft_split(s, ' ');
	check_repete(strs);
	while (strs[i])
		head_a = stack_to_a(head_a, atoi(strs[i++]));
	read_instructions(&head_a, &head_b);
	i = 0;
	free(s);
	while (strs[i])
		free(strs[i++]);
	free(strs);
	free_lst(&head_a);
	free_lst(&head_b);
}
