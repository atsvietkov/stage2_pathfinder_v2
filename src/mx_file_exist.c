#include "pathfinder.h"

int mx_file_exist(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        close(fd);
        return 2;
    }
    close(fd);
    return 0;
}
