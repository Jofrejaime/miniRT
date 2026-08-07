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

static int count_tokens(char **values)
{
    int i;

    i = 0;
    while (values && values[i])
        i++;
    return (i);
}

static void strip_newline(char *line)
{
    int i;

    i = 0;
    while (line[i])
        i++;
    if (i > 0 && line[i - 1] == '\n')
        line[i - 1] = '\0';
}

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
        ft_free_arr(token->values);
        free(token);
        return (NULL);
    }
    token->count = count_tokens(token->values);
    token->line = line_number;
    token->next = NULL;
    return (token);
}

static void add_token(
    t_token **head,
    t_token **tail,
    char *line,
    int line_number)
{
    t_token *new;

    new = token_new(line, line_number);
    free(line);
    if (!new)
        return ;
    if (!*head)
    {
        *head = new;
        *tail = new;
    }
    else
    {
        (*tail)->next = new;
        *tail = new;
    }
}
 

t_token *tokenize(int fd)
{
    t_token *head;
    t_token *tail;
    char    *line;
    int     line_number;

    head = NULL;
    tail = NULL;
    line_number = 1;
    while ((line = get_next_line(fd)))
    {
        strip_newline(line);
        if (line[0] == '\0')
        {
            free(line);
            line_number++;
            continue;
        }
        add_token(&head, &tail, line, line_number);
        line_number++;
    }
    return (head);
}
