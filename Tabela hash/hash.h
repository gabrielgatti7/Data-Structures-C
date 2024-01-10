#ifndef HASH_H
#define HASH_H
#include "word.h"

typedef struct hash Hash;

Hash* createHash(int length);

Word* access(Hash* h, char* str);

void printHash(Hash* h);

void freeHash(Hash* h);

#endif