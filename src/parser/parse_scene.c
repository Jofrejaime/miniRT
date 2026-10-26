/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 15:10:14 by jmutumbu          #+#    #+#             */
/*   Updated: 2026/08/19 15:10:15 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_error	parse_scene(t_rt *rt, t_token *tokens)
{
	t_error	err;

	while (tokens)
	{
		err = parse_element(rt, tokens);
		if (err)
		{
			rt->error.line = tokens->line;
			set_error(&rt->error, err, tokens->values[0], tokens->raw_line);
			return (err);
		}
		tokens = tokens->next;
	}
	err = validate_scene(rt);
	if (err)
	{
		set_error(&rt->error, err, NULL, NULL);
		return (err);
	}
	return (ERR_NONE);
}
