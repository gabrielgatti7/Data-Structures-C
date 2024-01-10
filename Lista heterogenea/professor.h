#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct prof Prof;

Prof* criaProf(Prof* prof, char* nome, int mat);
void imprimeProf(Prof* prof);
int retornaMatProf(Prof* prof);
char* retornaNomeProf(Prof* prof);
void destroiProf(Prof* prof);