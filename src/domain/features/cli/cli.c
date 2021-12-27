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

    if (strcmp(getPrefixOfCliInput(argv[1]), "--") != 0)
    {
        error = malloc(sizeof(CLIErrors));
        error->message = INVALID_PREFIX_OPERATION;
    }

    return error;
}

CLI *createCLI(int argc, char *argv[])
{
    CLIErrors *error = isValidImputs(argc, argv);
    CLI *cli = (CLI *)malloc(sizeof(CLI));
    if (error != NULL)
    {
        cli->error = error;
        cli->hasAnError = 1;
        return cli;
    }
    Operations operation = getOperation(argv[1]);

    if (operation == -1)
    {
        cli->error = malloc(sizeof(CLIErrors));
        cli->error->message = INVALID_OPERATION;
        cli->hasAnError = 1;
        return cli;
    }

    cli->operation = operation;
    cli->hasAnError = 0;

    return cli;
}

Operations getOperation(char *comand)
{
    return getOperationByText(comand);
}

Operations getOperationByText(char *comand)
{

    char operationsText[][1000] = {
        "--union",
        "--intersection",
        "--minimization",
        "--dot",
        "--complement",
        "--recognize"};

    Operations operations[] = {
        1, 2, 3, 4, 5, 6};

    for (int i = 0; i < 6; i++)
    {
        if (strcmp(comand, operationsText[i]) == 0)
        {
            return operations[i];
        }
    }

    return -1;
}
