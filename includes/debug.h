#ifndef DEBUG_H
# define DEBUG_H

# include "minirt.h"
# include "../src/lexer/token.h"

void	debug_vec3(t_vec3 vec);
void	debug_color(t_color color);

void	debug_ambient(t_ambient *ambient);
void	debug_camera(t_camera *camera);
void	debug_light(t_light *light);

void	debug_sphere(t_sphere *sp);
void	debug_plane(t_plane *pl);
void	debug_cylinder(t_cylinder *cy);
void	debug_object(t_object *obj);
void	debug_objects(t_object *objects);

void	debug_scene(t_scene *scene);
void	debug_tokens(t_token *tokens);
void	debug_error(t_error_info *error);
void	debug_rt(t_rt *rt);

#endif
