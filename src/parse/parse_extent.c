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

int analyze_extent(char *filename, char *extensao)
{
    size_t  file_size;
    size_t  ext_size;

    file_size = ft_strlen(filename);
    ext_size = ft_strlen(extensao);
    if (ext_size >= file_size)
        return (0);
    while (ext_size > 0)
    {
        if (filename[file_size - 1] != extensao[ext_size - 1])
            return (0);
        file_size--;
        ext_size--;
    }
    if (filename[file_size - 1] != '.')
        return (0);
    return(1);
}
