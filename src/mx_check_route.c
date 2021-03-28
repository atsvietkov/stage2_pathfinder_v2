#include "../inc/pathfinder.h"

bool mx_check_route(unsigned int size,
                    int bridges[size][size],
                    int route[size],
                    unsigned int id_start,
                    unsigned int id_end) {
    //
    bool result = TRUE;
    if(route[0] != id_start) {
        result = FALSE;
    }
    for (unsigned int i = 1; i < size && result == TRUE; i++) {
        for (unsigned int j = 0; j < i; j++) {
            if (route[i-1] == id_end) {
                break;
            }
            if (route[i] == route[j]) {
                result = FALSE;
                break;
            }
        }
    }
    for(unsigned int i = 1; i < size && result == TRUE; i++) {
        if(bridges[route[i]][route[i-1]] < 1) {
            result = FALSE;
            break;
        }
        if(route[i] == id_end) {
            break;
        }
    }
    return result;
}
