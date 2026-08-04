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


#include "parser.h"

static int check_extension(
    char *filename,
    char *extension)
{
    size_t file_len;
    size_t ext_len;

    file_len = ft_strlen(filename);
    ext_len = ft_strlen(extension);

    if (file_len <= ext_len + 1)
        return (0);

    while (ext_len)
    {
        if (filename[file_len - 1] != extension[ext_len - 1])
            return (0);

        file_len--;
        ext_len--;
    }

    return (filename[file_len - 1] == '.');
}

t_error	verify_args(int ac, char **av)
{
    int fd;

	if (ac != 2)
    return(ERR_INVALID_ARGUMENT_COUNT);
    if (fd < 0)
    {
        printf("Error\nErro ao abrir o arquivo!\n");
        return (ERR_FILE_OPEN);
    }
	if (!check_extension(av[1], "rt"))
	{
		printf("Error\nFormato de documento errado!\n");
		return (ERR_INVALID_FILE_FORMAT);
	}
    close(fd);
	return (ERR_NONE);
}
