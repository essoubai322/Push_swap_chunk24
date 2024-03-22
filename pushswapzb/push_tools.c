/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 07:58:21 by asebaai           #+#    #+#             */
/*   Updated: 2024/03/22 14:19:53 by asebaai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_indx(t_push **a)
{
	t_push	*tmp;
	t_push	*tmp1;

	tmp = *a;
	if (!tmp->next)
		return ;
	while (tmp)
	{
		tmp1 = *a;
		while (tmp1)
		{
			if (tmp->num > tmp1->num)
				tmp->index++;
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}

t_push	*stack_to_a(t_push *head, long data)
{
	t_push	*new_node;
	t_push	*last;

	new_node = malloc(sizeof(t_push));
	if (!new_node)
		return (NULL);
	new_node->num = data;
	new_node->index = 0;
	new_node->next = NULL;
	if (!head)
		return (new_node);
	last = ft_lstlast(head);
	last->next = new_node;
	return (head);
}

int	finder(t_push **stack, int pos)
{
	t_push	*tmp;
	int		i;

	i = 0;
	tmp = (*stack);
	while (tmp)
	{
		if (tmp->index == pos)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	find_index(t_push *s_a, int x, int p)
{
	int	i;

	i = 0;
	while (s_a)
	{
		if (s_a->index <= x || s_a->index <= x + p)
			break ;
		i++;
		s_a = s_a->next;
	}
	return (i);
}

int	highest_index(t_push *stack)
{
	int	highest;

	highest = stack->index;
	while (stack)
	{
		if (stack->index > highest)
			highest = stack->index;
		stack = stack->next;
	}
	return (highest);
}
