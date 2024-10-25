#include "../inc/pathfinder.h"

void mx_print_path(t_graph *graph, int *path, int length, int end) {
    mx_printstr("========================================\n");

    mx_printstr("Path: ");
    mx_printstr(graph->islands[path[0]]->name);
    mx_printstr(" -> ");
    mx_printstr(graph->islands[end]->name);
    mx_printstr("\n");

    mx_printstr("Route: ");
    for (int i = 0; i < length; i++) {
        mx_printstr(graph->islands[path[i]]->name);
        if (i != length - 1) {
            mx_printstr(" -> ");
        }
    }
    mx_printstr("\n");

    mx_printstr("Distance: ");
    int total_distance = 0;
    for (int i = 0; i < length - 1; i++) {
        int segment_distance = 0;
        t_bridge *bridge = graph->islands[path[i]]->bridges;

        while (bridge) {
            if (bridge->destination->index == path[i + 1]) {
                segment_distance = bridge->length;
                total_distance += segment_distance;

                mx_printint(segment_distance);
                if (i != length - 2) {
                    mx_printstr(" + ");
                }
                break;
            }
            bridge = bridge->next;
        }
    }

    if (length > 2) {
        mx_printstr(" = ");
        mx_printint(total_distance);
        mx_printstr("\n");
    } else {
        mx_printstr("\n");
    }

    mx_printstr("========================================\n");
}
