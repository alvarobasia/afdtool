#include <stdlib.h>
#include <stdio.h>

typedef struct _AFD
{
    int qtdEstados;
    char *estados;
    int qtdAlfabeto;
    char *alfabeto;
    int qtdTransicao;
    char *transicao;
    char *estInicial;
    int qtdEstFinal;
    char *estFinal;
}AFD;