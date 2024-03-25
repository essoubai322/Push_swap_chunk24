/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:33:36 by asebaai           #+#    #+#             */
/*   Updated: 2024/03/23 00:30:15 by asebaai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	s;

	s = nmemb * size;
	if (s > 0)
	{
		if (SIZE_MAX / nmemb < size)
			return (NULL);
		s = nmemb * size;
		ptr = malloc(s);
		if (!ptr)
			return (NULL);
		ft_bzero(ptr, s);
		return (ptr);
	}
	ptr = malloc(1);
	ft_bzero(ptr, 1);
	return (ptr);
}

void	free_lst(t_push **stack)
{
	t_push	*tmp;

	tmp = (*stack);
	while (*stack)
	{
		tmp = (*stack)->next;
		free((*stack));
		(*stack) = tmp;
	}
}

void	ss(t_push **a, t_push **b)
{
	sa(a);
	sb(b);
}
