#ifndef PARSER_H
# define PARSER_H

# include "minirt.h"
# include "token.h"
# include "errors.h"

t_ambient	*analyse_ambiente(char **line);
int parse_map(int fd, t_scene *scene);
int parse_color(int *r, int *g, int *b, char *line);
int	verify_args(int ac, char **av);

t_error parse_scene(t_rt *rt, t_token *tokens);

t_error parse_element(t_rt *rt, t_token *token);

/* Scene */
t_error parse_ambient(t_rt *rt, t_token *token);
t_error parse_camera(t_rt *rt, t_token *token);
t_error parse_light(t_rt *rt, t_token *token);

/* Objects */
t_error parse_sphere(t_rt *rt, t_token *token);
t_error parse_plane(t_rt *rt, t_token *token);
t_error parse_cylinder(t_rt *rt, t_token *token);

/* Converters */
t_error parse_double(double *value, char *str);
t_error parse_int(int *value, char *str);
t_error parse_vec3(t_vec3 *vec, char *str);
t_error parse_color(t_color *color, char *str);

#endif