#include "../inc/pathfinder.h"

bool mx_validate_bridge_line(const char *line) {
    if (!line || *line == '\0') {
        return false;
    }

    const char *comma_pos = mx_strchr(line, ',');
    const char *dash_pos = mx_strchr(line, '-');

    if (!comma_pos || !dash_pos ||
        comma_pos == line || dash_pos == line || 
        dash_pos >= comma_pos || *(comma_pos + 1) == '\0') {
        return false;
    }

    if (dash_pos == line || *(dash_pos - 1) == '-') {
        return false;
    }

    size_t island1_len = dash_pos - line;
    size_t island2_len = comma_pos - dash_pos - 1;

    if (island1_len == island2_len && 
        mx_strncmp(line, dash_pos + 1, island1_len) == 0) {
        return false;  
    }

    for (const char *p = line; p < dash_pos; ++p) {
        if (!mx_isalpha(*p)) {
            return false;
        }
    }

    if (*(dash_pos + 1) == '-' || *(dash_pos + 1) == ',') { 
        return false;
    }

    for (const char *p = dash_pos + 1; p < comma_pos; ++p) {
        if (!mx_isalpha(*p)) {
            return false;
        }
    }

    for (const char *p = comma_pos + 1; *p != '\0'; ++p) {
        if (!mx_isdigit(*p)) {
            return false;
        }
    }

    int length = mx_atoi(comma_pos + 1);
    if (length <= 0) {
        return false;
    }

    return true;
}
