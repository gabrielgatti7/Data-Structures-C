#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "listaGen.h"

Aluno* retiraAluno(ListaGen* lista, int* mat);
// verifica se o aluno esta na lista
int pertenceAluno(ListaGen* lista, int* mat);
float mediaTurma(ListaGen* lista);
void imprimeListaAlunos(ListaGen* lista);