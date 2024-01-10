#include <stdio.h>
#include "arvore.h"

int main(){
    Aluno* a1 = criaAluno(a1, "Joao", 100);
    Aluno* a2 = criaAluno(a2, "Bruno", 101);
    Aluno* a3 = criaAluno(a3, "Elder", 102);
    Aluno* a4 = criaAluno(a4, "Thiago", 103);
    Aluno* a5 = criaAluno(a5, "Gabriel", 104);

    Arv* a = arv_cria(a1,
                arv_cria(a2,
                    arv_criavazia(),
                    arv_cria(a3,
                        arv_criavazia(),
                        arv_criavazia())
                ),
                arv_cria(a4,
                    arv_cria(a5,
                        arv_criavazia(),
                        arv_criavazia()),
                    arv_cria(a1,
                        arv_criavazia(),
                        arv_criavazia())
                )
                
    );

    arv_imprime(a);

    // verifica se Joao pertence
    printf("\nAluno Joao pertence?: %d", arv_pertence(a, "Joao"));

    // verifica se Maria pertence
    printf("\nAluna Maria pertence?: %d", arv_pertence(a, "Maria"));

    // retorna o pai do no f
    printf("\nPai do no Elder:\n");
    imprimeAluno(info(arv_pai(a, "Elder")));

    // retorna o num de folhas da arvore
    printf("\nNumero de folhas da arvore: %d", folhas(a));

    // retorna o num de ocorrencias de e
    printf("\nNumero de ocorrencias de Joao: %d\n", ocorrencias(a, "Joao"));

    arv_libera(a);
    return 0;
}