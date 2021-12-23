#ifndef __CLI_H__
#define __CLI_H__

#include <stdlib.h>
#include <stdio.h>
#include "../utils/utils-cli.h"
#include "../utils/messages.h"

typedef enum
{
    UNION = 1,
    INTERSSECTION = 2,
    MINIMIZATION = 3,
    VISUALIZATION = 4,
    COMPLEMENT = 5,
    RECOGNIZE = 6
} Operations;

typedef struct _CLIErrors
{
    char *message;
} CLIErrors;

typedef struct _CLI
{
    Operations operation;
    char *inputFile;
    char *secondFile;
    signed short int volatile hasAnError;
    CLIErrors *error;
} CLI;

CLI *createCLI(int argc, char *argv[]);

Operations *getOperation(char *comand);

CLIErrors *isValidImputs(int argc, char *argv[]);

#endif