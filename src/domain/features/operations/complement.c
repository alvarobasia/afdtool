#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../afd/afd.h"

void *complementacao(AFD *entrada, AFD *complemento)
{
    AFD *ent = getEmptyAFD();
    ent = entrada;
    AFD *comp = getEmptyAFD();
    comp = ent;

    printf("\n--------estados de entrada:\n%s\n%s", ent->states[0], ent->states[1]);
    printf("\n--------estado final entrada:\n%s", ent->final_states[0]);
    printf("\n--------estados de complemento\n%s\n%s", comp->states[0], comp->states[1]);

    //limpando os estados finais
    comp->final_states = NULL;
    comp->qtd_final_states = ent->qtd_states-ent->qtd_final_states;
    comp->final_states = malloc(sizeof(char) * comp->qtd_final_states);
    int cont = 0, position = 0;

    // verificando quais estados não são finais no AFD de entrada e adicionando-os como
    // estados finais no AFD de complemento

    for (int i=0; i < ent->qtd_states; i++)
    {
        for (int j=0; j < ent->qtd_final_states; j++)
        {
            if (strcmp(ent->states[i],ent->final_states[j]) != 0)
            {   
                printf("\nentrou 1");
                cont++;
            }
        }
        if (cont == ent->qtd_final_states)
        {   
            printf("\nentrou 2");
            comp->final_states[position] = ent->states[i];
            position++;
            printf("\nestado final dentro: %s", comp->final_states[position]);
        }
        cont = 0;
    }

    complemento = comp;
    freeAFD(ent);
    freeAFD(comp);
}