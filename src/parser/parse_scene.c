#include "parser.h"

t_error parse_scene(t_rt *rt, t_token *tokens)
{
    while (tokens)
    {
        t_error err = parse_element(rt, tokens);
        if (err != ERR_NONE)
            return (err);
        tokens = tokens->next;
    }
    return (ERR_NONE);
}