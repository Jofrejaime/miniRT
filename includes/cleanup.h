/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 12:52:58 by jmutumbu          #+#    #+#             */
/*   Updated: 2026/09/14 12:52:59 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANUP_H
# define CLEANUP_H
# include "minirt.h"

typedef struct s_rt		t_rt;
typedef struct s_scene	t_scene;

void					rt_destroy(t_rt *rt);
void					scene_destroy(t_scene *scene);

#endif
