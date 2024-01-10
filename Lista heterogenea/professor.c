#include <stdio.h>
#include <stdlib.h>
#include "professor.h"

struct prof{
	char* nome;
	int matricula;
};

Prof* criaProf(Prof* prof, char* nome, int mat){
	prof = (Prof*) malloc (sizeof(Prof));

	prof->nome = strdup(nome);
    prof->matricula = mat;
	
	return prof;
}

void imprimeProf(Prof* prof){
	printf("Professor: %s, Matricula: %d\n", prof->nome, prof->matricula);
}

int retornaMatProf(Prof* prof){
    return prof->matricula;    
}

char* retornaNomeProf(Prof* prof){
    return prof->nome;
}

void destroiProf(Prof* prof){
	free(prof->nome);
    free(prof);
}