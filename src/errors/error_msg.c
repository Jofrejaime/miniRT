/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:32:10 by jmutumbu          #+#    #+#             */
/*   Updated: 2026/09/14 14:32:11 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

const char	*error_msg(t_error code)
{
	static const char	*messages[] = {
		"No error", "Memory allocation failed",	"Cannot open file",
		"File is empty", "Invalid file extension (expected .rt)",
		"Invalid file format", "Ambient light already defined",
		"Camera already defined", "Light already defined",
		"Ambient light missing", "Camera missing",
		"Light missing", "No objects in scene",
		"Invalid scene", "Unknown identifier",
		"Invalid ratio (expected 0.0 to 1.0)",
		"Invalid field of view (expected 0 to 180)",
		"Invalid vector",
		"Invalid color (expected R,G,B in range 0-255)",
		"Invalid argument count",
		"Invalid orientation vector (expected values in range -1.0 to 1.0)",
		"Invalid sphere", "Invalid plane", "Invalid cylinder",
		"Unknown error", "Invalid diameter (must be > 0)",
		"Invalid height (must be > 0)", "Invalid token",
		"Invalid token count", "Invalid number",
	};

	if (code < ERR_NONE || code > ERR_INVALID_NUMBER)
		return ("Unknown error");
	return (messages[code]);
}
