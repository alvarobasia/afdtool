#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "complement.h"

AFD complementacao(AFD entry)
{
    // Criando a AFD
    AFD complement;

    // Quantidade de estados, simbolos, estados finais, transições
    complement.qtd_states = entry.qtd_states;
    complement.qtd_symbols = entry.qtd_symbols;
    int qtdStates = (entry.qtd_states) - (entry.qtd_final_states);
    complement.qtd_final_states = qtdStates;
    complement.qtd_transitions = entry.qtd_transitions;

    // Alocação de memoria para estados, simbolos, estados finais, transições
    complement.states = malloc(sizeof(char *) * complement.qtd_states);
    complement.symbols = malloc(sizeof(char *) * complement.qtd_symbols);
    complement.final_states = malloc(sizeof(char *) * qtdStates);
    complement.transitions = malloc(sizeof(Transition *) * complement.qtd_transitions);

    // Atribuindo valor ao estado inicial
    complement.initial_state = entry.initial_state;

    // Atribuindo valor aos estados
    for (int i = 0; i < entry.qtd_states; i++)
    {
        char *state = entry.states[i];
        char *aux = state;
        int size = strlen(aux);
        char *newState = malloc((size + 1) * sizeof(char));
        strcpy(newState, aux);
        complement.states[i] = newState;
    }

    // Atribuindo valor aos simbolos
    for (int i = 0; i < entry.qtd_symbols; i++)
    {
        char *aux = entry.symbols[i];
        int size = strlen(aux);
        char *symbol = malloc((size + 1) * sizeof(char));
        strcpy(symbol, aux);
        complement.symbols[i] = symbol;
    }

    //Atribuindo valor aos estados finais
    int cont = 0;
    int index = 0;
    for (int i = 0; i < entry.qtd_states; i++)
    {
        char *state = entry.states[i];

        for (int j = 0; j < entry.qtd_final_states; j++)
        {
            if (strcmp(entry.states[i], entry.final_states[j]) != 0)
            {
                cont++;
            }
        }
        if (cont == entry.qtd_final_states)
        {
            char *aux = state;
            int size = strlen(aux);
            char *newState = malloc((size + 1) * sizeof(char));
            strcpy(newState, aux);
            complement.final_states[index] = newState;
            index++;
        }
        cont = 0;
    }

    //Atribuindo valor as transações
    for (int i = 0; i < entry.qtd_transitions; i++)
    {
        Transition *transitionProduct = getEmptyTransition();
        transitionProduct->from = entry.transitions[i].from;
        transitionProduct->read = entry.transitions[i].read;
        transitionProduct->to = entry.transitions[i].to;
        complement.transitions[i] = *transitionProduct;
    }

    return complement;
}
