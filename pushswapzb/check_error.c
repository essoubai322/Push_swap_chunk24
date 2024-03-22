/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:16:45 by asebaai           #+#    #+#             */
/*   Updated: 2024/03/22 14:29:47 by asebaai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_print(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isnumber(char *s)
{
	char	*str;

	str = s;
	if (!*str)
		error_print();
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str == '-' || *str == '+')
		{
			str--;
			if (ft_isdigit(*str))
				error_print();
			str++;
			str++;
		}
		if (!ft_isdigit(*str))
			error_print();
		str++;
		while (*str == ' ')
			str++;
	}
	return (1);
}

void	ft_check_av(char **str, int ac)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		ft_isnumber(str[i]);
		i++;
	}
}

void	check_max(long *num, int d)
{
	int	i;

	i = 0;
	while (i < d)
	{
		if (!(num[i] >= -2147483648 && num[i] <= 2147483647))
			error_print();
		i++;
	}
}
