#include "errors.h"

const char *error_msg(t_error code)
{
	static const char *messages[] = {"No error","Memory allocation failed",
	"Cannot open file","File is empty","Invalid file extension",
	"Ambient light already defined",
	"Camera already defined","Light already defined",
	"Ambient light missing","Camera missing",
	"Light missing","Unknown identifier",
	"Invalid ratio","Invalid field of view",
	"Invalid vector","Invalid color",
	"Invalid sphere","Invalid plane","Invalid cylinder"
	};
	if (code < ERR_NONE || code > ERR_INVALID_CYLINDER)
		return ("Unknown error");
	return (messages[code]);
}
