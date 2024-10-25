#include <../inc/libmx.h> 

char *mx_file_to_str(const char *file) {
    if (!file) {
        return NULL;
    }

    int fd = open(file, O_RDONLY);

    if (fd < 0) {
        return NULL;
    }
    
    int lenght = 0;
    char element;

	while (read(fd, &element, 1) != 0) {
		lenght ++;
	}

    if (close(fd) < 0) {
        return NULL;
    }

    int fd1 = open(file, O_RDONLY);

    if (fd1 < 0) {
        return NULL;
    }

    char *str = mx_strnew(lenght);

    for (int i = 0; read(fd1, &element, 1); i++) {
        str[i] = element;
    }

    if (close(fd) < 0) {
        return NULL;
    }

    return str;
}

