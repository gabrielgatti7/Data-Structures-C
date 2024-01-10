#include <stdio.h>
#include <stdlib.h>
#include "listaAluno.h"

// ==================== FUNCOES CALLBACK ================== //
int comparaMatricula_cb(void* aluno1, void* aluno2){
    Aluno* a1 = (Aluno*) aluno1;
    Aluno* a2 = (Aluno*) aluno2;

    if(retornaMat(a1) == retornaMat(a2)){
        return 0;
    }
    return 1;
}

int imprime_cb(void* aluno, void* dado){
    imprimeAluno(aluno);
    return 1;
}

int acumula(void* aluno, void* dado){
    float* cr_soma = (float*)dado;
    *cr_soma += retornaCR(aluno);
    return 1;
}

// ======================================================== //

Aluno* retiraAluno(ListaGen* lista, int* mat){
    retiraLista(lista, comparaMatricula_cb, mat);
}

int pertenceAluno(ListaGen* lista, int* mat){
    percorreLista(lista, comparaMatricula_cb, mat);
}

float mediaTurma(ListaGen* lista){
    float* soma = 0;
    percorreLista(lista, acumula, soma);

    return *soma / retornaQntElem(lista);
}

void imprimeListaAlunos(ListaGen* lista){
    percorreLista(lista, imprime_cb, NULL);
}