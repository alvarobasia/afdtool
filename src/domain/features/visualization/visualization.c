#include "visualization.h"

void visualizationEntryPoint(CLI *cli, int argc, char *argv[])
{

    CLIErrors *error = NULL;
    int bufferLength = 255;
    char buffer[bufferLength];
    AFD *afd = getEmptyAFD();

    if (argc != 5)
    {
        error = malloc(sizeof(CLIErrors));
        error->message = INVALID_ARGUMENTS_NUMBER;
        cli->error = error;
        cli->hasAnError = 1;
        return;
    }
    if (argv[2] == NULL || argv[4] == NULL)
    {
        error = malloc(sizeof(CLIErrors));
        error->message = NOT_PROVIDER_A_FILE;
    }

    if (strcmp("--output", argv[3]) != 0)
    {
        error = malloc(sizeof(CLIErrors));
        error->message = NOT_PROVIDER_A_OUTPUT_FILE_FLAG;
    }

    if (error != NULL)
    {
        cli->error = error;
        cli->hasAnError = 1;
        return;
    }

    cli->inputFile = argv[2];
    cli->secondFile = argv[4];

    FILE *inputFile = fopen(cli->inputFile, "r");
    if (inputFile == NULL)
    {
        error = malloc(sizeof(CLIErrors));
        error->message = NOT_PROVIDER_A_FILE;
        cli->error = error;
        cli->hasAnError = 1;
        return;
    }

    char number0fStates = fgetc(inputFile);
    afd->qtd_states = number0fStates - '0';
}