#include <stdlib.h>
#include <stdio.h>
#include "./domain/features/cli/cli.h"
#include "./domain/features/afd/afd.c"
#include "./domain/features/operations/complemento.c"


int main(int argc, char *argv[])
{

    // CLI *cli = createCLI(argc, argv);
    // if (cli->error != NULL)
    // {
    //     printf("\e[1;31mERROR:\e[0;37m %s", cli->error->message);
    //     return EXIT_FAILURE;
    // }

    AFD *afd;

    //estados
    afd->qtd_states = 2;
    afd->states[0] = "par";
    afd->states[1] = "impar";

    //alfabeto
    afd->qtd_symbols = 2;
    afd->symbols[0] = "0";
    afd->symbols[1] = "1";

    //transições
    afd->transitions[0]->from = "par";
    afd->transitions[0]->read = "0";
    afd->transitions[0]->to = "impar";

    afd->transitions[0]->from = "par";
    afd->transitions[0]->read = "1";
    afd->transitions[0]->to = "impar";

    afd->transitions[0]->from = "impar";
    afd->transitions[0]->read = "0";
    afd->transitions[0]->to = "par";
    
    afd->transitions[0]->from = "impar";
    afd->transitions[0]->read = "1";
    afd->transitions[0]->to = "par";

    //estado inicial
    afd->initial_state = "par";

    //estado final
    afd->qtd_final_states = 1;
    afd->final_states = "par";

    AFD *afd_complemento = complementacao(afd);

    printf("estados finais entrada:");
    for(int i=0; i<afd->qtd_final_states; i++){
        printf(afd->final_states[i]);
    }

    printf("estados finais complemento:");
    for(int i=0; i<afd_complemento->qtd_final_states; i++){
        printf(afd_complemento->final_states[i]);
    }
    
    return 0;
}
