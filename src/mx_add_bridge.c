#include "../inc/pathfinder.h"

bool mx_add_bridge(t_island *island1, t_island *island2, int length) {
    t_bridge *bridge = island1->bridges;
    while (bridge != NULL) {
        if (bridge->destination == island2) {
            return true;  
        }
        bridge = bridge->next;
    }

    bridge = island2->bridges;
    while (bridge != NULL) {
        if (bridge->destination == island1) {
            return true;  
        }
        bridge = bridge->next;
    }

    t_bridge *new_bridge1 = malloc(sizeof(t_bridge));
    new_bridge1->destination = island2;
    new_bridge1->length = length;
    new_bridge1->next = island1->bridges;
    island1->bridges = new_bridge1;

    t_bridge *new_bridge2 = malloc(sizeof(t_bridge));
    new_bridge2->destination = island1;
    new_bridge2->length = length;
    new_bridge2->next = island2->bridges;
    island2->bridges = new_bridge2;

    return false;
}
