#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno* criaAluno(Aluno* aluno, char* nome, int mat);
void imprimeAluno(Aluno* aluno);
int retornaMatAluno(Aluno* aluno);
char* retornaNomeAluno(Aluno* aluno);
void destroiAluno(Aluno* aluno);