#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

typedef enum {
    USAGE_ERROR,
    FILE_NOT_EXIST_ERROR,
    FILE_EMPTY_ERROR,
    INVALID_LINE_ERROR,
    INVALID_ISLAND_NUMBER_ERROR,
    DUPLICATE_BRIDGES_ERROR,
    SUM_OF_BRIDGES_ERROR
} ErrorType;

typedef struct s_bridge {
    struct s_island *destination;  
    int length;                    
    struct s_bridge *next;         
} t_bridge;

typedef struct s_island {
    int index;         
    char *name;         
    t_bridge *bridges;  
} t_island;

typedef struct s_graph {
    t_island **islands;
    int num_islands;
    int max_islands;
} t_graph;

typedef struct s_priority_queue {
    int *distances;
    int *indexes;
    int size;
} t_priority_queue;

t_graph *mx_create_graph(int islands_num);
void mx_expand_graph(t_graph *graph);
t_island *mx_add_island(t_graph *graph, char *name, int *island_index);
bool mx_add_bridge(t_island *island1, t_island *island2, int length);
t_graph *mx_read_file(const char *filename);

void mx_print_error(ErrorType error, const char *filename, int line_number);
bool mx_validate_bridge_line(const char *line);

void mx_free_graph(t_graph *graph);
void mx_free_bridges(t_bridge *bridge);
void mx_free_island(t_island *island);

t_priority_queue *mx_queue_create(int count);
int mx_queue_get_min(t_priority_queue *queue, int *visited);

void mx_print_path(t_graph *graph, int *path, int length, int end);
void mx_find_paths(t_graph *graph, int *distances, int current, int end, int *path, int length);
void mx_dijkstra(t_graph *graph, int start, int *distances);
void mx_print_routes(t_graph *graph, int start, int end);
void mx_print_all_routes(t_graph *graph);
void mx_insertion_sort(int *neighbors, int num_neighbors, t_graph *graph);

#endif

