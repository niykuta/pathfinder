#include "../inc/pathfinder.h"

void mx_free_bridges(t_bridge *bridge) {
    while (bridge) {
        t_bridge *temp = bridge;
        bridge = bridge->next;  
        free(temp);             
    }
}

void mx_free_island(t_island *island) {
    if (island) {
        mx_free_bridges(island->bridges);
        free(island->name);
        free(island);
    }
}

void mx_free_graph(t_graph *graph) {
    if (graph) {
        for (int i = 0; i < graph->num_islands; i++) {
            mx_free_island(graph->islands[i]); 
        }
        free(graph->islands);  
        free(graph);          
    }
}

