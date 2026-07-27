/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:00:00 by lvitorin          #+#    #+#             */
/*   Updated: 2026/07/27 15:00:00 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <stdio.h>

#define EPSILON 0.000001

static int  double_equal(double a, double b)
{
    return (fabs(a - b) < EPSILON);
}

static int  vec3_equal(t_vec3 a, t_vec3 b)
{
    return (double_equal(a.x, b.x)
        && double_equal(a.y, b.y)
        && double_equal(a.z, b.z));
}

static void print_vec3(t_vec3 v)
{
    printf("(%.6f, %.6f, %.6f)", v.x, v.y, v.z);
}

static int  report_vec3(char *name, t_vec3 result, t_vec3 expected)
{
    int passed;

    passed = vec3_equal(result, expected);
    printf("%-20s | esperado ", name);
    print_vec3(expected);
    printf(" | obtido ");
    print_vec3(result);
    printf(" | %s\n", (passed ? "OK" : "FALHOU"));
    return (passed);
}

static int  report_double(char *name, double result, double expected)
{
    int passed;

    passed = double_equal(result, expected);
    printf("%-20s | esperado %.6f | obtido %.6f | %s\n",
        name, expected, result, (passed ? "OK" : "FALHOU"));
    return (passed);
}

int main(void)
{
    int     passed;
    int     total;
    t_vec3  a;
    t_vec3  b;
    t_vec3  result;

    passed = 0;
    total = 0;
    a = (t_vec3){1.0, 2.0, 3.0};
    b = (t_vec3){4.0, -5.0, 6.0};
    printf("Relatorio de testes da lib_vec3\n");
    printf("================================\n");
    total++;
    passed += report_vec3("vec3_add", vec3_add(a, b),
            (t_vec3){5.0, -3.0, 9.0});
    total++;
    passed += report_vec3("vec3_sub", vec3_sub(a, b),
            (t_vec3){-3.0, 7.0, -3.0});
    total++;
    passed += report_vec3("vec3_scale", vec3_scale(a, 2.5),
            (t_vec3){2.5, 5.0, 7.5});
    total++;
    passed += report_double("vec3_dot", vec3_dot(a, b), 12.0);
    total++;
    passed += report_vec3("vec3_cross", vec3_cross(a, b),
            (t_vec3){27.0, 6.0, -13.0});
    total++;
    passed += report_double("vec3_length", vec3_length((t_vec3){3.0, 4.0, 12.0}),
            13.0);
    total++;
    passed += report_vec3("vec3_normalize",
            vec3_normalize((t_vec3){0.0, 3.0, 4.0}),
            (t_vec3){0.0, 0.6, 0.8});
    total++;
    result = vec3_rotate((t_vec3){1.0, 0.0, 0.0},
            (t_vec3){0.0, 0.0, 1.0}, M_PI / 2.0);
    passed += report_vec3("vec3_rotate", result,
            (t_vec3){0.0, 1.0, 0.0});
    printf("================================\n");
    printf("Resultado final: %d/%d testes passaram.\n", passed, total);
    if (passed != total)
        return (1);
    return (0);
}
