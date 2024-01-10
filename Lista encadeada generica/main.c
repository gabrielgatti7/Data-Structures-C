#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "listaAluno.h"

int main(){
    Aluno* a1 = criaAluno(a1, "Gabriel", 100, 7.0);
    Aluno* a2 = criaAluno(a1, "Thiago", 101, 7.0);
    Aluno* a3 = criaAluno(a1, "Bruno", 102, 10.0);
    Aluno* a4 = criaAluno(a1, "Joao", 103, 5.6);

    ListaGen* turma = criaLista();

    insereLista(turma, a1);
    insereLista(turma, a2);
    insereLista(turma, a3);
    insereLista(turma, a4);

    imprimeListaAlunos(turma);
    printf("Media da turma: %f\n", mediaTurma(turma));

    printf("Bruno esta na turma?: %d\n", pertenceAluno(turma, 102));

    printf("Retira Bruno da turma\n");
    turma = retiraAluno(turma, 102);

    imprimeListaAlunos(turma);
    printf("Media da turma: %f\n", mediaTurma(turma));

    printf("Bruno esta na turma?: %d\n", pertenceAluno(turma, 102));

    return 0;
}