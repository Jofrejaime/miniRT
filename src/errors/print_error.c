#include "errors.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

void print_error(t_error_info *err)
{
	if (!err)
		return ;
	ft_putendl_fd("Error", STDERR_FILENO);
	if (err->line > 0)
		dprintf(STDERR_FILENO,
		"Line: %d\n",
		err->line);
	if (err->identifier)
		dprintf(STDERR_FILENO,
		"Element: %s\n",
		err->identifier);
	if (err->value)
		dprintf(STDERR_FILENO,
		"Value: %s\n",
		err->value);
	ft_putendl_fd(
		(char *)error_msg(err->code),
		STDERR_FILENO);
	if (err->message)
		ft_putendl_fd(
		err->message,
		STDERR_FILENO);
}

