/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:43:07 by jmutumbu          #+#    #+#             */
/*   Updated: 2026/09/14 14:43:08 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "hit.h"
# include "light.h"
# include "minirt.h"

void	render(t_rt *rt, int width, int height);

#endif
