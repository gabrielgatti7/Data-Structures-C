#include <stdio.h>
#include <stdlib.h>
#include "listaGen.h"

struct celulagen{
    void* item;
    CelGen* prox;
};

struct listagen{
    CelGen* prim;
    CelGen* ult;
    int qnt_elem;
};

CelGen* criaCelula(void* item){
    CelGen* cel = (CelGen*) malloc (sizeof(CelGen));
    cel->item = item;
    cel->prox = NULL;

    return cel;
}

ListaGen* criaLista(void){
    ListaGen* lista = (ListaGen*) malloc (sizeof(ListaGen));
    lista->prim = NULL;
    lista->ult = NULL;
    lista->qnt_elem = 0;
    return lista;
}

// insere no final da lista
ListaGen* insereLista(ListaGen* lista, void* item){
    CelGen* nova = criaCelula(item);

    // Se lista vazia
    if(lista->prim == NULL){
        lista->prim = nova;
        lista->ult = nova;
    }
    else{
        lista->ult->prox = nova;
        lista->ult = nova;
    }
    lista->qnt_elem++;
}

void retiraLista(ListaGen* lista, int (*callback)(void*, void*), void* chave){
    CelGen* p = lista->prim;
    CelGen* ant = NULL;
    void* item;

    while(p != NULL && callback(p->item, chave) != 0){
        ant = p;
        p = p->prox;
    }

    // se nao encontrou o aluno
    if(p == NULL){
        return NULL;
    }

    // se eh o unico da lista
    if(p == lista->prim && p == lista->ult){
        lista->prim = NULL;
        lista->ult = NULL;
    }
    // se eh o ultimo da lista
    else if(p == lista->ult){
        ant->prox = NULL;
        lista->ult = ant;
    }
    // se eh o primeiro da lista
    else if(p == lista->prim){
        lista->prim = p->prox;
    }
    // outros casos
    else{
        ant->prox = p->prox;
    }

    lista->qnt_elem--;

    free(p);
}

int percorreLista(ListaGen* lista, int (*callback)(void*, void*), void* chave){
    CelGen* p;
    for(p = lista->prim; p != NULL; p = p->prox){
        int r = callback(p->item, chave);
        if(r == 0){
            return r;
        }
    }
    return 1;
}

int retornaQntElem(ListaGen* lista){
    return lista->qnt_elem;
}

void liberaLista(ListaGen* lista){
    CelGen* p = lista->prim;
    CelGen* t = NULL;

    while(p != NULL){
        t = p->prox;
        free(p);
        p = t;
    }

    free(lista);
}