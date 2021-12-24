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
-> symbols: array de simbolos de acordo com a quantidade de qtd_symbols.
-> initial_state: estado inicial da AFD.
-> final_states: estados finais da AFD de acordo com a quantidade de qtd_final_states.
-> transitions: array de transicoes de acordo com o tamanho de qtd_transitions.
**/

typedef struct afd_est
{
  char **states;
  int qtd_states;

  char **symbols;
  int *qtd_symbols;

  int *initial_state;

  char *final_states;
  int *qtd_final_states;

  Transition **transitions;
  int *qtd_transitions;

} AFD;

/**
Metodo que retorna uma instancia de transicao, passando a AFD alvo,
e os campos necessários na estrutura de transicao.
**/
Transition *getTransition(AFD afd, char *from, char *to, char *read);

/**
  Metodo para alocacao de memoria e retorna uma transicao vazia.
 **/
Transition *getEmptyTransition();

/**
  Metodo que busca e retorna a posicao de um estado dentro da AFD,
  é necessario saber a AFD utilizada e o estado a ser encontrado.
  Se o estado não for encontrado, o valor -1 é retornado. 
  **/
int getStatePosition(AFD afd, char *state);

/**
  Metodo que busca e retorna a posicao de um simbolo dentro da AFD,
  é necessario saber a AFD utilizada e o simbolo a ser encontrado.
  Se o simbolo não for encontrado, o valor -1 é retornado. 
  **/
int getSymbolPosition(AFD afd, char *symbol);

/**
  Método que retorna uma AFD vazia.
   **/
AFD *getEmptyAFD();

/**
  Método que faz a leitura de uma AFD a partir de um arquivo informado.
  E retorna a AFD correspondente.
   **/
AFD *readAFD(char *fileName);

/**
  Método que escreve a AFD informada no arquivo informado.
   **/
void writeAFD(AFD afd, char *fileName);

/**
  Método que libera memoria alocada por uma AFD.
   **/
void freeAFD(AFD *afd);