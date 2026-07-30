#ifndef PARSE_H
# define PARSE_H

#include "../../includes/minirt.h"

t_ambient	*analyse_ambiente(char **line);
int parse_map(int fd, t_scene *scene);
int parse_color(int *r, int *g, int *b, char *line);
int	verify_args(int ac, char **av);
#endif
