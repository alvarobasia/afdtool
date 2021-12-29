#include <stdlib.h>
#include <stdio.h>
#include "./domain/features/cli/cli.h"
#include "./domain/features/afd/afd.h"
#include "./domain/features/operations/complement.h"
#include "./domain/features/operations/product/product.h"
#include "./domain/features/operations/intersection/intersection.h"

int main()
{

    // CLI *cli = createCLI(argc, argv);
    // if (cli->error != NULL)
    // {
    //     printf("\e[1;31mERROR:\e[0;37m %s", cli->error->message);
    //     return EXIT_FAILURE;
    // }

    //*--------------------------------------------------------------*
    AFD *afd = getEmptyAFD();

    // //estados
    afd->qtd_states = 2;
    // printf("--------qtd estados:\n%d", afd->qtd_states);

    afd->states = malloc(sizeof(char) * afd->qtd_states);
    afd->states[0] = "A";
    afd->states[1] = "B";
    // printf("\n--------estados:\n%s\n%s", afd->states[0], afd->states[1]);

    //alfabeto
    afd->qtd_symbols = 2;
    // printf("\n--------qtd do alfabeto:\n%d", afd->qtd_symbols);

    afd->symbols = malloc(sizeof(char) * afd->qtd_symbols);
    afd->symbols[0] = "a";
    afd->symbols[1] = "b";
    // printf("\n--------alfabeto:\n%s\n%s", afd->symbols[0], afd->symbols[1]);

    //transições
    afd->qtd_transitions = 4;
    // printf("\n--------qtd de transicoes:\n%d", afd->qtd_transitions);

    afd->transitions = malloc(sizeof(Transition) * afd->qtd_transitions);
    afd->transitions[0].from = "A";
    afd->transitions[0].read = "a";
    afd->transitions[0].to = "B";
    // printf("\n--------transicao 0:\n%s - %s - %s", afd->transitions[0].from, afd->transitions[0].read,
    //                                                 afd->transitions[0].to);

    afd->transitions[1].from = "A";
    afd->transitions[1].read = "b";
    afd->transitions[1].to = "A";
    // printf("\n--------transicao 1:\n%s - %s - %s", afd->transitions[1].from, afd->transitions[1].read,
    //                                                 afd->transitions[1].to);

    afd->transitions[2].from = "B";
    afd->transitions[2].read = "a";
    afd->transitions[2].to = "A";
    // printf("\n--------transicao 2:\n%s - %s - %s", afd->transitions[2].from, afd->transitions[2].read,
    //                                                 afd->transitions[2].to);

    afd->transitions[3].from = "B";
    afd->transitions[3].read = "b";
    afd->transitions[3].to = "B";
    // printf("\n--------transicao 3:\n%s - %s - %s", afd->transitions[3].from, afd->transitions[3].read,
    //                                                 afd->transitions[3].to);

    //estado inicial
    afd->initial_state = "A";
    // printf("\n--------estado inicial:\n%s", afd->initial_state);

    //estado final
    afd->qtd_final_states = 1;
    // printf("\n--------qtd de estados finais:\n%d", afd->qtd_final_states);

    afd->final_states = malloc(sizeof(char) * afd->qtd_final_states);
    afd->final_states[0] = "A";
    // printf("\n--------estados finais:\n%s", afd->final_states[0]);

    //*--------------------------------------------------------------*
    AFD *afd2 = getEmptyAFD();

    // //estados
    afd2->qtd_states = 2;
    // printf("--------qtd estados:\n%d", afd2->qtd_states);

    afd2->states = malloc(sizeof(char) * afd2->qtd_states);
    afd2->states[0] = "C";
    afd2->states[1] = "D";
    // printf("\n--------estados:\n%s\n%s", afd2->states[0], afd2->states[1]);

    //alfabeto
    afd2->qtd_symbols = 2;
    // printf("\n--------qtd do alfabeto:\n%d", afd2->qtd_symbols);

    afd2->symbols = malloc(sizeof(char) * afd2->qtd_symbols);
    afd2->symbols[0] = "a";
    afd2->symbols[1] = "b";
    // printf("\n--------alfabeto:\n%s\n%s", afd2->symbols[0], afd2->symbols[1]);

    //transições
    afd2->qtd_transitions = 4;
    // printf("\n--------qtd de transicoes:\n%d", afd2->qtd_transitions);

    afd2->transitions = malloc(sizeof(Transition) * afd2->qtd_transitions);
    afd2->transitions[0].from = "C";
    afd2->transitions[0].read = "a";
    afd2->transitions[0].to = "C";
    // printf("\n--------transicao 0:\n%s - %s - %s", afd2->transitions[0].from, afd2->transitions[0].read,
    //                                                 afd2->transitions[0].to);

    afd2->transitions[1].from = "C";
    afd2->transitions[1].read = "b";
    afd2->transitions[1].to = "D";
    // printf("\n--------transicao 1:\n%s - %s - %s", afd2->transitions[1].from, afd2->transitions[1].read,
    //                                                 afd2->transitions[1].to);

    afd2->transitions[2].from = "D";
    afd2->transitions[2].read = "a";
    afd2->transitions[2].to = "D";
    // printf("\n--------transicao 2:\n%s - %s - %s", afd2->transitions[2].from, afd2->transitions[2].read,
    //                                                 afd2->transitions[2].to);

    afd2->transitions[3].from = "D";
    afd2->transitions[3].read = "b";
    afd2->transitions[3].to = "C";
    // printf("\n--------transicao 3:\n%s - %s - %s", afd2->transitions[3].from, afd2->transitions[3].read,
    //                                                 afd2->transitions[3].to);

    //estado inicial
    afd2->initial_state = "C";
    // printf("\n--------estado inicial:\n%s", afd->initial_state);

    //estado final
    afd2->qtd_final_states = 1;
    // printf("\n--------qtd de estados finais:\n%d", afd->qtd_final_states);

    afd2->final_states = malloc(sizeof(char) * afd2->qtd_final_states);
    afd2->final_states[0] = "C";
    // printf("\n--------estados finais:\n%s", afd->final_states[0]);

    AFD product;
    product = afdProduct(*afd, *afd2);

    AFD intersection;
    intersection = afdIntersection(*afd, *afd2);

    printf("\n\n\n--------estado inicial: %s", intersection.initial_state);

    printf("\n\n\n--------estados finais: ");
    for (int i = 0; i < intersection.qtd_final_states; i++)
    {
        printf("\n%s", intersection.final_states[i]);
    }

    printf("\n\n\n--------estados:");
    for (int i = 0; i < intersection.qtd_states; i++)
    {
        printf("\n%s", intersection.states[i]);
    }

    printf("\n\n\n--------simbolos:");
    for (int i = 0; i < intersection.qtd_symbols; i++)
    {
        printf("\n%s", intersection.symbols[i]);
    }

    printf("\n\n\n--------transacoes:");
    for (int i = 0; i < intersection.qtd_transitions; i++)
    {
        printf("\nFrom: %s", intersection.transitions[i].from);
        printf("\nRead: %s", intersection.transitions[i].read);
        printf("\nTo: %s", intersection.transitions[i].to);
        printf("\n\n");
    }

    return 0;
}
