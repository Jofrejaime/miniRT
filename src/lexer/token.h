#ifndef TOKEN_H
# define TOKEN_H

#include "../../includes/minirt.h"

typedef struct s_token
{
    char            **values;
    int             count;
    int             line;
    char            *raw_line;
    struct s_token  *next;
} t_token;

void    print_tokens(t_token *tokens);
t_token *tokenize(int fd);
void destroy_tokens(t_token *tokens);

#endif
