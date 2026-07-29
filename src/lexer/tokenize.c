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

static t_token *token_new(
    char *raw_line,
    int line_number)
{
    t_token *token;
    token = malloc(sizeof(t_token));
    if (!token)
        return (NULL);
    token->raw_line = ft_strdup(raw_line);
    token->values = ft_split(raw_line, ' ');
    if (!token->raw_line || !token->values)
    {
        free(token->raw_line);
        free(token);
        return (NULL);
    }
    token->count = count_tokens(token->values);
    token->line = line_number;
    token->next = NULL;
    return (token);
}

void print_tokens(t_token *tokens)
{
    while (tokens)
    {
        printf(
            "[LINE %d] (%d tokens)\n",
            tokens->line,
            tokens->count);
        ft_print_arr(tokens->values);
        printf("\n");
        tokens = tokens->next;
    }
}

t_token *tokenize(int fd)
{
    t_token *head;
    t_token *tail;
    t_token *new;
    char    *line;
    int     line_number;

    head = NULL;
    tail = NULL;
    line_number = 1;
    while ((line = get_next_line(fd)))
    {
        new = token_new(line, line_number);
        free(line);
        if (!new)
            return (NULL);
        if (!head)
        {
            head = new;
            tail = new;
        }
        else
        {
            tail->next = new;
            tail = new;
        }
        line_number++;
    }
    return (head);
}

void destroy_tokens(t_token *tokens)
{
    t_token *next;

    while (tokens)
    {
        next = tokens->next;
        ft_free_arr(tokens->values);
        free(tokens->raw_line);
        free(tokens);
        tokens = next;
    }
}