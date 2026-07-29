/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 18:08:46 by lvitorin          #+#    #+#             */
/*   Updated: 2026/07/27 18:08:48 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int parse_color(int *r, int *g, int *b, char *line)
{
   if (!line)
        return (0);
    char **colors = ft_split(line, ',');
    if (!colors)
        return (0);
    *r = ft_atoi(colors[0]);
    *g = ft_atoi(colors[1]);
    *b = ft_atoi(colors[2]);
    free(colors[0]);
    free(colors[1]);
    free(colors[2]);
    free(colors);
    if (*r < 0 || *r > 255 || *g < 0 || *g > 255 || *b < 0 || *b > 255)
        return (0);
    return (1);
}

t_ambient    *analyse_ambiente(char **line)
{
    t_ambient *result;

    if (!line)
    return (NULL);
    result = malloc(sizeof(t_ambient));
    if (!result)
    return (NULL);
    if (ft_isfloat(line[1], &result->ratio) != '\0')
        return (NULL);
    if (!parse_color(&result->color.r, &result->color.g, &result->color.b, line[2]))
        return (NULL);
    printf("entrou\n");
    return (result);
}
