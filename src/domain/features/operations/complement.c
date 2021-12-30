#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../afd/afd.h"

AFD complementacao(AFD entrada)
{
    AFD ent = entrada;
    AFD complemento;
    int qtd = ent.qtd_states - ent.qtd_final_states;
    char **comp_final_states = malloc(sizeof(char)*qtd);
    int cont = 0, position = 0;
    // char *state, *newState = malloc(sizeof(char));

    // verificando quais estados não são finais no AFD de entrada e adicionando-os como
    // estados finais no AFD de complemento

    for (int i=0; i < ent.qtd_states; i++)
    {
        for (int j=0; j < ent.qtd_final_states; j++)
        {
            if (!(strcmp(ent.states[i],ent.final_states[j]) == 0))
            {   
                cont++;
            }
        }
        if (cont == ent.qtd_final_states)
        {   
            strcpy(comp_final_states[position], ent.states[i]);
            printf("\nestado final dentro: %s", comp_final_states[position]);
            position++;    
        }
        cont = 0;
    }

    complemento = ent;
    complemento.qtd_final_states = qtd;
    complemento.final_states = NULL;
    complemento.final_states = realloc(comp_final_states, (sizeof(char)*qtd));
    complemento.final_states = comp_final_states;
    return complemento;

}