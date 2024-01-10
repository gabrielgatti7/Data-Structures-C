#ifndef WORD_H
#define WORD_H

typedef struct word Word;

Word* createWord(char* wd);

char* returnString(Word* wd);

void refreshFrequency (Word* wd);

int returnFrequency (Word* wd);

Word* searchWordList(Word* wd, char* string);

Word* insertWordList(Word* list, Word* wd);

int countWordsList(Word* wd);

void printList(Word* wd);

void freeWordList(Word* wd);

#endif