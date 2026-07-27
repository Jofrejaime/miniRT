/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_extent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:12:38 by lvitorin          #+#    #+#             */
/*   Updated: 2026/07/27 17:12:40 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parse.h"

int	ft_strlen(const	char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int analyze_extent(char *filename, char *extensao)
{
    int i;
    int fileSize;
    int extSize;

    fileSize = ft_strlen(filename);
    extSize = ft_strlen(extensao);
    if (extSize >= fileSize)
        return (0);
    while(extSize - 1 >= 0)
    {
        if (filename[fileSize - 1] != extensao[extSize - 1])
            return (0);
        fileSize--;
        extSize--;
    }
    if (filename[fileSize - 1] != '.')
        return (0);
    return(1);
}