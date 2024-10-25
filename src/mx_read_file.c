#include "../inc/pathfinder.h"

t_graph *mx_read_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        mx_print_error(FILE_NOT_EXIST_ERROR, filename, 0);
        exit(1);
    }

    char *line = NULL;
    int islands_num = 0;
    int island_index = 0;
    t_graph *graph = NULL;
    long total_bridge_length = 0;
    bool has_duplicates = false;  
    int result = mx_read_line(&line, 1, '\n', fd);

    if (result == -1) {
        close(fd);
        mx_print_error(FILE_EMPTY_ERROR, filename, 0);
        exit(1);
    }

    if (result > 0) {
        islands_num = mx_atoi(line);
        if (islands_num <= 0 || !mx_isnumber(line)) {
            mx_strdel(&line);
            close(fd);
            mx_print_error(INVALID_LINE_ERROR, NULL, 1);  
            exit(1);
        }
        graph = mx_create_graph(islands_num);
        mx_strdel(&line);
    }
    else {
        mx_strdel(&line);
        close(fd);
        mx_print_error(INVALID_LINE_ERROR, NULL, 1);  
        exit(1);
    }

    int line_number = 2;
    result = 0;

    while ((result = mx_read_line(&line, 1, '\n', fd)) != -1) {
        if (result == -3 || result == 0 || (line && *line == '\0')) {
            mx_strdel(&line);
            mx_free_graph(graph);
            close(fd);
            mx_print_error(INVALID_LINE_ERROR, NULL, line_number);  
            exit(1);
        }

        if (!mx_validate_bridge_line(line)) {
            mx_strdel(&line);
            mx_free_graph(graph);
            close(fd);
            mx_print_error(INVALID_LINE_ERROR, NULL, line_number);  
            exit(1);
        }

        char **parts = mx_strsplit(line, ',');
        char **islands = mx_strsplit(parts[0], '-');

        t_island *island1 = mx_add_island(graph, islands[0], &island_index);
        t_island *island2 = mx_add_island(graph, islands[1], &island_index);

        int length = atoi(parts[1]);
        if (mx_add_bridge(island1, island2, length)) {
            has_duplicates = true;  
        }
        total_bridge_length += length;

        mx_del_strarr(&parts);
        mx_del_strarr(&islands);
        mx_strdel(&line);

        line_number++;
    }

    if (graph->num_islands != islands_num) {
        mx_free_graph(graph);
        mx_print_error(INVALID_ISLAND_NUMBER_ERROR, NULL, 0);  
        exit(1);
    }

    if (has_duplicates) {
        mx_free_graph(graph);
        mx_print_error(DUPLICATE_BRIDGES_ERROR, NULL, 0);  
        exit(1);
    }

    if (total_bridge_length > INT_MAX) {
        mx_free_graph(graph);
        mx_print_error(SUM_OF_BRIDGES_ERROR, NULL, 0); 
        exit(1);
    }

    close(fd);
    return graph;
}
