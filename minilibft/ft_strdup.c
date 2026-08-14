/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:37:12 by lvitorin          #+#    #+#             */
/*   Updated: 2025/06/16 18:53:16 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*pt;

	if (!s)
		return (NULL);
	pt = (char *)malloc((ft_strlen(s) + 1));
	if (!pt)
		return (NULL);
	pt = (char *)ft_memcpy(pt, s, ft_strlen(s));
	pt[ft_strlen(s)] = '\0';
	return (pt);
}
