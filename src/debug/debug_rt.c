#include "debug.h"

void	debug_scene(t_scene *scene)
{
	if (!scene)
		return ;
	printf("\n========== SCENE ==========\n");
	debug_ambient(scene->ambient);
	printf("\n");
	debug_camera(scene->camera);
	printf("\n");
	debug_light(scene->light);
	printf("\n");
	debug_objects(scene->objects);
	printf("===========================\n");
}

void	debug_rt(t_rt *rt)
{
	if (!rt)
		return ;
	printf("\n======= MINI RT =======\n");
	debug_scene(&rt->scene);
	printf("\n");
	if (rt->error.code)
		debug_error(&rt->error);
	printf("=======================\n");
}
