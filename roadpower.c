#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "roads.h"

int check_if_true(graph *graph_prot, char *name)
{

}

void length_of_roads(graph *graph_prot)
{

}

uint16_t shortest_way(graph *graph_prot, int start, int finish)
{
    int *d = malloc(sizeof(int) * graph_prot->nvertices);
    int *prev = malloc(sizeof(int) * graph_prot->nvertices);

    for(int i = 0; i <= graph_prot->nvertices; i++) {
        if(i != start) {
        }
    }
}

uint16_t longest_way(graph *graph_prot, int start, int finish)
{

}

uint16_t num_of_all_roads(graph *graph_prot, int start, int finish)
{

}