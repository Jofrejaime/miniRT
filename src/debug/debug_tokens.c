#include "debug.h"

void	debug_tokens(t_token *tokens)
{
	while (tokens)
	{
		printf("[LINE %d] (%d tokens)\n", tokens->line, tokens->count);
		ft_print_arr(tokens->values);
		printf("\n");
		tokens = tokens->next;
	}
}
