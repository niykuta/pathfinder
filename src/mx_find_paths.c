#include "../inc/pathfinder.h"

void mx_find_paths(t_graph *graph, int *distances, int current, int end, int *path, int length) {
    path[length++] = current;

    if (current == end) {
        mx_print_path(graph, path, length, end);
        return;
    }

    int *neighbors = malloc(graph->num_islands * sizeof(int)); 
    int num_neighbors = 0;

    for (t_bridge *bridge = graph->islands[current]->bridges; bridge; bridge = bridge->next) {
        int neighbor = bridge->destination->index;
        if (distances[neighbor] == distances[current] + bridge->length) {
            neighbors[num_neighbors++] = neighbor;
        }
    }

    mx_insertion_sort(neighbors, num_neighbors, graph);

    for (int i = 0; i < num_neighbors; i++) {
        mx_find_paths(graph, distances, neighbors[i], end, path, length);
    }

    free(neighbors);  
}
