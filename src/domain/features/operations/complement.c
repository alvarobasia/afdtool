#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../afd/afd.h"

void *complementacao(AFD *entrada, AFD *complemento)
{
    AFD *ent = getEmptyAFD();
    ent = entrada;
    

    // ent->final_states = malloc(sizeof(char) * entrada->qtd_final_states);
    // ent->final_states = entrada->final_states;

    printf("\n--------estados de entrada:\n%s\n%s", ent->states[0], ent->states[1]);
    printf("\n--------estado final entrada:\n%s", ent->final_states[0]);

    //limpando os estados finais
    // comp->final_states = NULL;
    int comp_qtd_final_states = ent->qtd_states-ent->qtd_final_states;
    char **comp_final_states = malloc(sizeof(char) * comp_qtd_final_states);
    int cont = 0, position = 0, size;
    char *state, *newState;
             
    

    // verificando quais estados não são finais no AFD de entrada e adicionando-os como
    // estados finais no AFD de complemento

    for (int i=0; i < ent->qtd_states; i++)
    {
        printf("\n1");
        for (int j=0; j < ent->qtd_final_states; j++)
        {
            printf("\n2");
            if (!(strcmp(ent->states[i],ent->final_states[j]) == 0))
            {   
                printf("\nentrou 1");
                cont++;
            }
        }
        if (cont == ent->qtd_final_states)
        {   
            printf("\nentrou 2");
            printf("\nestado final para entrar: %s",ent->states[i]);
            state = ent->states[i];
            
            size = strlen(state);
            newState = malloc((size + 1) * sizeof(char));
            strcpy(newState, state);
            printf("\nnewState: %s", newState);
            strcpy(comp_final_states[position],newState);
            //comp_final_states[position] = newState;
            printf("\nestado final dentro: %s", comp_final_states[position]);
            position++;
            
        }
        cont = 0;
    }

    complemento = ent;
    complemento->final_states = comp_final_states;

    freeAFD(ent);
    free(comp_final_states);
}