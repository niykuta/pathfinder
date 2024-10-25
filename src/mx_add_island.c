#include "../inc/pathfinder.h"

t_island *mx_add_island(t_graph *graph, char *name, int *index) {
    for (int i = 0; i < graph->num_islands; i++) {
        if (mx_strcmp(graph->islands[i]->name, name) == 0) {
            return graph->islands[i]; 
        }
    }

    mx_expand_graph(graph);

    t_island *new_island = malloc(sizeof(t_island));
    new_island->name = mx_strdup(name);
    new_island->bridges = NULL;
    new_island->index = *index;

    graph->islands[graph->num_islands] = new_island;
    (*index)++;
    graph->num_islands++;

    return new_island;
}

