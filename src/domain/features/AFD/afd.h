typedef struct _AFD
{
    int qtdEstados;
    char estados[qtdEstados][10];
    int qtdAlfabeto;
    char alfabeto[qtdAlfabeto];
    int qtdTransicao;
    char transicao[qtdTransicao][30];
    char estInicial[10];
    int qtdEstFinal;
    char estFinal[qtdEstFinal][10];
} AFD;