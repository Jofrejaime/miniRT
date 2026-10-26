/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 15:13:01 by jmutumbu          #+#    #+#             */
/*   Updated: 2026/08/19 15:13:02 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_error	parse_int(int *value, char *str)
{
	int	i;

	if (!value || !str || !*str)
		return (ERR_INVALID_NUMBER);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (ERR_INVALID_NUMBER);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (ERR_INVALID_NUMBER);
		i++;
	}
	*value = ft_atoi(str);
	return (ERR_NONE);
}
