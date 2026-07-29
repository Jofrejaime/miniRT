#include "cleanup.h"

static void destroy_object(t_object *obj)
{
	if (!obj)
		return ;

	free(obj->data);
	free(obj);
}

static void destroy_objects(t_object *objects)
{
	t_object *next;

	while (objects)
	{
		next = objects->next;

		destroy_object(objects);

		objects = next;
	}
}

void scene_destroy(t_scene *scene)
{
	if (!scene)
		return ;

	free(scene->ambient);
	scene->ambient = NULL;

	free(scene->light);
	scene->light = NULL;

	destroy_objects(scene->objects);
	scene->objects = NULL;
}
