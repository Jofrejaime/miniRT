

#include "token.h"

int main(int argc, char **argv)
{
    int fd;
    t_token *tokens;

    if (argc != 2)
        return (1);
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (1);
    tokens = tokenize(fd);
    print_tokens(tokens);
    return (0);
}
