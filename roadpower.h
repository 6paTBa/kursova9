#include <stdint.h>
#include "roads.h"
/*количество городов /3\

  А Б В 
А 0 0 3 
Б 0 0 0
В 3 0 0

поиск кратчайшего пути /a\ /б\ /рассчитать\ ---> if(!(check to true(names1) || check to true(names2))) --> shortest_way(graph, )
количество различных маршрутов /город1\ /город2\ /рассчитать\
длиннейший путь /город1\ /город2\ /рассчитать\
*/

int check_if_true(graph *graph_prot, char *name);
void length_of_roads(graph *graph_prot);
uint16_t shortest_way(graph *graph_prot, int start, int finish);
uint16_t longest_way(graph *graph_prot, int start, int finish);
uint16_t num_of_all_roads(graph *graph_prot, int start, int finish);