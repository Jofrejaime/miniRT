/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:12:17 by lvitorin          #+#    #+#             */
/*   Updated: 2026/09/04 16:12:19 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

//#include "minirt.h"
# include <fcntl.h>
# include <libft.h>

typedef struct s_token
{
	char			**values;
	int				count;
	int				line;
	char			*raw_line;
	struct s_token	*next;
}					t_token;

t_token				*tokenize(int fd);
char				*get_next_line(int fd);
void				destroy_tokens(t_token *tokens);
void				ft_free_arr(char **arr);
int					ft_arrlen(char **arr);

#endif
