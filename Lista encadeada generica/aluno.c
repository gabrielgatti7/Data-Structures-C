#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

struct aluno{
	char* nome;
	int matricula;
	float cr;
};

Aluno* criaAluno(Aluno* aluno, char* nome, int mat, float cr){
	aluno = (Aluno*) malloc (sizeof(Aluno));

	aluno->nome = strdup(nome);
    aluno->matricula = mat;
	aluno->cr = cr;

	return aluno;
}

void imprimeAluno(Aluno* aluno){
	printf("Nome: %s, Matricula: %d, CR: %f\n", aluno->nome, aluno->matricula, aluno->cr);
}

int retornaMat(Aluno* aluno){
    return aluno->matricula;    
}

float retornaCR(Aluno* aluno){
    return aluno->cr;    
}

char* retornaNome(Aluno* aluno){
    return aluno->nome;
}

void destroiAluno(Aluno* aluno){
	free(aluno->nome);
    free(aluno);
}