#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./intersection.h"
#include "../product/product.h"

void intersectionEntryPoint(CLI *cli, AFD *afd1, AFD *afd2, int argc, char *argv[])
{
    CLIErrors *error = NULL;

    if (argc != 6)
    {
        error = malloc(sizeof(CLIErrors));
        error->message = INVALID_ARGUMENTS_NUMBER;
        cli->error = error;
        cli->hasAnError = 1;
        return;
    }
    if (argv[2] == NULL || argv[3] == NULL || argv[5] == NULL)
    {
        error = malloc(sizeof(CLIErrors));
        error->message = NOT_PROVIDER_A_FILE;
    }

    if (strcmp("--output", argv[4]) != 0)
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

    cli->secondFile = argv[5];

    FILE *file = fopen(cli->secondFile, "a");

    if (file == NULL)
    {
        error = malloc(sizeof(CLIErrors));
        error->message = NOT_PROVIDER_A_FILE;
        cli->error = error;
        cli->hasAnError = 1;
        return;
    }

    afdIntersection(*afd1, *afd2, file);
}

void afdIntersection(AFD afd1, AFD afd2, FILE *file)
{
    // Criando a AFD de interseção a partir do produto entre duas AFDs
    AFD intersection = afdProduct(afd1, afd2);

    //Quantidade de estados finais
    int qtdStates = (afd1.qtd_final_states) * (afd2.qtd_final_states);
    intersection.qtd_final_states = qtdStates;

    // Alocar memória para os estados finais
    intersection.final_states = malloc(sizeof(char *) * qtdStates);

    int indexFinalState = 0;
    for (int i = 0; i < afd1.qtd_states; i++)
    {
        // estado da AFD 1
        char *state1 = afd1.states[i];

        for (int j = 0; j < afd2.qtd_states; j++)
        {
            // estado da AFD 2
            char *state2 = afd2.states[j];

            // concatenação entre 2 estados
            int size = strlen(state1);
            char *stateProduct = malloc((size + 1) * sizeof(char));
            strcpy(stateProduct, state1);
            strcat(stateProduct, "and");
            strcat(stateProduct, state2);

            // indicar o estado final da AFD de produto, no caso, os dois estados devem ser finais em suas AFDs de origem
            for (int k = 0; k < afd1.qtd_final_states; k++)
            {
                for (int l = 0; l < afd2.qtd_final_states; l++)
                {
                    if ((strcmp(state1, afd1.final_states[k]) == 0) && (strcmp(state2, afd2.final_states[l]) == 0))
                    {
                        intersection.final_states[indexFinalState] = stateProduct;
                        indexFinalState++;
                    }
                }
            }
        }
    }

    // return intersection;
    writeFile(&intersection, file);
}