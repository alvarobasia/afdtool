#include <stdio.h>
#include "../../../features/afd/afd.h"
#include "../../cli/cli.h"
#include "../../utils/messages.h"

/**
 Método utilizado para gerar uma união entre AFDs.
 Ela recebe duas AFDs que irão realizar a operação de produto 
 e retorna a AFD correspondente a união entre elas.
 **/
void afdUnion(AFD afd1, AFD afd2, FILE *file);
void unionEntryPoint(CLI *cli, AFD *afd1, AFD *afd2, int argc, char *argv[]);