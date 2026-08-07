#ifndef PARSER_H
# define PARSER_H

# include "minirt.h"
# include "token.h"
# include "errors.h"
# include "vec3.h"

void	ft_free_arr(char **arr);
int		ft_arrlen(char **arr);

t_ambient	*analyse_ambiente(char **line);
int parse_map(int fd, t_scene *scene);
t_error	verify_args(int ac, char **av);
t_error validate_token(t_token *token);

/* Core */
t_error parse_scene(t_rt *rt, t_token *tokens);
t_error parse_element(t_rt *rt, t_token *token);

/* Validation */
t_error validate_token(t_token *token);
t_error expect_token_count(t_token *token, int expected);
t_error validate_scene(t_rt *rt);

/* Converters */
t_error parse_int(int *value, char *str);
t_error parse_double(double *value, char *str);
t_error parse_vec3(t_vec3 *vec, char *str);
t_error parse_color(t_color *color, char *str);

/* Elements */
t_error parse_ambient(t_rt *rt, t_token *token);
t_error parse_camera(t_rt *rt, t_token *token);
t_error parse_light(t_rt *rt, t_token *token);

t_error parse_sphere(t_rt *rt, t_token *token);
t_error parse_plane(t_rt *rt, t_token *token);
t_error parse_cylinder(t_rt *rt, t_token *token);

/*Utils */
int valid_orientation(t_vec3 v);
int is_zero_vector(t_vec3 v);

#endif