#include "parse.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error\nnumero de parametros invalido!\n");
		return (1);
	}
	if (!analyze_extent(argv[1], "rt"))
	{
		printf("Error\nformato de documento errado\n");
		return (1);
	}
	printf("miniRT: ficheiro .rt valido\n");
	return (0);
}
