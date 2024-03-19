/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:32:22 by asebaai           #+#    #+#             */
/*   Updated: 2024/03/18 06:17:50 by asebaai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// valgrind --leak-check=full CHECK LEAKS;

static char	**free_str(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int	cword(char const *s, char c)
{
	int	i;
	int	t;

	t = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			t++;
		}
		if (s[i])
			i++;
	}
	return (t);
}

static char	**strt(char const *s, char c, char **str)
{
	int	i;
	int	j;
	int	t;

	t = 0;
	i = 0;
	j = 0;
	str[cword(s, c)] = NULL;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i++] != c)
				t++;
			i--;
			str[j] = ft_calloc(t + 1, sizeof(char));
			if (!str[j++])
				return (free_str(str));
			t = 0;
		}
		i++;
	}
	return (str);
}

static char	**strmalloc(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * (1 + cword(s, c)));
	if (!str)
		return (NULL);
	str = strt(s, c, str);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		g;
	char	**str;

	i = 0;
	j = 0;
	g = 0;
	str = strmalloc(s, c);
	while (s[i])
	{
		while (s[i] != c && s[i] != '\0')
		{
			str[j][g] = s[i];
			g++;
			if (s[i++ + 1] == c)
			{
				j++;
				g = 0;
			}
		}
		if (s[i++] == '\0')
			return (str);
	}
	return (str);
}
