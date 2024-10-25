#include "../inc/pathfinder.h"

void mx_print_error(ErrorType error, const char *filename, int line_number) {
    switch (error) {
        case USAGE_ERROR:
            mx_printerr("usage: ./pathfinder [filename]\n");
            break;
        case FILE_NOT_EXIST_ERROR:
            mx_printerr("error: file ");
            mx_printerr(filename);
            mx_printerr(" does not exist\n");
            break;
        case FILE_EMPTY_ERROR:
            mx_printerr("error: file ");
            mx_printerr(filename);
            mx_printerr(" is empty\n");
            break;
        case INVALID_LINE_ERROR:
            mx_printerr("error: line ");
            mx_printint(line_number);  
            mx_printerr(" is not valid\n");
            break;
        case INVALID_ISLAND_NUMBER_ERROR:
            mx_printerr("error: invalid number of islands\n");
            break;
        case DUPLICATE_BRIDGES_ERROR:
            mx_printerr("error: duplicate bridges\n");
            break;
        case SUM_OF_BRIDGES_ERROR:
            mx_printerr("error: sum of bridges lengths is too big\n");
            break;
        default:
            mx_printerr("error: unknown error\n");
            break;
    }
}
