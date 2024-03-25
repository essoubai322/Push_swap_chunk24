/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 03:27:41 by asebaai           #+#    #+#             */
/*   Updated: 2024/03/23 00:57:43 by asebaai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	malloc_len(int ac, char **av)
{
	int	j;
	int	len;

	j = 1;
	len = 0;
	while (j < ac)
	{
		len += ft_strlen(av[j]) + 1;
		j++;
	}
	return (len);
}

int	ft_ispace(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

char	*av_to_pointer(int ac, char *av[])
{
	int		total_length;
	int		i;
	char	*result;
	int		offset;

	total_length = malloc_len(ac, av);
	i = 1;
	result = (char *)malloc(total_length + 1);
	offset = 0;
	while (i < ac)
	{
		ft_strcpy(&result[offset], av[i]);
		offset += ft_strlen(av[i]);
		result[offset++] = ' ';
		i++;
	}
	result[offset - 1] = '\0';
	return (result);
}

void	check_repete1(long *tab, int i, int j, int d)
{
	while (i < d)
	{
		j = 0;
		while (j < d)
		{
			if (tab[i] == tab[j] && i != j)
				error_print();
			j++;
		}
		i++;
	}
}

void	check_repete(char **str)
{
	int		i;
	long	*tab;
	int		j;
	int		d;

	d = 0;
	while (str[d])
		d++;
	tab = malloc(sizeof(long) * d);
	if (!tab)
		return ;
	i = 0;
	j = 0;
	while (j < d)
	{
		tab[j] = ft_atoi(str[j]);
		j++;
	}
	j = 0;
	check_repete1(tab, i, j, d);
	free(tab);
}
