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
        //если вершина раннее не просматривалась, если она смежна с source
        //и расстояние от source до нее минимальный, то возвращаем эту вершину
    }
}

int extract_max(graph *graph_prot, int source, int *seen) {
    int min = 0;
    for(int i = 0; i < graph_prot->nvertices; i++) {
        if((i != source) && (seen[i] != 1) && 
            (graph_prot->roads[source][i] != 0) && (graph_prot->roads[source][i] > min)) {
                return i;
        }
    }
}

uint16_t shortest_way(graph *graph_prot, int start, int finish)
{
    int max = graph_prot->nvertices, v;
    int *d = malloc(sizeof(int) * graph_prot->nvertices);
    //указатель на массив чисел, в котором хранятся текущие расстояния
    //от стартовой вершины до [n-ой] вершины
    int *seen = calloc(graph_prot->nvertices, sizeof(int));
    //указатель на массив просмотренных вершин
    //если вершина n просмотрена, но в [n-ый] равен 1
    int *prev = malloc(sizeof(int) * graph_prot->nvertices);
    //указатель на массив предыдущих в пути вершин
    //предыдущая за n-ой вершиной - есть элемент [n] массива

    for(int i = 0; i < max; i++) {
        if(i != start) {
            d[i] = 32767;
        }
        //для каждой вершины, кроме старта, показатель расстояния 
        //от старта будет равняться максимальному значению int
        prev[i] = -1;
    }
    d[start] = 0;

    for(int i = 0; i < max; i++) {
        v = extract_min(graph_prot, start, seen);
        //из множества непросмотренных вершин
        //извлекаем самую ближнюю
        seen[v] = 1;
        //отмечаем ее как просмотренную
        d[v] = graph_prot->roads[start][v];

        for(int j = 0; j < max; j++) {
        //просматриваем все смежные с v вершины
            if(graph_prot->roads[v][j] != 0) {
            //если между v и j есть дорога
                if(graph_prot->roads[start][j] != 0) {
                //если между стартом и j есть дорога
                    d[j] = graph_prot->roads[start][j];
                    if(d[v] + graph_prot[v][j] < d[j]) {
                        d[j] = d[v] + graph_prot[v][j];
                        prev[j] = v;
                    }
                    //сравниваем, будет ли путь через v короче
                    //чем напрямую от старта
                    //если да, то значение расстояния от старта до j
                    //будет равно расстоянию до j через v
                } else {
                    d[j] = d[v] + graph_prot[v][j];
                    prev[j] = v;
                }
                //если от старта нет дороги до j
                //значение расстояния от старта до j
                //будет равно расстоянию до j через v
            }
        }
    }
    return d[finish];
    //возвращаем минимальный путь до конечной вершины
}

uint16_t longest_way(graph *graph_prot, int start, int finish)
{
    int max = graph_prot->nvertices, v;
    int *d = malloc(sizeof(int) * graph_prot->nvertices);
    int *seen = calloc(graph_prot->nvertices, sizeof(int));
    int *prev = malloc(sizeof(int) * graph_prot->nvertices);

    for(int i = 0; i < max; i++) {
        if(i != start) {
            d[i] = -1;
        }
        prev[i] = -1;
    }
    d[start] = 0;

    for(int i = 0; i < max; i++) {
        v = extract_max(graph_prot, start, seen);
        seen[v] = 1;
        d[v] = graph_prot->roads[start][v];

        for(int j = 0; j < max; j++) {
            if(graph_prot->roads[v][j] != 0) {
                if(graph_prot->roads[start][j] != 0) {
                    d[j] = graph_prot->roads[start][j];
                    if(d[v] + graph_prot[v][j] > d[j]) {
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

uint16_t num_of_all_roads(graph *graph_prot, int start, int finish)
{

}