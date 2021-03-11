#include "../inc/pathfinder.h"

int mx_file_noempty(const char *filename) {
    char *str = mx_file_to_str(filename);
    if(mx_strlen(str) == 0) {
        mx_strdel(&str);
        return 3;
    }
    mx_strdel(&str);
    return 0;
}
