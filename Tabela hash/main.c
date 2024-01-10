#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hash.h"
#define WORDS 64
#define TABLENGTH 127

int readString(FILE* f, char* str){
    int i = 0, c;

    while((c = fgetc(f)) != EOF){
        if(isalpha(c))
            break;
    }
    if(c == EOF)
        return 0;
    else
        str[i++] = c;

    while((i<WORDS-1) && (c = fgetc(f)) != EOF && isalpha(c))
        str[i++] = c;
    
    str[i] = '\0';

    return i;
}

int main(int argc, char** argv){
    FILE* f;
    char str[WORDS];

    if(argc != 2){
        printf("Arquivo nao encontrado\n");
        return 0;
    }

    f = fopen(argv[1], "rt");

    if(f == NULL){
        printf("Erro na abertura do arquivo\n");
        return 0;
    }

    Hash* h = createHash(TABLENGTH);

    while(readString(f, str)){
        Word* wd = access(h, str);
    }
/*
    access(h, "barco");
    access(h, "ed");
    access(h, "barco");
    access(h, "cobra");
    access(h, "de");
    access(h, "vida");
*/
    printHash(h);

    freeHash(h);

    return 0;
}