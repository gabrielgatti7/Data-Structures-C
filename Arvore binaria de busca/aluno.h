#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;

Aluno* criaAluno(Aluno* aluno, char* nome, int mat);
void imprimeAluno(Aluno* aluno);
int retornaMat(Aluno* aluno);
char* retornaNome(Aluno* aluno);
void destroiAluno(Aluno* aluno);

#endif