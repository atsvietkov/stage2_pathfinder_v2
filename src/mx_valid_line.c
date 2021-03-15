#include "../inc/pathfinder.h"

int mx_valid_line(const char *buffer1, const char *buffer2, unsigned int buffer3) {
    if (!buffer1 || !buffer2) {
        return 5;
    }
    for (int i = 0; buffer1[i]; i++) {
        if(!mx_isalpha(buffer1[i])) {
            return 5;
        }
    }
    for (int i = 0; buffer2[i]; i++) {
        if(!mx_isalpha(buffer2[i])) {
            return 5;
        }
    }
    if (buffer3 < 1) {
        return 5;
    }
    // mx_printstrn("Valid.");
    return 0;
}
