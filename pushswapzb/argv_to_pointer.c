/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 03:27:41 by asebaai           #+#    #+#             */
/*   Updated: 2024/03/18 06:53:38 by asebaai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return (i);
}

int malloc_len(int ac, char **av)
{
    int j = 1;
    int len = 0;
    while (j < ac)
    {
        len += ft_strlen(av[j]) + 1;
        j++;
    }
    return (len);
}

int ft_ispace(int c)
{
    if (c == ' ')
        return (1);
    return (0);
}

char *av_to_pointer(int ac, char *av[]) 
{
    int total_length = malloc_len(ac,av);
    int i = 1;
    char *result = (char *)malloc(total_length + 1);
    int offset = 0;
    
    while (i < ac) {
        strcpy(&result[offset], av[i]);
        offset += strlen(av[i]);
        result[offset++] = ' ';
        i++;
    }
    result[offset - 1] = '\0';
    return (result);
}

void	check_repete(char **str)
{
	int	i;
	long	*tab;
	int	j;
	int d = 0;

	while (str[d])
		d++;
	tab = malloc(sizeof(int) * d);
	if (!tab)
		return ;
	i = 0;
	j = 0;
	while (j < d)
	{
		tab[j] = ft_atoi(str[j]);
		j++;
	}
	check_max(tab,d);
	j = 0;
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
	free(tab);
}