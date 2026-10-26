/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 19:05:17 by lvitorin          #+#    #+#             */
/*   Updated: 2026/07/27 19:05:20 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_parse_int(char *string, int i, double *num)
{
	while (ft_isdigit(string[i]))
	{
		*num = *num * 10 + (string[i] - '0');
		i++;
	}
	return (i);
}

static int	ft_parse_decimal(char *string, int i, double *num)
{
	double	dizima;

	dizima = 0.1;
	while (ft_isdigit(string[i]))
	{
		*num = *num + (string[i] - '0') * dizima;
		dizima *= 0.1;
		i++;
	}
	return (i);
}

char	ft_isfloat(char *string, double *num)
{
	int	i;

	i = 0;
	*num = 0;
	if (!string)
		return ('\0');
	if (!ft_isdigit(string[0]))
		return (string[0]);
	i = ft_parse_int(string, i, num);
	if (string[i] != '.')
		return (string[i]);
	i = ft_parse_decimal(string, i + 1, num);
	return (string[i]);
}
