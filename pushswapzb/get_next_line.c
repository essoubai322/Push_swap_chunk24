/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 00:17:44 by asebaai           #+#    #+#             */
/*   Updated: 2024/03/18 03:30:42 by asebaai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static char	*join_read(char *save_sto, char *buffer, int fd)
{
	ssize_t	read_n;

	while (1)
	{
		read_n = read(fd, buffer, BUFFER_SIZE);
		if (read_n <= 0)
			break ;
		buffer[read_n] = '\0';
		save_sto = ft_strjoin(save_sto, buffer);
		if (ft_strchr(save_sto, '\n') != -1)
			break ;
	}
	free(buffer);
	buffer = NULL;
	return (save_sto);
}

static int	new_l(char *save_sto)
{
	int	i;

	i = 0;
	while (save_sto[i] != '\n' && save_sto[i] != '\0')
		i++;
	if (save_sto[i] == '\n')
		i++;
	return (i);
}

static char	*fr(char *t)
{
	free(t);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*save_str;
	char		*buffer;
	char		*next_line;
	char		*save_lines;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	save_str = join_read(save_str, buffer, fd);
	if (!save_str || save_str[0] == '\0')
		return (fr(save_str));
	i = new_l(save_str);
	next_line = malloc(i + 1);
	if (!next_line)
		return (fr(save_str));
	ft_memmove(next_line, save_str, i);
	next_line[i] = '\0';
	save_lines = ft_strdup(&save_str[i]);
	free(save_str);
	save_str = save_lines;
	return (next_line);
}
