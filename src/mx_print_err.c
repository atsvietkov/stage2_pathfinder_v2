#include "../inc/pathfinder.h"

void mx_print_err(const char *str) {
    if(str) {
        write(2, str, mx_strlen(str));
    }
}
