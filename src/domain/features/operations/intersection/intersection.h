#include <stdio.h>
#include "../../../features/afd/afd.h"
#include "../../cli/cli.h"
#include "../../utils/messages.h"
#include "../../afd/afd.h"
/**
 Método utilizado para gerar uma interseção entre AFDs.
Ela recebe duas AFDs que irão realizar a operação de produto 
e retorna a AFD correspondente a interseção entre elas.
 **/
void afdIntersection(AFD afd1, AFD afd2, FILE *file);
void intersectionEntryPoint(CLI *cli, AFD *afd1, AFD *afd2, int argc, char *argv[]);