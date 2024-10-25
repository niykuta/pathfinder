#include "../inc/pathfinder.h"

int mx_queue_get_min(t_priority_queue *queue, int *visited) {
    int min_distance = INT_MAX;
    int min_index = -1;

    for (int i = 0; i < queue->size; i++) {
        int index = queue->indexes[i];
        if (!visited[index] && queue->distances[index] < min_distance) {
            min_distance = queue->distances[index];
            min_index = index;
        }
    }

    return min_index;
}
