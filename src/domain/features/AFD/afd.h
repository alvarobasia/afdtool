/** 
Estrutura para representação de uma transicao. Ela utiliza os indices dos elementos no array do AFD.
-> from: estado em que se encontra o AFD no momento da transicao
-> read: simbolo que a AFD ira realizar a leitura no momento da transicao
-> to: estado para o qual a AFD irá apos a realizaçao da transicao
**/
typedef struct transition_est
{
  int *from;
  int *read;
  int *to;
} Transition;

/**
Estrutura para representaçao de uma AFD
-> states: array de estados de acordo com a quantidade de qtd_states.
-> alphabet: array de simbolos de acordo com a quantidade de qtd_symbols.
-> initial_state: estado inicial da AFD.
-> final_states: estados finais da AFD de acordo com a quantidade de qtd_final_states.
-> transitions: array de transicoes de acordo com o tamanho de qtd_transitions.
**/

typedef struct afd_est
{
    char **states;
    int qtd_states;

    char **alphabet;
    int *qtd_symbols;

    int *initial_state;

    char *final_states;
    int *qtd_final_states;

    Transition **transitions;
    int *qtd_transitions;
    
} AFD;
