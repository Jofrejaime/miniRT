/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:38:26 by lvitorin          #+#    #+#             */
/*   Updated: 2026/07/28 12:38:28 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parse.h"

static char *reset_space(char **line)
{
    int i;

    i = 0;
    while(line[i] == ' ' || line[i] == '\t')
            i++;
    char *newLine = ft_strdup(line + i);
    free(line);
    return (newLine);
}


int parse_map(int fd)
{
    char *line;
    int i;

    i = 0;
    while((line = get_next_line(fd)))
    {
       char *newLine = reset_space(&line);
        if (newLine[0] == 'A')
        {
            // Process ambient light line
            analyse_ambiente(&newLine);
        }
        free(newLine);
    }
    return (0);
}