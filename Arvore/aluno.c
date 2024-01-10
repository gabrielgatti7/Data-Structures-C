#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno{
	char* nome;
	int matricula;
};

Aluno* criaAluno(Aluno* aluno, char* nome, int mat){
	aluno = (Aluno*) malloc (sizeof(Aluno));

	aluno->nome = strdup(nome);
    aluno->matricula = mat;
	
	return aluno;
}

void imprimeAluno(Aluno* aluno){
	printf("Nome: %s, Mat: %d", aluno->nome, aluno->matricula);
}

int retornaMat(Aluno* aluno){
    return aluno->matricula;    
}

char* retornaNome(Aluno* aluno){
    return aluno->nome;
}

void destroiAluno(Aluno* aluno){
	free(aluno->nome);
    free(aluno);
}