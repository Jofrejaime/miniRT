#include "errors.h"

void set_error(
	t_error_info *err,
	t_error code,
	int line,
	char *identifier,
	char *value,
	char *message)
{
	if (!err)
		return ;
	err->code = code;
	err->line = line;
	err->identifier = identifier;
	err->value = value;
	err->message = message;
}
