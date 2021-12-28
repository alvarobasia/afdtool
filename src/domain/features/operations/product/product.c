#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "product.h"
#include "afd/afd.h"

/**
 Método para buscar a transicao de um estado usando determinado 
 símbolo dentro da AFD inicial. O retorno é o estado para o qual
 o símbolo indica.
 **/
char *setTransition(AFD *afd, char *symbol, char *state)
{
    for (int i = 0; i < *afd->number_transitions; i++)
    {
        Transition *transition = afd->transitions[i];
        char *from = afd->states[*transition->from];
        char *read = afd->alphabet[*transition->read];
        if (!strcmp(state, from) && !strcmp(symbol, read))
        {
            return afd->states[*transition->to];
        }
    }
}

/**
 Método para indicar qual estado vai receber as transições do estado atual.
 **/
int getFinalPosition(AFD *product, AFD *afd1, AFD *afd2, char *state1, char *state2, char *symbol)
{
    char *value1 = setTransition(afd1, symbol, state1);
    char *value2 = setTransition(afd2, symbol, state2);
    char *aux = strcat(value1, "-");
    char *finalState = strcat(aux, value2);

    int index = -1;
    for (int i = 0; i < *product->qtd_states; i++)
    {
        if (!strcmp(finalState, product->states[i]))
        {
            index = i;
            break;
        }
    }
    free(aux);
    free(finalState);
    return index;
}

AFD *afdProduct(AFD *afd1, AFD *afd2)
{
    // criar AFD vazia
    AFD *product = getEmptyAFD();
    // quantidade de estados (m * n)
    int qtdStates = (*afd1->qtd_states) * (*afd2->qtd_states);
    *product->qtd_states = qtdStates;
    // alocação de memoria para os estados da AFD produto
    product->states = malloc(sizeof(char *) * qtdStates);

    // simbolos utilizados
    *product->qtd_symbols = *afd2->qtd_symbols;
    // product->symbols = malloc((*afd2->qtd_symbols) * sizeof(char *));
    product->symbols = malloc((*product->qtd_symbols) * sizeof(char *));

    // adicionar os simbolos que foram utilizados nas AFDs na AFD do produto
    for (int i = 0; i < *afd2->qtd_symbols; i++)
    {
        char *aux = afd2->symbols[i];
        // char *symbol = copyString(aux);
        char *symbol = malloc(strlen(aux) * sizeof(char));

        for (int j = 0; j < strlen(aux); j++)
        {
            symbol[i] = aux[i];
        }

        product->symbols[i] = symbol;
    }
    // criar estados possíveis realizando o produto entre duas AFDs
    int index = 0;
    for (int i = 0; i < *afd1->qtd_states; i++)
    {
        // estado da AFD 1
        char *state1 = afd1->states[i];
        for (int j = 0; j < *afd2->qtd_states; j++)
        {
            // estado da AFD 2
            char *state2 = afd2->states[j];
            // int size = strlen(state1) + strlen(state2);
            // concatenação entre 2 estados
            char *aux = strcat(state1, "-");
            char *stateProduct = strcat(aux, state2);
            product->states[index] = stateProduct;
            // indicar o estado inicial da AFD de produto, no caso, os dois estados devem ser iniciais em suas AFDs de origem
            if (i == *afd1->initial_state && j == *afd2->initial_state)
            {
                *product->initial_state = index;
            }
            index++;
        }
    }
    // realizar transição dos estados
    *product->qtd_transitions = qtdStates * (*product->qtd_symbols);
    product->transitions = malloc(sizeof(Transition *) * (product->qtd_transitions));

    for (int i = 0; i < product->qtd_states; i++)
    {

        for (int j = 0; j < product->qtd_symbols; j++)
        {
            /* code */
        }
    }

    index = 0;
    // ler os simbolos de cada estado do AFD produto
    for (int i = 0; i < *product->qtd_states; i++)
    {
        char *state = product->states[i];
        // realizar o split do estado para descobrir as transições de cada estado separadamente
        char **split = strtok(state, "-");
        for (int j = 0; j < *product->qtd_symbols; i++)
        {
            char *symbol = product->symbols[j];
            int finalPosition = getFinalPosition(product, afd1, afd2, split[0], split[1], symbol);
            Transition *transition = getEmptyTransition();
            *transition->from = i;
            *transition->read = j;
            *transition->to = finalPosition;
            product->transitions[index] = transition;
            index++;
        }
        free(split[0]);
        free(split[1]);
        free(split);
    }

    return product;
}