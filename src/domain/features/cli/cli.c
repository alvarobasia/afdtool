#include "cli.h"
#include <inttypes.h>
#include <string.h>

CLIErrors *isValidImputs(int argc, char *argv[])
{
    CLIErrors *error = NULL;

    if (argc < 3)
    {
        error = malloc(sizeof(CLIErrors));
        error->message = INVALID_ARGUMENTS_NUMBER;
    }

    // if (strcmp(getPrefixOfCliInput(argv[1]), "--") != 0)
    // {
    //     error = malloc(sizeof(CLIErrors));
    //     error->message = INVALID_PREFIX_OPERATION;
    // }

    return error;
}

CLI *createCLI(int argc, char *argv[])
{
    CLIErrors *error = isValidImputs(argc, argv);
    CLI *cli = (CLI *)malloc(sizeof(CLI));
    if (error != NULL)
    {
        cli->error = error;
        return cli;
    }
    return cli;
    // Operations operation = getOperation(argv[1]);
}

Operations *getOperation(char *comand)
{
}
