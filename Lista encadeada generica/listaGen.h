#ifndef LISTAGEN_H
#define LISTAGEN_H

typedef struct celulagen CelGen;

typedef struct listagen ListaGen;

CelGen* criaCelula(void* item);
ListaGen* criaLista(void);
ListaGen* insereLista(ListaGen* lista, void* item);
void retiraLista(ListaGen* lista, int (*callback)(void*, void*), void* chave);
int percorreLista(ListaGen* lista, int (*callback)(void*, void*), void* chave);
void liberaLista(ListaGen* lista);
int retornaQntElem(ListaGen* lista);

#endif