#include "../inc/pathfinder.h"

int mx_arrcmp(unsigned int size, int route1[size], int route2[size], unsigned int id_end) {
    int result = 0;
    for (unsigned int i = 0; i < size; i++) {
        if(route1[i] != route2[i]) {
            result = route1[i] - route2[i];
            break;
        }
        if (route1[i] == (int)id_end || route2[i] == (int)id_end) {
            break;
        }
    }
    return result;
}
