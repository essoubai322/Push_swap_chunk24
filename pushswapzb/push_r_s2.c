/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_r_s2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:30:48 by asebaai           #+#    #+#             */
/*   Updated: 2024/03/22 14:33:27 by asebaai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_push **a, t_push **b)
{
	t_push	*tmp;

	tmp = NULL;
	if (!(a) || !(*a) || !(b))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_lstadd_front(b, tmp);
	write(1, "pb\n", 3);
}

void	pa(t_push **a, t_push **b)
{
	t_push	*tmp;

	tmp = NULL;
	if (!(b) || !(*b) || !(a))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	ft_lstadd_front(a, tmp);
	write(1, "pa\n", 3);
}

void	sa(t_push **a)
{
	int	tmp;
	int	index;

	if (!(a) || !(*a) || !((*a)->next))
		return ;
	tmp = (*a)->num;
	index = (*a)->index;
	(*a)->num = (*a)->next->num;
	(*a)->index = (*a)->next->index;
	(*a)->next->num = tmp;
	(*a)->next->index = index;
	write(1, "sa\n", 3);
}

void	sb(t_push **b)
{
	int	tmp;
	int	index;

	if (!(b) || !(*b) || !((*b)->next))
		return ;
	tmp = (*b)->num;
	index = (*b)->index;
	(*b)->num = (*b)->next->num;
	(*b)->index = (*b)->next->index;
	(*b)->next->num = tmp;
	(*b)->next->index = index;
	write(1, "sb\n", 3);
}

void	ra(t_push **a)
{
	t_push	*tmp;

	tmp = NULL;
	if (!a || !(*a))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_lstadd_back(a, tmp);
	write(1, "ra\n", 3);
}
