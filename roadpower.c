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

int extract_min(graph *graph_prot, int source, int *seen) {
    int min = 32767;
    for(int i = 0; i < graph_prot->nvertices; i++) {
        if((i != source) && (seen[i] != 1) && 
            (graph_prot->roads[source][i] != 0) && (graph_prot->roads[source][i] < min)) {
                return i;
        }
    }
}

uint16_t shortest_way(graph *graph_prot, int start, int finish)
{
    int max = graph_prot->nvertices, v;
    int *d = malloc(sizeof(int) * graph_prot->nvertices);
    int *seen = calloc(graph_prot->nvertices, sizeof(int));
    int *prev = malloc(sizeof(int) * graph_prot->nvertices);

    for(int i = 0; i < max; i++) {
        if(i != start) {
            d[i] = 32767;
        }
        prev[i] = -1;
    }
    d[start] = 0;

    for(int i = 0; i < max; i++) {
        v = extract_min(graph_prot, start, seen);
        seen[v] = 1;
        d[v] = graph_prot->roads[start][v];

        for(int j = 0; j < max; j++) {
            if(graph_prot->roads[v][j] != 0) {
                if(graph_prot->roads[start][j] != 0) {
                    d[j] = graph_prot->roads[start][j];
                    if(d[v] + graph_prot[v][j] < d[j]) {
                        d[j] = d[v] + graph_prot[v][j];
                        prev[j] = v;
                    }
                } else {
                    d[j] = d[v] + graph_prot[v][j];
                    prev[j] = v;
                }
            }
        }
    }
    return d[finish];
}

uint16_t longest_way(graph *graph_prot, int start, int finish)
{

}

uint16_t num_of_all_roads(graph *graph_prot, int start, int finish)
{

}