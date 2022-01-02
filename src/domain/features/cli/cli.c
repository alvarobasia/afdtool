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
    cli->inputFile = argv[2];
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

char **splitBySpace(char *line)
{
    char **result = malloc(sizeof(char) * 3);
    char *pch = strtok(line, " ");
    int i = 0;
    while (pch != NULL)
    {
        result[i] = pch;
        pch = strtok(NULL, " ");
        i++;
    }
    return result;
}

AFD *readFile(CLI *cli, char *fileName)
{

    char *fileName = malloc(sizeof(char) * 1000);
    strcpy(fileName, cli->inputFile);

    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        cli->error = malloc(sizeof(CLIErrors));
        cli->error->message = FILE_NOT_FOUND;
        cli->hasAnError = 1;
        return -1;
    }

    char *line = NULL;
    size_t len = 0;
    size_t read;

    ReadSteps readSteps = READ_QTD_STATES;
    AFD *afd = getEmptyAFD();
    int aux = 0;

    while ((read = getline(&line, &len, file)) != -1)
    {
        int end = 0;

        if (end == 1)
        {
            break;
        }

        switch (readSteps)
        {
        case READ_QTD_STATES:
            afd->qtd_states = atoi(line);
            readSteps = READ_STATES;
            aux = atoi(line);
            afd->states = malloc(sizeof(char *) * aux);
            break;
        case READ_STATES:
            afd->states[aux - 1] = malloc(sizeof(char) * 1000);
            strcpy(afd->states[aux - 1], strtok(line, "\n"));
            aux--;
            if (aux == 0)
            {
                readSteps = READ_QTD_SYMBOLS;
            }
            break;
        case READ_QTD_SYMBOLS:
            afd->qtd_symbols = atoi(line);
            readSteps = READ_SYMBOLS;
            aux = atoi(line);
            afd->symbols = malloc(sizeof(char *) * aux);
            break;
        case READ_SYMBOLS:
            afd->symbols[aux - 1] = malloc(sizeof(char) * 1000);
            strcpy(afd->symbols[aux - 1], strtok(line, "/n"));
            aux--;
            if (aux == 0)
            {
                readSteps = READ_QTD_TRANSITIONS;
            }
            break;
        case READ_QTD_TRANSITIONS:
            afd->qtd_transitions = atoi(line);
            readSteps = READ_TRANSITIONS;
            aux = atoi(line);
            afd->transitions = malloc(sizeof(Transition) * aux);
            break;
        case READ_TRANSITIONS:
        {
            Transition *transition = getEmptyTransition();

            char *values = malloc(sizeof(char) * strlen(line));
            strcpy(values, line);

            char **sentences = splitBySpace(values);

            transition->from = strtok(sentences[0], "\n");
            transition->read = strtok(sentences[1], "\n");
            transition->to = strtok(sentences[2], "\n");

            afd->transitions[aux - 1] = *transition;

            aux--;
            if (aux == 0)
            {
                readSteps = READ_INIT_STATE;
            }
            break;
        }
        case READ_INIT_STATE:
            afd->initial_state = line;
            readSteps = READ_QTD_FINAL_STATES;
            break;
        case READ_QTD_FINAL_STATES:
            afd->qtd_final_states = atoi(line);
            readSteps = READ_FINAL_STATES;
            aux = atoi(line);
            afd->final_states = malloc(sizeof(char *) * aux);
            break;
        case READ_FINAL_STATES:
            afd->final_states[aux - 1] = malloc(sizeof(char) * 1000);
            strcpy(afd->final_states[aux - 1], strtok(line, "\n"));
            aux--;
            if (aux == 0)
            {
                end = 1;
            }
            break;
        default:
            break;
        }
    }

    fclose(file);
    return afd;
}

void *writeFile(AFD *afd, char *fileName)
{

    FILE *file = fopen(fileName, "a");

    fprintf(file, "%d\n", afd->qtd_states);
    for (int i = 0; i < afd->qtd_states; i++)
    {
        fprintf(file, "%s\n", strtok(afd->states[i], "\n"));
    }
    fprintf(file, "%d\n", afd->qtd_symbols);
    for (int i = 0; i < afd->qtd_symbols; i++)
    {
        fprintf(file, "%s\n", strtok(afd->symbols[i], "\n"));
    }
    fprintf(file, "%d\n", afd->qtd_transitions);
    for (int i = 0; i < afd->qtd_transitions; i++)
    {
        fprintf(file, "%s %s %s\n", afd->transitions[i].from, afd->transitions[i].read, afd->transitions[i].to);
    }
    fprintf(file, "%s\n", afd->initial_state);
    fprintf(file, "%d\n", afd->qtd_final_states);
    for (int i = 0; i < afd->qtd_final_states; i++)
    {
        fprintf(file, "%s\n", strtok(afd->final_states[i], "\n"));
    }
    fclose(file);
}