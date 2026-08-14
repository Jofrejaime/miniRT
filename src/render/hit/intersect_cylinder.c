#include "hit.h"

static t_quadratic cylinder_equation(
    t_ray ray,
    t_cylinder *cy)
{
    t_quadratic    eq;
    t_vec3         oc;
    t_vec3         oc_perp;
    t_vec3         dir_perp;

    oc = vec3_sub(ray.origin, cy->center);

    oc_perp = vec3_sub(
        oc,
        vec3_scale(cy->axis,
            vec3_dot(oc, cy->axis)));

    dir_perp = vec3_sub(
        ray.dir,
        vec3_scale(cy->axis,
            vec3_dot(ray.dir, cy->axis)));

    eq.a = vec3_dot(dir_perp, dir_perp);

    eq.b = 2.0
        * vec3_dot(oc_perp, dir_perp);

    eq.c = vec3_dot(oc_perp, oc_perp)
        - (cy->radius * cy->radius);

    eq.delta = (eq.b * eq.b)
        - (4.0 * eq.a * eq.c);

    return (eq);
}

static double solve_cylinder(
    t_quadratic eq)
{
    double t1;
    double t2;

    if (eq.delta < 0)
        return (-1);

    t1 = (-eq.b - sqrt(eq.delta))
        / (2.0 * eq.a);

    t2 = (-eq.b + sqrt(eq.delta))
        / (2.0 * eq.a);

    return (smallest_positive_root(t1, t2));
}

static int inside_height(
    t_cylinder *cy,
    t_vec3 point)
{
    double proj;

    proj = vec3_dot(
        vec3_sub(point, cy->center),
        cy->axis);

    return (
        proj >= -(cy->height / 2.0)
        &&
        proj <= (cy->height / 2.0)
    );
}

static double cylinder_side_distance(
    t_ray ray,
    t_cylinder *cy)
{
    t_quadratic eq;
    double      t;
    t_vec3      point;

    eq = cylinder_equation(ray, cy);

    t = solve_cylinder(eq);

    if (t < EPSILON)
        return (-1);

    point = ray_at(ray, t);

    if (!inside_height(cy, point))
        return (-1);

    return (t);
}

static t_vec3 cylinder_side_normal(
    t_cylinder *cy,
    t_vec3 point)
{
    double  proj;
    t_vec3  axis_point;

    proj = vec3_dot(
        vec3_sub(point, cy->center),
        cy->axis);

    axis_point = vec3_add(
        cy->center,
        vec3_scale(cy->axis, proj));

    return (
        vec3_normalize(
            vec3_sub(point, axis_point)));
}

int intersect_cylinder(
    t_ray ray,
    t_object *obj,
    t_hit *hit)
{
    t_cylinder  *cy;
    double      t;
    t_vec3      normal;

    cy = (t_cylinder *)obj->data;

    t = cylinder_side_distance(ray, cy);

    if (t < EPSILON)
        return (0);

    normal = cylinder_side_normal(
        cy,
        ray_at(ray, t));

    hit_fill(
        hit,
        ray,
        t,
        normal,
        obj);

    return (1);
}
