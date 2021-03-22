#include "../inc/pathfinder.h"

unsigned int mx_connects(unsigned int size, 
                         int bridges[size][size], 
                         unsigned int id_now) {
    //
    unsigned int connects = 0;
    for (unsigned int i = 0; i < size; i++) {
        if(bridges[id_now][i] != 0) {
            connects++;
        }
    }
    return connects;
}
