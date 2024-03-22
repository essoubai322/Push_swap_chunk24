/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:01:52 by asebaai           #+#    #+#             */
/*   Updated: 2024/03/22 17:25:47 by asebaai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_back_to_a(t_push **stack_a, t_push **stack_b)
{
	while ((*stack_b))
	{
		if ((*stack_b)->index == highest_index(*stack_b) || (*stack_b)->index == highest_index(*stack_b) - 1)
			pa(stack_a, stack_b);
		else if (finder(stack_b, highest_index(*stack_b)) > ft_lstsize(*stack_b) / 2)
			while (!((*stack_b)->index == highest_index(*stack_b) || (*stack_b)->index == highest_index(*stack_b) - 1))
				rrb(stack_b);
		else
			while (!((*stack_b)->index == highest_index(*stack_b) || (*stack_b)->index == highest_index(*stack_b) - 1))
				rb(stack_b);
		if (ft_lstsize(*stack_a) > 1 && (*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
	}
}

void sort_nbr(t_push **s_a, t_push **s_b, int p)
{
	int len;
	int i;

	i = 0;
	len = ft_lstsize(*s_a);
	while (i < len)
	{
		if ((*s_a)->index <= i)
		{
			pb(s_a, s_b);
			rb(s_b);
			i++;
		}
		else if ((*s_a)->index <= i + p)
		{
			pb(s_a, s_b);
			i++;
		}
		else if (find_index(*s_a, i, p) < ft_lstsize(*s_a) / 2)
			ra(s_a);
		else
			rra(s_a);
	}
}

void sort100(t_push **s_a, t_push **s_b)
{
	int len;

	sort_indx(s_a);
	len = ft_lstsize(*s_a);
	if (checked_sorted(s_a, min_indx(*s_a)))
	{
		if (len == 2)
			sort2(s_a);
		else if (len == 3)
			sort3(s_a, s_b, min_indx(*s_a));
		else if (len == 4)
			sort4(s_a, s_b, min_indx(*s_a));
		else if (len == 5)
			sort5(s_a, s_b, min_indx(*s_a));
		else if (len <= 400)
			sort_nbr(s_a, s_b, 15);
		else
			sort_nbr(s_a, s_b, 30);
		push_back_to_a(s_a, s_b);
	}
}

int main(int ac, char **av)
{
	t_push *head_a;
	t_push *head_b;
	char *s;
	char **strs;
	int i;

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
	sort100(&head_a, &head_b);
	i = 0;
	free(s);
	while (strs[i])
		free(strs[i++]);
	free(strs);
	free_lst(&head_a);
	free_lst(&head_b);
}
