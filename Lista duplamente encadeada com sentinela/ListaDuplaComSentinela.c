#include <stdio.h>
#include <stdlib.h>
#include "ListaDuplaComSentinela.h"

struct celula{
    Aluno* aluno;
    Celula* prox;
    Celula* ant;
};

struct lista{
    Celula* prim;
    Celula* ult;
};

Celula* inicializaCelula(Aluno* aluno){
    Celula* cel = malloc(sizeof(Celula));
    cel->aluno = aluno;
    cel->ant = NULL;
    cel->prox = NULL;

    return cel;
}

Lista* inicializaLista(){
    Lista* lista = malloc(sizeof(Lista));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void insereAluno_finalLista(Lista* lista, Aluno* aluno){
    Celula* nova = inicializaCelula(aluno);

    // Se lista vazia
    if(lista->prim == NULL){
        lista->prim = nova;
        lista->ult = nova;
    }
    else{
        lista->ult->prox = nova;
        nova->ant = lista->ult;
        lista->ult = nova;
    }
}

void retiraAluno(Lista* lista, char* nome){
    Celula* p = lista->prim;

    while(p != NULL && strcmp(retornaNome(p->aluno), nome) != 0){
        p = p->prox;
    }

    // se nao encontrou o aluno
    if(p == NULL){
        return;
    }

    // se eh o unico da lista
    if(p == lista->prim && p == lista->ult){
        lista->prim = NULL;
        lista->ult = NULL;
    }
    // se eh o ultimo da lista
    else if(p == lista->ult){
        p->ant->prox = NULL;
        lista->ult = p->ant;
    }
    // se eh o primeiro da lista
    else if(p == lista->prim){
        lista->prim = p->prox;
        p->prox->ant = NULL;
    }
    // outros casos
    else{
        p->ant->prox = p->prox;
        p->prox->ant = p->ant;
    }

    free(p);
}

void imprimeLista_InicFinal(Lista* lista){
    Celula* p = NULL;
    int i = 0;
    for(p = lista->prim; p != NULL; p = p->prox){
        i++;
        printf("\n");
        imprimeAluno(p->aluno);
    }
    if(i==0) printf("\n** LISTA VAZIA **\n");
    printf("\n");
}

void imprimeLista_FinalInic(Lista* lista){
    Celula* p = NULL;
    int i = 0;
    for(p = lista->ult; p != NULL; p = p->ant){
        i++;
        printf("\n");
        imprimeAluno(p->aluno);
    }
    if(i==0) printf("\n** LISTA VAZIA **\n");
    printf("\n");
}

void destroiLista(Lista* lista){
    Celula* p = lista->prim;
    Celula* t = NULL;

    while(p != NULL){
        t = p->prox;
        free(p);
        p = t;
    }

    free(lista);
}