/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:10:20 by lvitorin          #+#    #+#             */
/*   Updated: 2026/09/04 16:10:23 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	ft_free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_arrlen(char **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	destroy_tokens(t_token *tokens)
{
	t_token	*next;

	while (tokens)
	{
		next = tokens->next;
		ft_free_arr(tokens->values);
		free(tokens->raw_line);
		free(tokens);
		tokens = next;
	}
}
