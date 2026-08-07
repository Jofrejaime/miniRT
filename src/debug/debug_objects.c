#include "debug.h"

void	debug_ambient(t_ambient *ambient)
{
	if (!ambient)
	{
		printf("Ambient: NULL\n");
		return ;
	}
	printf("Ambient\n");
	printf("  Ratio: %.2f\n", ambient->ratio);
	printf("  Color: ");
	debug_color(ambient->color);
	printf("\n");
}

void	debug_camera(t_camera *camera)
{
	if (!camera)
	{
		printf("Camera: NULL\n");
		return ;
	}
	printf("Camera\n");
	printf("  Position : ");
	debug_vec3(camera->pos);
	printf("\n");
	printf("  Direction: ");
	debug_vec3(camera->dir);
	printf("\n");
	printf("  FOV      : %.2f\n", camera->fov);
}

void	debug_light(t_light *light)
{
	if (!light)
	{
		printf("Light: NULL\n");
		return ;
	}
	printf("Light\n");
	printf("  Position: ");
	debug_vec3(light->pos);
	printf("\n");
	printf("  Ratio   : %.2f\n", light->ratio);
	printf("  Color   : ");
	debug_color(light->color);
	printf("\n");
}

void	debug_sphere(t_sphere *sp)
{
	printf("  Sphere\n");
	printf("    Center: ");
	debug_vec3(sp->center);
	printf("\n");
	printf("    Radius: %.4f\n", sp->radius);
}

void	debug_plane(t_plane *pl)
{
	printf("  Plane\n");
	printf("    Point : ");
	debug_vec3(pl->point);
	printf("\n");
	printf("    Normal: ");
	debug_vec3(pl->normal);
	printf("\n");
}

void	debug_cylinder(t_cylinder *cy)
{
	printf("  Cylinder\n");
	printf("    Center  : ");
	debug_vec3(cy->center);
	printf("\n");
	printf("    Axis    : ");
	debug_vec3(cy->axis);
	printf("\n");
	printf("    Diameter: %.4f\n", cy->diameter);
	printf("    Height  : %.4f\n", cy->height);
}

void	debug_object(t_object *obj)
{
	if (!obj)
		return ;
	printf("  Color: ");
	debug_color(obj->color);
	printf("\n");
	if (obj->type == OBJ_SPHERE)
		debug_sphere((t_sphere *)obj->data);
	else if (obj->type == OBJ_PLANE)
		debug_plane((t_plane *)obj->data);
	else if (obj->type == OBJ_CYLINDER)
		debug_cylinder((t_cylinder *)obj->data);
}

void	debug_objects(t_object *objects)
{
	int	i;

	i = 0;
	while (objects)
	{
		printf("Object[%d]\n", i++);
		debug_object(objects);
		objects = objects->next;
	}
}
