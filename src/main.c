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
    printf("%d", afd->qtd_states);
    afd->states = malloc(sizeof(char) * afd->qtd_states);
    afd->states[0] = "par";
    afd->states[1] = "impar";
    printf("%s", afd->states[1]);
    // // //alfabeto
    // afd->qtd_symbols = 2;
    // afd->symbols[0] = "0";
    // afd->symbols[1] = "1";

    // // //transições
    // afd->transitions[0].from = "par";
    // afd->transitions[0].read = "0";
    // afd->transitions[0].to = "impar";

    // afd->transitions[1].from = "par";
    // afd->transitions[1].read = "1";
    // afd->transitions[1].to = "impar";

    // afd->transitions[2].from = "impar";
    // afd->transitions[2].read = "0";
    // afd->transitions[2].to = "par";

    // afd->transitions[3].from = "impar";
    // afd->transitions[3].read = "1";
    // afd->transitions[3].to = "par";

    // // //estado inicial
    // afd->initial_state = "par";

    // //estado final
    // afd->qtd_final_states = 1;
    // afd->final_states[0] = "par";

    // printf("%s", afd->states[0]);

    // AFD *afd_complemento = complementacao(afd);

    // printf("estados finais entrada:");
    // for (int i = 0; i < afd->qtd_final_states; i++)
    // {
    //     printf("%s", afd->final_states[i]);
    // }

    // printf("estados finais complemento:");
    // for(int i=0; i<afd_complemento->qtd_final_states; i++){
    //     printf(afd_complemento->final_states[i]);
    // }

    return 0;
}
