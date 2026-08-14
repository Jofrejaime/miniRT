
#include "parser.h"

int main(int argc, char *argv[])
{
    t_scene *scene;
    scene = malloc(sizeof(t_scene));
    if (argc != 2)
    {
        printf("numero de parametros invalido!\n");
        return (1);
    }

    if (!analyze_extent(argv[1], "rt"))
    {
        printf("Formato de documento errado\n");
        return (1);
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        printf("Erro ao abrir o arquivo\n");
        return (1);
    }
    if (!parse_map(fd, scene))
        printf("Erro ao analisar ambiente\n");
    else
        printf("Sucesso\n");
    if (scene->ambient)
        printf("Ratio ambient: %f\n %d %d %d\n", scene->ambient->ratio, scene->ambient->color.r, scene->ambient->color.g, scene->ambient->color.b);
    return (0);
}
