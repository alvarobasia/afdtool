#include <stdio.h>
#include "../../../features/afd/afd.h"

/**
 Método utilizado para gerar uma interseção entre AFDs.
Ela recebe duas AFDs que irão realizar a operação de produto 
e retorna a AFD correspondente a interseção entre elas.
 **/
AFD afdIntersection(AFD afd1, AFD afd2);