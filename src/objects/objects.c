/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:39:32 by jmutumbu          #+#    #+#             */
/*   Updated: 2026/09/14 14:39:36 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*object_new(t_obj_type type, void *data, t_color color)
{
	t_object	*obj;

	obj = malloc(sizeof(t_object));
	if (!obj)
		return (NULL);
	obj->type = type;
	obj->data = data;
	obj->color = color;
	obj->next = NULL;
	return (obj);
}

void	object_add(t_object **objects, t_object *new_object)
{
	t_object	*last;

	if (!objects || !new_object)
		return ;
	if (!*objects)
	{
		*objects = new_object;
		return ;
	}
	last = *objects;
	while (last->next)
		last = last->next;
	last->next = new_object;
}
