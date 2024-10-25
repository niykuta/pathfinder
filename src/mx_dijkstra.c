#include "../inc/pathfinder.h"

void mx_dijkstra(t_graph *graph, int start, int *distances) {
    int count = graph->num_islands;
    int *visited = calloc(count, sizeof(int));
    t_priority_queue *queue = mx_queue_create(count);

    for (int i = 0; i < count; i++) {
        distances[i] = INT_MAX;
    }
    distances[start] = 0;
    queue->distances[start] = 0;

    for (int i = 0; i < count; i++) {
        int current = mx_queue_get_min(queue, visited);
        if (current == -1) break;
        visited[current] = 1;

        t_bridge *bridge = graph->islands[current]->bridges;
        while (bridge) {
            int neighbor = bridge->destination->index;
            int new_distance = distances[current] + bridge->length;

            if (!visited[neighbor] && new_distance < distances[neighbor]) {
                distances[neighbor] = new_distance;
                queue->distances[neighbor] = new_distance;
            }
            bridge = bridge->next;
        }
    }

    free(queue->distances);
    free(queue->indexes);
    free(queue);
    free(visited);
}
