#include <stdlib.h>
#include <stdio.h>
#include <string.h>

AFD *complementacao(AFD *entrada)
{

    AFD *ent = entrada;
    AFD *comp = ent;

    //limpando os estados finais
    comp->final_states = NULL;
    comp->qtd_final_states = 0;
    int cont = 0, position = 0;

    // verificando quais estados não são finais no AFD de entrada e adicionando-os como
    // estados finais no AFD de complemento

    for (int i; i < ent->qtd_states; i++)
    {
        for (int j; j < ent->qtd_final_states; j++)
        {
            if (ent->states[i] != ent->final_states[j])
            {
                cont++;
            }
        }
        if (cont == ent->qtd_final_states)
        {
            comp->final_states[position] = ent->states[i];
            comp->qtd_final_states++;
            position++;
        }
        cont = 0;
    }

    free(ent);
    return comp;
}