/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:46:46 by lvitorin          #+#    #+#             */
/*   Updated: 2026/07/29 12:46:48 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "token.h"

void    print_tokens(t_token *tokens)
{
    while (tokens)
    {
        ft_print_arr(tokens->value);
        tokens = tokens->next;
    }
}

t_token *tokenize(int fd)
{
    t_token *tokens;
    t_token *new_token;
    char *line;

    tokens = NULL;
    while ((line = get_next_line(fd)))
    {
        new_token = malloc(sizeof(t_token));
        if (!new_token)
            return (NULL);
        new_token->value = ft_split(line, ' ');
        new_token->next = NULL;
        if (!tokens)
            tokens = new_token;
        else
        {
            t_token *last;

            last = tokens;
            while (last->next)
                last = last->next;
            last->next = new_token;
        }
        free(line);
    }
    return (tokens);
}
