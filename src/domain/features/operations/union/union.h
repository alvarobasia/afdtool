#include <stdio.h>
#include "../../../features/afd/afd.h"

/**
 Método utilizado para gerar uma união entre AFDs.
 Ela recebe duas AFDs que irão realizar a operação de produto 
 e retorna a AFD correspondente a união entre elas.
 **/
AFD afdUnion(AFD afd1, AFD afd2);