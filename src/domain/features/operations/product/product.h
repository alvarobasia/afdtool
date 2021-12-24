#include <stdio.h>

/**
 Método utilizado para gerar um produto de AFDs.
 Ela recebe as duas AFDs que irão realizar a operação e
 retorna a AFD correspondente ao produto entre elas.
 **/
AFD *afdProduct(AFD *afd1, AFD *afd2);