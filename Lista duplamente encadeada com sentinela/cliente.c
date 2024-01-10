#include <stdio.h>
#include <stdlib.h>
#include "ListaDuplaComSentinela.h"

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

    printf("\\---------- TURMA 1 -- INICIO-FINAL ----------\\");
    imprimeLista_InicFinal(turma1);
    printf("\\---------- TURMA 2 -- INICIO-FINAL ----------\\");
    imprimeLista_InicFinal(turma2);
    printf("\n\n");

    printf("\\---------- TURMA 1 -- FINAL-INICIO ----------\\");
    imprimeLista_FinalInic(turma1);
    printf("\\---------- TURMA 2 -- FINAL-INICIO ----------\\");
    imprimeLista_FinalInic(turma2);
    printf("\n\n");
    
    printf("\nRETIRA 'MARIA' DA TURMA 1:\n\n");
    retiraAluno(turma1, "Maria");

    printf("\\---------- TURMA 1 -- INICIO-FINAL ----------\\");
    imprimeLista_InicFinal(turma1);
    printf("\\---------- TURMA 2 -- INICIO-FINAL ----------\\");
    imprimeLista_InicFinal(turma2);
    printf("\n\n");

    printf("\\---------- TURMA 1 -- FINAL-INICIO ----------\\");
    imprimeLista_FinalInic(turma1);
    printf("\\---------- TURMA 2 -- FINAL-INICIO ----------\\");
    imprimeLista_FinalInic(turma2);
    printf("\n\n");

    printf("\nRETIRA 'GABRIEL' DA TURMA 1:\n\n");
    retiraAluno(turma1, "Gabriel");

    printf("\\---------- TURMA 1 -- INICIO-FINAL ----------\\");
    imprimeLista_InicFinal(turma1);
    printf("\\---------- TURMA 2 -- INICIO-FINAL ----------\\");
    imprimeLista_InicFinal(turma2);
    printf("\n\n");

    printf("\\---------- TURMA 1 -- FINAL-INICIO ----------\\");
    imprimeLista_FinalInic(turma1);
    printf("\\---------- TURMA 2 -- FINAL-INICIO ----------\\");
    imprimeLista_FinalInic(turma2);
    printf("\n\n");

    printf("\nRETIRA 'JOA' DA TURMA 1:\n\n");
    retiraAluno(turma1, "Joa");

    printf("\\---------- TURMA 1 -- INICIO-FINAL ----------\\");
    imprimeLista_InicFinal(turma1);
    printf("\\---------- TURMA 2 -- INICIO-FINAL ----------\\");
    imprimeLista_InicFinal(turma2);
    printf("\n\n");

    printf("\\---------- TURMA 1 -- FINAL-INICIO ----------\\");
    imprimeLista_FinalInic(turma1);
    printf("\\---------- TURMA 2 -- FINAL-INICIO ----------\\");
    imprimeLista_FinalInic(turma2);
    printf("\n\n");

    printf("\nRETIRA 'PEDRO' DA TURMA 1:\n\n");
    retiraAluno(turma1, "Pedro");
    printf("INSERE 'PEDRO' NA TURMA 2:\n\n");
    insereAluno_finalLista(turma2, a2);
    
    printf("\\---------- TURMA 1 -- INICIO-FINAL ----------\\");
    imprimeLista_InicFinal(turma1);
    printf("\\---------- TURMA 2 -- INICIO-FINAL ----------\\");
    imprimeLista_InicFinal(turma2);
    printf("\n\n");

    printf("\\---------- TURMA 1 -- FINAL-INICIO ----------\\");
    imprimeLista_FinalInic(turma1);
    printf("\\---------- TURMA 2 -- FINAL-INICIO ----------\\");
    imprimeLista_FinalInic(turma2);

    destroiAluno(a1);
    destroiAluno(a2);
    destroiAluno(a3);
    destroiAluno(a4);

    destroiLista(turma1);
    destroiLista(turma2);

    return 0;
}