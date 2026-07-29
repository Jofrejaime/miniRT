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

static char *reset_space(char *line)
{
    int i;

    i = 0;
    while(line[i] == ' ' || line[i] == '\t')
            i++;
    char *newLine = ft_strdup(line + i);
    return (newLine);
}


int parse_map(int fd, t_scene *scene)
{
    char *line;
    int i;

    i = 0;
    while((line = get_next_line(fd)))
    {
       char *newLine = reset_space(line);
       free(line);
       char **words = ft_split(newLine, ' ');
       if (words[0][0] == 'A' && ft_matrizlen(words) == 3)
       {
            // Process ambient light line
            if (!(scene->ambient = analyse_ambiente(words)))
                return (0);
        }
        free(newLine);
    }
    return (1);
}