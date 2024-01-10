#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno* criaAluno(Aluno* aluno, char* nome, int mat, float cr);
void imprimeAluno(Aluno* aluno);
int retornaMat(Aluno* aluno);
float retornaCR(Aluno* aluno);
char* retornaNome(Aluno* aluno);
void destroiAluno(Aluno* aluno);