#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word.h"

struct word{
    int n;
    struct word* next;
    char* string;
};

Word* createWord(char* string){
    Word* word = (Word*) malloc(sizeof(Word));
    word->string = strdup(string);
    word->n = 0;
    word->next = NULL;
    return word;
}

char* returnString(Word* wd){
    return wd->string;
}

void refreshFrequency (Word* wd){
    wd->n++;
}

int returnFrequency (Word* wd){
    return wd->n;
}

Word* searchWordList(Word* wd, char* string){
    Word* a = wd;
    for(a; a!=NULL; a=a->next){
        if(!strcmp(returnString(a), string)){
            return a;
        }
    }
    return NULL;
}

// insere no inicio
Word* insertWordList(Word* list, Word* wd){
    wd->next = list;
    refreshFrequency(wd);
    return wd;  
}

int countWordsList(Word* wd){
    Word* a = wd;
    int n = 0;
    for(a; a!=NULL; a=a->next){
        n++;
    }
    return n;
}

void printList(Word* wd){
    Word* a = wd;
    for(a; a!=NULL; a=a->next){
        printf("%s: %d\n", returnString(a), returnFrequency(a));
    }
}

void freeWordList(Word* wd){
    Word* a = wd;

    while(wd != NULL){
        a = wd->next;
        free(wd->string);
        free(wd);
        wd = a;
    }
}