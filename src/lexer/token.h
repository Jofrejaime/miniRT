#ifndef TOKEN_H
# define TOKEN_H

#include "../../includes/minirt.h"

typedef struct s_token
{
    char **value;
    int count;
    int line;
    char *row_line;
    struct s_token *next;
}   t_token;

void    print_tokens(t_token *tokens);
t_token *tokenize(int fd);

#endif
