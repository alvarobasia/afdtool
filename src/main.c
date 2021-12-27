#include <stdlib.h>
#include <stdio.h>
#include "./domain/features/cli/cli.h"
#include "./domain/features/visualization/visualization.h"

void execCorrectOperation(CLI *cli, int argc, char *argv[])
{
    switch (cli->operation)
    {
    case UNION:
        break;
    case INTERSSECTION:
        break;
    case MINIMIZATION:
        break;
    case VISUALIZATION:
        visualizationEntryPoint(cli, argc, argv);
        break;
    case COMPLEMENT:
        break;
    case RECOGNIZE:
        break;
    default:
        break;
    }
}

void execError(CLI *cli)
{
    if (cli->hasAnError)
    {
        printf("\e[1;31mERROR:\e[0;37m %s", cli->error->message);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{

    CLI *cli = createCLI(argc, argv);
    execError(cli);
    execCorrectOperation(cli, argc, argv);
    execError(cli);

    return 0;
}
