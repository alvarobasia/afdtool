#include <stdlib.h>
#include <stdio.h>
#include "./domain/features/cli/cli.h"
#include "./domain/features/afd/afd.h"
#include "./domain/features/operations/complement/complement.h"
#include "./domain/features/operations/product/product.h"
#include "./domain/features/operations/intersection/intersection.h"
#include "./domain/features/operations/union/union.h"
#include "./domain/features/operations/visualization/visualization.h"

void getCorrectOperation(CLI *cli, int argc, char *argv[])
{
    switch (cli->operation)
    {
    case UNION:
        unionEntryPoint(cli, readFile(cli, argv[2]), readFile(cli, argv[3]), argc, argv);
        break;
    case INTERSSECTION:
        intersectionEntryPoint(cli, readFile(cli, argv[2]), readFile(cli, argv[3]), argc, argv);
        break;
    case VISUALIZATION:
        visualizationEntryPoint(cli, readFile(cli, cli->inputFile), argc, argv);
        break;
    case COMPLEMENT:
        complementEntryPoint(cli, readFile(cli, cli->inputFile), argc, argv);
        break;
    default:
        printf("Invalid operation");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{

    CLI *cli = createCLI(argc, argv);
    if (cli->error != NULL)
    {
        printf("\e[1;31mERROR:\e[0;37m %s", cli->error->message);
        return EXIT_FAILURE;
    }

    getCorrectOperation(cli, argc, argv);

    return 0;
}
