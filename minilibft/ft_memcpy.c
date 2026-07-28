/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:31:19 by lvitorin          #+#    #+#             */
/*   Updated: 2025/06/13 23:31:21 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*f;

	if (!dest)
		return (NULL);
	if (!src)
		return (dest);
	p = (unsigned char *)src;
	f = (unsigned char *)dest;
	while (p && f && n > 0)
	{
		*f++ = *p++;
		n--;
	}
	return (dest);
}
