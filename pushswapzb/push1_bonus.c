/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push1_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:10:02 by asebaai           #+#    #+#             */
/*   Updated: 2024/03/22 20:10:38 by asebaai          ###   ########.fr       */
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
}
