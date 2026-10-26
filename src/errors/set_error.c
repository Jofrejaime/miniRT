/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:31:50 by jmutumbu          #+#    #+#             */
/*   Updated: 2026/09/14 14:31:52 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

void	set_error(t_error_info *err, t_error code, char *identifier,
		char *value)
{
	if (!err)
		return ;
	err->code = code;
	err->identifier = identifier;
	err->value = value;
	err->message = 0;
}
