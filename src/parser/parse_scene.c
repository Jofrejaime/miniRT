#include "parser.h"

t_error parse_scene(
    t_rt *rt,
    t_token *tokens)
{
    t_error err;

    while (tokens)
    {
        err = parse_element(rt, tokens);

        if (err)
        {
            set_error(
                &rt->error,
                err,
                tokens->line,
                tokens->values[0],
                tokens->raw_line,
                NULL);
            return (err);
        }

        tokens = tokens->next;
    }

    err = validate_scene(rt);

    if (err)
        return (err);

    return (ERR_NONE);
}