#include "../inc/pathfinder.h" 
 
int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_print_error(USAGE_ERROR, NULL, 0);
        return 1;  
    }

    t_graph *graph = mx_read_file(argv[1]);

    mx_print_all_routes(graph);

    mx_free_graph(graph);
    return 0; 
}


