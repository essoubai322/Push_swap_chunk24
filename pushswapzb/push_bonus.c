/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:09:07 by asebaai           #+#    #+#             */
/*   Updated: 2024/03/22 20:09:41 by asebaai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_push **b)
{
	t_push	*tmp;

	tmp = NULL;
	if (!b || !(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	ft_lstadd_back(b, tmp);
}

void	rra(t_push **a)
{
	t_push	*last;
	t_push	*current;

	current = *a;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	while (current->next->next != NULL)
	{
		current = current->next;
	}
	last = current->next;
	current->next = NULL;
	last->next = *a;
	*a = last;
}

void	rrb(t_push **b)
{
	t_push	*tmp;
	t_push	*tmp1;

	tmp = NULL;
	tmp1 = NULL;
	if (!b || !(*b))
		return ;
	tmp1 = *b;
	tmp = ft_lstlast(*b);
	while (tmp1)
	{
		if (!(tmp1->next->next))
		{
			tmp1->next = NULL;
			break ;
		}
		tmp1 = tmp1->next;
	}
	ft_lstadd_front(b, tmp);
}

void	rrr(t_push **a, t_push **b)
{
	rra(a);
	rrb(b);
}

void	rr(t_push **a, t_push **b)
{
	ra(a);
	rb(b);
}
