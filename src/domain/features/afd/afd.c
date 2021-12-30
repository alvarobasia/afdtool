
#include "./afd.h"

Transition *getTransition(AFD afd, char *from, char *to, char *read)
{
    int fromPosition = getStatePosition(&afd, from);
    int readPosition = getSymbolPosition(&afd, read);
    int toPosition = getStatePosition(&afd, to);

    Transition *transition = malloc(sizeof(Transition));
    transition->from = malloc(sizeof(int));
    transition->read = malloc(sizeof(int));
    transition->to = malloc(sizeof(int));

    *transition->from = fromPosition;
    *transition->read = readPosition;
    *transition->to = toPosition;

    return transition;
}

Transition *getEmptyTransition()
{
    Transition *transition = malloc(sizeof(Transition));
    transition->from = malloc(sizeof(char));
    transition->read = malloc(sizeof(char));
    transition->to = malloc(sizeof(char));
}

int getStatePosition(AFD *afd, char *state)
{
    for (int i = 0; i < afd->qtd_states; i++)
    {
        if (!strcmp(afd->states[i], state))
        {
            return i;
        }
    }
    return -1;
}

int getSymbolPosition(AFD *afd, char *symbol)
{
    for (int i = 0; i < afd->qtd_symbols; i++)
    {
        if (!strcmp(afd->symbols[i], symbol))
        {
            return i;
        }
    }
    return -1;
}

AFD *getEmptyAFD()
{
    AFD *afd = malloc(sizeof(AFD));
    afd->qtd_states = (int)malloc(sizeof(int));
    afd->qtd_symbols = (int)malloc(sizeof(int));
    afd->qtd_transitions = (int)malloc(sizeof(int));
    afd->qtd_final_states = (int)malloc(sizeof(int));
    return afd;
}

void freeTransition(Transition *transition)
{
    free(transition->from);
    free(transition->to);
    free(transition->read);
}

void freeAFD(AFD *afd)
{
    for (int i = 0; i < afd->qtd_states; i++)
    {
        free(afd->states[i]);
    }
    for (int i = 0; i < afd->qtd_symbols; i++)
    {
        free(afd->symbols[i]);
    }
    for (int i = 0; i < afd->qtd_transitions; i++)
    {
        freeTransition(&afd->transitions[i]);
    }

    free(afd->transitions);
    free(afd->symbols);
    free(afd->states);
    free(afd->final_states);
    free(afd->initial_state);
}