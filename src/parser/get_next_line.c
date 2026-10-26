/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:45:18 by lvitorin          #+#    #+#             */
/*   Updated: 2026/07/28 12:45:20 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*alloc_line(void)
{
	char	*line;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	return (line);
}

static int	read_chunk(int fd, char *buffer, int *index, int *bytes)
{
	if (*index >= *bytes)
	{
		*bytes = read(fd, buffer, BUFFER_SIZE);
		*index = 0;
		if (*bytes <= 0)
			return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	index;
	static int	bytes;
	char		*line;
	int			i;

	line = alloc_line();
	if (fd < 0 || !line)
		return (free(line), NULL);
	i = 0;
	while (1)
	{
		if (!read_chunk(fd, buffer, &index, &bytes))
			break ;
		line[i++] = buffer[index];
		if (buffer[index++] == '\n')
			break ;
	}
	if (i == 0)
		return (free(line), NULL);
	line[i] = '\0';
	return (line);
}
