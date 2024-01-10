#include <stdio.h>
#include "abb.h"

int main(){
    Aluno* a1 = criaAluno(a1, "Joao", 100);
    Aluno* a2 = criaAluno(a2, "Bruno", 101);
    Aluno* a3 = criaAluno(a3, "Elder", 102);
    Aluno* a4 = criaAluno(a4, "Thiago", 103);
    Aluno* a5 = criaAluno(a5, "Gabriel", 104);

    Arv* a;
    a = abb_insere(a, a2);
    a = abb_insere(a, a4);
    a = abb_insere(a, a1);
    a = abb_insere(a, a3);
    a = abb_insere(a, a5);

    printf("===================== ALUNOS =====================\n");
    abb_imprime(a);

    printf("\nBruno perterce?: ");
    if(abb_busca(a, 101) != NULL)
        printf("1\n");
    else
        printf("0\n");
    printf("Maria perterce?: ");
        if(abb_busca(a, 105) != NULL)
        printf("1\n");
    else
        printf("0\n");

    printf("\nRetira Elder:\n");
    abb_retira(a, 102);

    printf("===================== ALUNOS =====================\n");
    abb_imprime(a);

    printf("\nRetira Bruno:\n");
    abb_retira(a, 101);

    printf("===================== ALUNOS =====================\n");
    abb_imprime(a);

    abb_libera(a);
    destroiAluno(a1);
    destroiAluno(a2);
    destroiAluno(a3);
    destroiAluno(a4);
    destroiAluno(a5);
    return 0;
}