#include "../inc/pathfinder.h"

t_graph *mx_create_graph(int islands_num) {
    t_graph *graph = malloc(sizeof(t_graph));
    graph->num_islands = 0;
    graph->max_islands = islands_num; 
    graph->islands = malloc(islands_num * sizeof(t_island*));

    for (int i = 0; i < islands_num; i++) {
        graph->islands[i] = NULL;
    }

    return graph;
}


