#include <stdlib.h>
#include <stdio.h>
#include "./domain/features/cli/cli.h"
#include "./domain/features/afd/afd.h"
#include "./domain/features/operations/complement.h"

int main(int argc, char *argv[])
{

    // CLI *cli = createCLI(argc, argv);
    // if (cli->error != NULL)
    // {
    //     printf("\e[1;31mERROR:\e[0;37m %s", cli->error->message);
    //     return EXIT_FAILURE;
    // }

    AFD *afd = getEmptyAFD();

    // //estados
    afd->qtd_states = 2;
    printf("--------qtd estados:\n%d", afd->qtd_states);

    afd->states = malloc(sizeof(char) * afd->qtd_states);
    afd->states[0] = "par";
    afd->states[1] = "impar";
    printf("\n--------estados:\n%s\n%s", afd->states[0], afd->states[1]);
    
    //alfabeto
    afd->qtd_symbols = 2;
    printf("\n--------qtd do alfabeto:\n%d", afd->qtd_symbols);

    afd->symbols = malloc(sizeof(char) * afd->qtd_symbols);
    afd->symbols[0] = "0";
    afd->symbols[1] = "1";
    printf("\n--------alfabeto:\n%s\n%s", afd->symbols[0], afd->symbols[1]);

    //transições
    afd->qtd_transitions = 4;
    printf("\n--------qtd de transicoes:\n%d", afd->qtd_transitions);

    afd->transitions = malloc(sizeof(Transition) * afd->qtd_transitions);
    afd->transitions[0].from = "par";
    afd->transitions[0].read = "0";
    afd->transitions[0].to = "impar";
    printf("\n--------transicao 0:\n%s - %s - %s", afd->transitions[0].from, afd->transitions[0].read,
                                                    afd->transitions[0].to);

    afd->transitions[1].from = "par";
    afd->transitions[1].read = "1";
    afd->transitions[1].to = "impar";
    printf("\n--------transicao 1:\n%s - %s - %s", afd->transitions[1].from, afd->transitions[1].read,
                                                    afd->transitions[1].to);

    afd->transitions[2].from = "impar";
    afd->transitions[2].read = "0";
    afd->transitions[2].to = "par";
    printf("\n--------transicao 2:\n%s - %s - %s", afd->transitions[2].from, afd->transitions[2].read,
                                                    afd->transitions[2].to);

    afd->transitions[3].from = "impar";
    afd->transitions[3].read = "1";
    afd->transitions[3].to = "par";
    printf("\n--------transicao 3:\n%s - %s - %s", afd->transitions[3].from, afd->transitions[3].read,
                                                    afd->transitions[3].to);

    //estado inicial
    afd->initial_state = "par";
    printf("\n--------estado inicial:\n%s", afd->initial_state);

    //estado final
    afd->qtd_final_states = 1;
    printf("\n--------qtd de estados finais:\n%d", afd->qtd_final_states);

    afd->final_states = malloc(sizeof(char) * afd->qtd_final_states);
    afd->final_states[0] = "par";
    printf("\n--------estados finais:\n%s", afd->final_states[0]);

    printf("\n\n------------------------COMPLEMENTO------------------------------");
    AFD *afd_complemento = getEmptyAFD();
    complementacao(afd, afd_complemento);

    printf("\n------------Estados finais:");
    for(int i=0; i<afd_complemento->qtd_final_states; i++){
        printf("entrou");
        printf("\n%s",afd_complemento->final_states[0]);
    }

    freeAFD(afd);
    freeAFD(afd_complemento);
    return 0;
}
