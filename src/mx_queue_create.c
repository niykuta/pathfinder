#include "../inc/pathfinder.h"

t_priority_queue *mx_queue_create(int count) {
    t_priority_queue *queue = malloc(sizeof(t_priority_queue));
    queue->distances = malloc(count * sizeof(int));
    queue->indexes = malloc(count * sizeof(int));
    queue->size = count;

    for (int i = 0; i < count; i++) {
        queue->distances[i] = INT_MAX;
        queue->indexes[i] = i;
    }

    return queue;
}
