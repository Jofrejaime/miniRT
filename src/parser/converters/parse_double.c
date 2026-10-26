/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 15:12:53 by jmutumbu          #+#    #+#             */
/*   Updated: 2026/08/19 15:12:54 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_error	parse_double(double *value, char *str)
{
	char	*endptr;

	if (!value || !str)
		return (ERR_INVALID_NUMBER);
	*value = strtod(str, &endptr);
	if (*endptr != '\0')
		return (ERR_INVALID_NUMBER);
	return (ERR_NONE);
}
