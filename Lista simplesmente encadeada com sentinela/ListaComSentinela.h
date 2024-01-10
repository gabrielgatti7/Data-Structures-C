#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

typedef struct celula Celula;

typedef struct lista Lista;

Celula* inicializaCelula(Aluno* aluno);
Lista* inicializaLista();
void insereAluno_finalLista(Lista* lista, Aluno* aluno);
Aluno* retiraAluno(Lista* lista, char* nome);
void imprimeLista(Lista* lista);
void destroiLista(Lista* lista);