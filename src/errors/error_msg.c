#include "errors.h"

const char *error_msg(t_error code)
{
	static const char *messages[] = {
		"No error",
		"Memory allocation failed",
		"Cannot open file",
		"File is empty",
		"Invalid file extension",
		"Invalid file format",
		"Ambient light already defined",
		"Camera already defined",
		"Light already defined",
		"Ambient light missing",
		"Camera missing",
		"Light missing",
		"No objects in scene",
		"Invalid scene",
		"Unknown identifier",
		"Invalid ratio",
		"Invalid field of view",
		"Invalid vector",
		"Invalid color",
		"Invalid argume ERR_INVALID_SCENEnt count",
		"Invalid orientation vector",
		"Invalid sphere",
		"Invalid plane",
		"Invalid cylinder",
		"Unknown error",
		"Invalid diameter",
		"Invalid height",
		"Invalid token",
		"Invalid token count",
		"Invalid number",
	};
	if (code < ERR_NONE || code > ERR_INVALID_NUMBER)
		return ("Unknown error");
	return (messages[code]);
}
