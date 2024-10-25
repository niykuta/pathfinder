#include "../inc/pathfinder.h"

void mx_print_routes(t_graph *graph, int start, int end) {
    int *distances = malloc(graph->num_islands * sizeof(int));
    int *path = malloc(graph->num_islands * sizeof(int));

    mx_dijkstra(graph, start, distances);
    mx_find_paths(graph, distances, start, end, path, 0);

    free(distances);
    free(path);
}

void mx_print_all_routes(t_graph *graph) {
    int count = graph->num_islands;

    for (int start = 0; start < count; start++) {
        for (int end = start + 1; end < count; end++) {
            mx_print_routes(graph, start, end);
        }
    }
}

