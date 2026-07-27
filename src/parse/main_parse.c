
#include "parse.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("numero de parametros invalido!\n");
        return (1);
    }

    if (!analyze_extent(argv[1], "rt"))
        printf("Formatdo de documento errado\n");
    else
        printf("Sucesso");
}