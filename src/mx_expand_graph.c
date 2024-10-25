#include "../inc/pathfinder.h"

void mx_expand_graph(t_graph *graph) {
    if (graph->num_islands >= graph->max_islands) {
        graph->max_islands *= 2; 
        graph->islands = realloc(graph->islands, graph->max_islands * sizeof(t_island*));

        for (int i = graph->num_islands; i < graph->max_islands; i++) {
            graph->islands[i] = NULL;
        }
    }
}
