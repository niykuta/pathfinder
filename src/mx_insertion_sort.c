#include "../inc/pathfinder.h"

void mx_insertion_sort(int *neighbors, int num_neighbors, t_graph *graph) {
    for (int i = 1; i < num_neighbors; i++) {
        int key = neighbors[i];
        int j = i - 1;

        while (j >= 0 && mx_strcmp(graph->islands[neighbors[j]]->name, graph->islands[key]->name) > 0) {
            neighbors[j + 1] = neighbors[j];
            j--;
        }
        
        neighbors[j + 1] = key;
    }
}
