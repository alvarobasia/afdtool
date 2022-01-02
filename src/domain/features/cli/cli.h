#ifndef __CLI_H__
#define __CLI_H__

#include <stdlib.h>
#include <stdio.h>
#include "../utils/utils-cli.h"
#include "../utils/messages.h"
#include "../afd/afd.h"
typedef enum
{
    UNION = 1,
    INTERSSECTION = 2,
    MINIMIZATION = 3,
    VISUALIZATION = 4,
    COMPLEMENT = 5,
    RECOGNIZE = 6
} Operations;

typedef enum readSteps
{
    READ_QTD_STATES = 1,
    READ_STATES = 2,
    READ_QTD_SYMBOLS = 3,
    READ_SYMBOLS = 4,
    READ_QTD_TRANSITIONS = 5,
    READ_TRANSITIONS = 6,
    READ_INIT_STATE = 7,
    READ_QTD_FINAL_STATES = 8,
    READ_FINAL_STATES = 9
} ReadSteps;

typedef struct _CLIErrors
{
    char *message;
} CLIErrors;

typedef struct _CLI
{
    Operations operation;
    char *inputFile;
    char *secondFile;
    char *output;
    signed short int volatile hasAnError;
    CLIErrors *error;
} CLI;

CLI *createCLI(int argc, char *argv[]);

Operations getOperation(char *comand);

Operations getOperationByText(char *comand);

CLIErrors *isValidImputs(int argc, char *argv[]);

AFD *readFile(CLI *cli, char *fileName);

void *writeFile(AFD *afd, char *fileName);

#endif