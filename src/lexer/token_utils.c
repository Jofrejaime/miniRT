
#include "token.h"

void ft_free_arr(char **arr)
{
    int i;

    if (!arr)
        return ;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }

    free(arr);
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
