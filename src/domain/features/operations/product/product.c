#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./product.h"

AFD afdProduct(AFD afd1, AFD afd2)
{
    // criar AFD vazia
    AFD *product = getEmptyAFD();
    // quantidade de estados (m * n)
    int qtdStates = (afd1.qtd_states) * (afd2.qtd_states);
    product->qtd_states = qtdStates;
    // alocação de memoria para os estados da AFD produto
    product->states = malloc(sizeof(char *) * qtdStates);

    // simbolos utilizados
    product->qtd_symbols = afd2.qtd_symbols;
    product->symbols = malloc((product->qtd_symbols) * sizeof(char *));

    // adicionar os simbolos que foram utilizados nas AFDs na AFD do produto
    for (int i = 0; i < afd2.qtd_symbols; i++)
    {
        char *aux = afd2.symbols[i];
        int size = strlen(aux);
        char *symbol = malloc((size + 1) * sizeof(char));
        strcpy(symbol, aux);
        product->symbols[i] = symbol;
    }
    // criar estados possíveis realizando o produto entre duas AFDs
    int index = 0;
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
            product->states[index] = stateProduct;
            // indicar o estado inicial da AFD de produto, no caso, os dois estados devem ser iniciais em suas AFDs de origem
            // NÃO ESTÁ FUNCIONANDO
            // if (i == *afd1->initial_state && j == *afd2->initial_state)
            // {
            //     printf("\n%s", product->states[index]);
            //     *product->initial_state = product->states[index];
            // }
            index++;
        }
    }

    // printf("\n\n\n--------estado inicial: %s", product->initial_state);
    // printf("\n\n\n--------estados:");
    // for (int i = 0; i < product->qtd_states; i++)
    // {
    //     printf("\n%s", product->states[i]);
    // }

    // realizar transição dos estados
    product->qtd_transitions = qtdStates * (product->qtd_symbols);
    product->transitions = malloc(sizeof(Transition *) * (product->qtd_transitions));

    index = 0;
    for (int i = 0; i < product->qtd_states; i++)
    {
        char *state = product->states[i];
        printf("\nEstado: %s", state);
        /* 
        Separação dos estados para verificar qual a transição feita por cada 
        para encontrar o estado da transição correspondente na AFD produto.
        */
        int size = 2;
        char *aux;
        char **split = malloc(size * sizeof(char *));
        aux = strtok(state, "/");
        int x = 0;
        while (aux != NULL)
        {
            split[x] = aux;
            aux = strtok(NULL, "/");
            x++;
        }

        for (int j = 0; j < product->qtd_symbols; j++)
        {
            char *symbol = product->symbols[j];
            char *to1;
            char *to2;
            // transição para o estado 1
            for (int k = 0; k < afd1.qtd_transitions; k++)
            {
                if (strcmp(split[0], afd1.transitions[k].from) == 0)
                {
                    if (strcmp(symbol, afd1.transitions[k].read) == 0)
                    {
                        to1 = afd1.transitions[k].to;
                    }
                }
            }
            for (int k = 0; k < afd2.qtd_transitions; k++)
            {
                if (strcmp(split[1], afd2.transitions[k].from) == 0)
                {
                    if (strcmp(symbol, afd2.transitions[k].read) == 0)
                    {
                        to2 = afd2.transitions[k].to;
                    }
                }
            }

            printf("\nSimbolo: %s", symbol);

            char *stateTo = malloc((strlen(to1) + strlen(to2) + 1) * sizeof(char));
            strcpy(stateTo, to1);
            strcat(stateTo, "/");
            strcat(stateTo, to2);

            printf("\nTo: %s", stateTo);

            Transition *transitionProduct = getEmptyTransition();

            // Transition *transitionState1 = getEmptyTransition();
            // for (int k = 0; k < afd1->qtd_transitions; k++)
            // {
            //     Transition *transitionState1 = getEmptyTransition();
            //     // transitionState1->from = afd1->transitions[i].from;
            //     *transitionState1 = afd1->transitions[k];
            //     printf("From: %s", transitionState1->from);
            //     // char *from = afd1->states[transitionState1->from];
            //     // printf("From: %s", from);
            // }

            // Transition *transitionState2 = getEmptyTransition();
        }
    }

    // index = 0;
    // // ler os simbolos de cada estado do AFD produto
    // for (int i = 0; i < *product->qtd_states; i++)
    // {
    //     char *state = product->states[i];
    //     // realizar o split do estado para descobrir as transições de cada estado separadamente
    //     char **split = strtok(state, "-");
    //     for (int j = 0; j < *product->qtd_symbols; i++)
    //     {
    //         char *symbol = product->symbols[j];
    //         int finalPosition = getFinalPosition(product, afd1, afd2, split[0], split[1], symbol);
    //         Transition *transition = getEmptyTransition();
    //         *transition->from = i;
    //         *transition->read = j;
    //         *transition->to = finalPosition;
    //         product->transitions[index] = transition;
    //         index++;
    //     }
    //     free(split[0]);
    //     free(split[1]);
    //     free(split);
    // }

    return *product;
}