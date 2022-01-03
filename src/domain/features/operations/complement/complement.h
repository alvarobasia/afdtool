#ifndef __COMPLEMENT_H__
#define __COMPLEMENT_H__
#endif

#include "../../cli/cli.h"
#include "../../utils/messages.h"
#include "../../afd/afd.h"

void complementacao(AFD entry, FILE *file);

void complementEntryPoint(CLI *cli, AFD *afd, int argc, char *argv[]);