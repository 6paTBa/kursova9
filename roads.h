#include <stdio.h>
#define MAX_NAME_LENGTH 2

typedef struct{
    char name[MAX_NAME_LENGTH];
} names;

typedef struct{
    size_t nvertices;
    names *vertices;
    int *roads;
} graph;