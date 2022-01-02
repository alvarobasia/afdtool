#include "visualization.h"

void visualizationEntryPoint(CLI *cli, AFD *afd, int argc, char *argv[])
{

    CLIErrors *error = NULL;

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

    cli->secondFile = argv[4];

    FILE *file = fopen(cli->secondFile, "a");

    if (file == NULL)
    {
        error = malloc(sizeof(CLIErrors));
        error->message = NOT_PROVIDER_A_FILE;
        cli->error = error;
        cli->hasAnError = 1;
        return;
    }

    visualization(afd, file);
}

void visualization(AFD *afd, FILE *file)
{
    char *final = "";

    for (int i = 0; i < afd->qtd_final_states; i++)
    {
        char *aux = malloc((sizeof(char) * strlen(final) + 1) + (sizeof(char) * strlen(afd->final_states[i]) + 1));
        strcpy(aux, final);
        final = malloc((sizeof(char) * strlen(final) + 1) + (sizeof(char) * strlen(afd->final_states[i]) + 1));
        strcat(aux, afd->final_states[i]);
        strcat(aux, " ");
        strcpy(final, aux);
    }
    fprintf(file, "digraph finite_state_machine {\n");
    fprintf(file, "\trankdir=LR;\n");
    fprintf(file, "\tnode [shape = doublecircle]; %s;\n", final);
    fprintf(file, "\tnode [shape = circle];\n");
    for (int i = 0; i < afd->qtd_transitions; i++)
    {
        fprintf(file, "\t%s -> %s [ label = \"%s\" ];\n", afd->transitions[i].from, afd->transitions[i].to, afd->transitions[i].read);
    }
    fprintf(file, "}\n");
    fclose(file);
}