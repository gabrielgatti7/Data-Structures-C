#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#define TAM 50

struct pilha{
    Aluno* aluno[TAM];
    int topo;
};


Pilha* inicializaPilha(){
    Pilha* pilha = (Pilha*) malloc (sizeof(Pilha));
    pilha->topo = 0;

    return pilha;
}


void push(Pilha* pilha, Aluno* aluno){
    if(pilha == NULL){
        printf("Ponteiro para pilha inválido!\n");
        return;
    }
    if(aluno == NULL){
        printf("Ponteiro para aluno inválido!\n");
        return;
    }
    if(pilha->topo >= TAM){
        printf("Pilha cheia!\n");
        return;
    }

    pilha->aluno[pilha->topo] = aluno;
    pilha->topo++; 
}


Aluno* pop(Pilha* pilha){
    if(pilha == NULL){
        printf("Ponteiro para pilha inválido!\n");
        return NULL;
    }
    if(pilha->topo == 0){
        printf("Pilha vazia!\n");
        return NULL;
    }

    pilha->topo--;
    return pilha->aluno[pilha->topo];
}


int EstaVazia(Pilha* pilha){
    if(pilha == NULL){
        printf("Ponteiro para pilha inválido!\n");
        return -1;
    }

    if(pilha->topo == 0) return 1;
    else return 0;
}

// imprime comecando do topo
void imprimePilha(Pilha* pilha){
    if(pilha == NULL){
        printf("Ponteiro para pilha inválido!\n");
        return;
    }

    int i;
    for(i = (pilha->topo-1); i >= 0; i--){
        printf("\n");
        imprimeAluno(pilha->aluno[i]);
    }
    printf("\n");
}


void destroiPilha(Pilha* pilha){
    if(pilha == NULL){
        printf("Ponteiro para pilha inválido!\n");
        return;
    }

    free(pilha);
}