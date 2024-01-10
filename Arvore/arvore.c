#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

struct arvore{
    Aluno* aluno;
    struct arvore* dir;
    struct arvore* esq;
};

//Cria uma árvore vazia
Arv* arv_criavazia (void){
    return NULL;
}

//cria uma árvore com a informação do nó raiz c, e
//com subárvore esquerda e e subárvore direita d
Arv* arv_cria (Aluno* al, Arv* e, Arv* d){
    Arv* a = (Arv*) malloc (sizeof(Arv));
    a->aluno = al;
    a->dir = d;
    a->esq = e;
}

//libera o espaço de memória ocupado pela árvore a
Arv* arv_libera (Arv* a){
    if(!arv_vazia(a)){
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
    return NULL;
}

//retorna true se a árvore estiver vazia e false
//caso contrário
int arv_vazia (Arv* a){
    if(a)
        return 0;
    return 1;
}

//indica a ocorrência (1) ou não (0) de um aluno
int arv_pertence (Arv* a, char* nome){
    if(arv_vazia(a)){
        return 0;
    }
    if(!strcmp(retornaNome(a->aluno), nome) || arv_pertence(a->esq, nome)
        || arv_pertence(a->dir, nome))
        return 1;
}

//imprime as informações dos nós da árvore
void arv_imprime (Arv* a){
    printf("<");
    if(!arv_vazia(a)){
        imprimeAluno(a->aluno);
        arv_imprime(a->esq);
        arv_imprime(a->dir);
    }
    printf(">");
}

//retorna a mãe de um dado no
Arv* arv_pai (Arv* a, char* nome){
    if(!arv_vazia(a)){
        if((!arv_vazia(a->esq) && !strcmp(retornaNome(a->esq->aluno), nome))
            || (!arv_vazia(a->dir) && !strcmp(retornaNome(a->dir->aluno), nome)))
            return a;
        
        Arv* aux = arv_pai(a->esq, nome);
        if(aux == NULL)
            aux = arv_pai(a->dir, nome);
        return aux;
    }
    return NULL;
}

//retorna a quantidade de folhas de uma arvore binaria
int folhas (Arv* a){
    if(!arv_vazia(a)){
        return 1 + folhas(a->esq) + folhas(a->dir);
    }
    return 0;
}

//retorna o numero de ocorrencias de um dado aluno na arvore
int ocorrencias (Arv* a, char* nome){
    if(arv_vazia(a))
        return 0;
    if(!strcmp(retornaNome(a->aluno), nome)){
        return 1 + ocorrencias(a->esq, nome) + ocorrencias(a->dir, nome);
    }
    return ocorrencias(a->esq, nome) + ocorrencias(a->dir, nome);
}

//retorna o campo informacao de um dado no
Aluno* info (Arv* a){
    return a->aluno;
}