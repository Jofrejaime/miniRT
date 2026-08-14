#include "debug.h"

void	debug_error(t_error_info *error)
{
	if (!error)
		return ;
	printf("Error Code : %d\n", error->code);
	printf("Line       : %d\n", error->line);
	printf("Identifier : %s\n", error->identifier ? error->identifier : "(null)");
	printf("Value      : %s\n", error->value ? error->value : "(null)");
	printf("Message    : %s\n", error->message ? error->message : "(null)");
}
