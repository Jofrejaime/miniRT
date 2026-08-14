/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:13:55 by lvitorin          #+#    #+#             */
/*   Updated: 2025/06/19 10:53:43 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_world(char const *s, char c)
{
	int			i;
	int			count_world;

	i = 0;
	count_world = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count_world++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count_world);
}

static int	len_world(char const *s, int start, char c)
{
	int	i;

	i = start;
	while (s[i] && s[i] != c)
		i++;
	return (i - start);
}

static void	clean_memory(char **pt, int l)
{
	while (l-- > 0)
		free(pt[l]);
	free(pt);
}

static void	principal(const char *s, char c, char **pt)
{
	int		l;
	int		j;
	int		i;

	l = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			pt[l] = (char *)malloc((len_world(s, i, c) + 1) * sizeof(char));
			if (!pt[l])
				return (clean_memory(pt, l));
			j = 0;
			while (s[i] != c && s[i])
				pt[l][j++] = s[i++];
			pt[l++][j] = '\0';
		}
	}
	pt[l] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**pt;

	pt = (char **)malloc((count_world(s, c) + 1) * sizeof(char *));
	if (!pt)
		return (NULL);
	principal(s, c, pt);
	return (pt);
}
/*int	main()
{
#include <stdio.h>
	int	i = 0;
	char	**pt = ft_split("ola mundo", 'n');

	while (pt[i])
	{
		printf("%s\n",pt[i]);
		i++;
	}

}*/
