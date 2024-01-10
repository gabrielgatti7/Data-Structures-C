#include <stdio.h>
#include <stdlib.h>
#include "ListaComSentinela.h"

int main(){
    Aluno* a1 = criaAluno(a1, "Gabriel", 100);
    Aluno* a2 = criaAluno(a2, "Pedro", 101);
    Aluno* a3 = criaAluno(a3, "Maria", 102);
    Aluno* a4 = criaAluno(a4, "Joao", 103);

    Lista* turma1 = inicializaLista();
    Lista* turma2 = inicializaLista();

    insereAluno_finalLista(turma1, a1);
    insereAluno_finalLista(turma1, a2);
    insereAluno_finalLista(turma1, a3);

    insereAluno_finalLista(turma2, a1);
    insereAluno_finalLista(turma2, a4);

    Aluno* a;

    printf("\\---------- TURMA 1 ----------\\");
    imprimeLista(turma1);
    printf("\\---------- TURMA 2 ----------\\");
    imprimeLista(turma2);
    printf("\n");
    
    a = retiraAluno(turma1, "Maria");

    printf("\\---------- TURMA 1 ----------\\");
    imprimeLista(turma1);
    printf("\\---------- TURMA 2 ----------\\");
    imprimeLista(turma2);
    printf("\n\n");

    a = retiraAluno(turma1, "Gabriel");

    printf("\\---------- TURMA 1 ----------\\");
    imprimeLista(turma1);
    printf("\\---------- TURMA 2 ----------\\");
    imprimeLista(turma2);
    printf("\n\n");

    a = retiraAluno(turma1, "Joa");

    printf("\\---------- TURMA 1 ----------\\");
    imprimeLista(turma1);
    printf("\\---------- TURMA 2 ----------\\");
    imprimeLista(turma2);
    printf("\n\n");

    a = retiraAluno(turma1, "Pedro");
    insereAluno_finalLista(turma2, a2);
    
    printf("\\---------- TURMA 1 ----------\\");
    imprimeLista(turma1);
    printf("\\---------- TURMA 2 ----------\\");
    imprimeLista(turma2);


    destroiAluno(a1);
    destroiAluno(a2);
    destroiAluno(a3);
    destroiAluno(a4);

    destroiLista(turma1);
    destroiLista(turma2);

    return 0;
}