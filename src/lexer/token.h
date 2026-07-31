#ifndef TOKEN_H
# define TOKEN_H

//#include "minirt.h"
#include <stdio.h>
#include <libft.h>
#include <fcntl.h>

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
char    *get_next_line(int fd);
void destroy_tokens(t_token *tokens);

#endif
