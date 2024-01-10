#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

int main(){
    Aluno* a1 = criaAluno(a1, "Gabriel", 100);
    Aluno* a2 = criaAluno(a2, "Pedro", 101);
    Aluno* a3 = criaAluno(a3, "Maria", 102);
    Aluno* a4 = criaAluno(a4, "Joao", 103);

    Pilha* p1 = inicializaPilha();
    Pilha* p2 = inicializaPilha();

    push(p1, a1);
    push(p1, a2);
    push(p1, a3);

    push(p2, a1);
    push(p2, a4);

    Aluno* a;

    printf("\\---------- TURMA 1 ----------\\");
    imprimePilha(p1);
    printf("\\---------- TURMA 2 ----------\\");
    imprimePilha(p2);
    printf("\n");

    a = pop(p1);

    printf("\\---------- TURMA 1 ----------\\");
    imprimePilha(p1);
    printf("\\---------- TURMA 2 ----------\\");
    imprimePilha(p2);
    printf("\n\n");

    a = pop(p1);

    printf("\\---------- TURMA 1 ----------\\");
    imprimePilha(p1);
    printf("\\---------- TURMA 2 ----------\\");
    imprimePilha(p2);
    printf("\n\n");

    a = pop(p1);

    printf("\\---------- TURMA 1 ----------\\");
    imprimePilha(p1);
    printf("\\---------- TURMA 2 ----------\\");
    imprimePilha(p2);
    printf("\n\n");

    a = pop(p1);

    push(p2, a2);
    
    printf("\\---------- TURMA 1 ----------\\");
    imprimePilha(p1);
    printf("\\---------- TURMA 2 ----------\\");
    imprimePilha(p2);


    destroiAluno(a1);
    destroiAluno(a2);
    destroiAluno(a3);
    destroiAluno(a4);

    destroiPilha(p1);
    destroiPilha(p2);

    return 0;
}