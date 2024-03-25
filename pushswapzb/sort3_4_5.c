/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_4_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:48:53 by asebaai           #+#    #+#             */
/*   Updated: 2024/03/22 23:59:47 by asebaai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checked_sorted(t_push **a, int min)
{
	t_push	*tmp;
	int		i;

	tmp = *a;
	if (!*a)
		return (0);
	i = min;
	while (tmp)
	{
		if (tmp->index != i)
			return (1);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

int	min_indx(t_push *a)
{
	int	min;

	min = a->index;
	while (a)
	{
		if (a->index < min)
			min = a->index;
		a = a->next;
	}
	return (min);
}

void	sort3(t_push **a, t_push **b, int min)
{
	if ((*a)->index == min)
	{
		pb(a, b);
		sa(a);
		pa(a, b);
	}
	else if ((*a)->index == (min + 1) && (*a)->next->index == min)
		sa(a);
	else if ((*a)->index == (min + 2) && (*a)->next->index == min)
		ra(a);
	else if ((*a)->index == (min + 2) && (*a)->next->index == (min + 1))
	{
		ra(a);
		sa(a);
	}
	else
	{
		ra(a);
		ra(a);
	}
}

void	sort4(t_push **a, t_push **b, int min)
{
	while (checked_sorted(a, min_indx(*a)))
	{
		if ((*a)->index == min)
		{
			pb(a, b);
			sort3(a, b, min_indx(*a));
			pa(a, b);
		}
		else if (finder(a, highest_index(*a)) > ft_lstsize(*a) / 2)
		{
			while (!((*a)->index == min))
				rra(a);
		}
		else
		{
			while (!((*a)->index == min))
				ra(a);
		}
	}
}

void	sort5(t_push **a, t_push **b, int min)
{
	while (checked_sorted(a, min_indx(*a)))
	{
		if ((*a)->index == min)
		{
			pb(a, b);
			sort4(a, b, min_indx(*a));
			pa(a, b);
		}
		else
		{
			while (!((*a)->index == min))
				rra(a);
		}
	}
}
