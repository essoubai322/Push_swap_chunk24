/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:01:52 by asebaai           #+#    #+#             */
/*   Updated: 2024/03/18 13:13:02 by asebaai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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

int main(int ac, char **av)
{
	t_push *head_a;
    char *s;
    char **strs;
    int i = 0;
    if (ac == 1)
        return (0);
    ft_check_av(av, ac);
    s = av_to_pointer(ac, av);
    strs = ft_split(s,' ');
	//free(s);
    //check_repete(strs);
	// while (strs[i])
	// 	printf("%s\n", strs[i++]);
	while(strs[i])
	{
		head_a = stack_to_a(head_a,atoi(strs[i++]));
	}
}
