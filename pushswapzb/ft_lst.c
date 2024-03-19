/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:34:11 by asebaai           #+#    #+#             */
/*   Updated: 2024/03/18 10:54:14 by asebaai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_push *lst)
{
	int		i;
	t_push	*curnt;

	i = 0;
	curnt = lst;
	while (curnt != NULL)
	{
		curnt = curnt->next;
		++i;
	}
	return (i);
}

void	ft_lstadd_back(t_push **lst, t_push *new)
{
	t_push	*curr;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	curr = *lst;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

void	ft_lstadd_front(t_push **lst, t_push *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

t_push	*ft_lstlast(t_push *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_push	*ft_lstnew(int content)
{
	t_push	*node;

	node = malloc(sizeof(t_push));
	if (!node)
		return (NULL);
	node->num = content;
	node->index = 0;
	node->next = NULL;
	return (node);
}
