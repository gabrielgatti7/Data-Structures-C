#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

struct hash{
    int length;
    Word** table;
};

static int hash(char* str, int length){
    int i = 0, sum = 0;
    for(i=0; str[i]!='\0'; i++){
        sum += str[i];
    }
    return sum % length;
}

Hash* createHash(int length){
    Hash* h = (Hash*) malloc(sizeof(Hash));
    h->length = length;
    h->table = (Word**) malloc(length * sizeof(Word*));
    
    // inicializa os ponteiros da tabela como NULL
    int i = 0;
    for(i; i<length; i++){
        h->table[i] = NULL;
    }
    return h; 
}

Word* access(Hash* h, char* str){

    int index = hash(str, h->length);
    
    Word* wd = searchWordList(h->table[index], str);

    if(wd == NULL){
        wd = createWord(str);
        h->table[index] = insertWordList(h->table[index], wd);
    }
    else
        refreshFrequency(wd);

    return wd;
}

void printHash(Hash* h){
    int i = 0;
    for(i; i < h->length; i++){
        if(h->table[i] != NULL){
            printList(h->table[i]);
        }
    }
}

void freeHash(Hash* h){
    int i = 0;
    for(i; i < h->length; i++){
        freeWordList(h->table[i]);
    }
    free(h->table);
    free(h);
}