#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./union.h"
#include "../product/product.h"

AFD afdUnion(AFD afd1, AFD afd2)
{
    // Criando a AFD de interseção a partir do produto entre duas AFDs
    AFD unionAFD = afdProduct(afd1, afd2);

    //Quantidade de estados finais
    int qtdStates = (afd1.qtd_final_states) * (afd2.qtd_final_states);
    unionAFD.qtd_final_states = qtdStates;
    char **finalStates = malloc(sizeof(char *) * qtdStates);

    // Alocar memória para os estados finais
    unionAFD.final_states = malloc(sizeof(char *) * qtdStates);

    int indexFinalState = 1;
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
            strcat(stateProduct, "/");
            strcat(stateProduct, state2);

            // indicar o estado final da AFD de produto, no caso, os dois estados devem ser finais em suas AFDs de origem
            for (int k = 0; k < afd1.qtd_final_states; k++)
            {
                for (int l = 0; l < afd2.qtd_final_states; l++)
                {
                    if ((strcmp(state1, afd1.final_states[k]) == 0) || (strcmp(state2, afd2.final_states[l]) == 0))
                    {
                        unionAFD.final_states[indexFinalState - 1] = stateProduct;
                        unionAFD.final_states = realloc(unionAFD.final_states, ((indexFinalState + 1) * sizeof(char)));
                        printf("Entrou");
                        printf("%d", indexFinalState);
                        indexFinalState++;
                    }
                }
            }
        }
    }
    unionAFD.qtd_final_states = indexFinalState - 1;

    return unionAFD;
}