#include "../inc/pathfinder.h"

unsigned int mx_line_amount(char *file) {
    unsigned int counter = 0;
    if (file) {
        for (unsigned int i = 0; file[i]; i++) {
            if(file[i] == '\n') {
                counter++;
            }
        }
    }
    return counter;
}
