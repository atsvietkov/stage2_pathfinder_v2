#include "../inc/pathfinder.h"

void mx_pathfinder_core(unsigned int size, 
                        int bridges[size][size], 
                        char islands[size][ARRAY_WIDTH], 
                        unsigned int id_start, 
                        unsigned int id_end) {
    int route[3*size][size];
    // mx_memset(route, 0, sizeof(unsigned int) * 2 * size);
    for (int i = 0; i < 3*size; i++) {
        for (int j = 0; j < size; j++) {
            route[i][j] = -1;
        }
    }


    route[0][0] = id_start;
    route[1][0] = mx_connects(size, bridges, id_start) - 1;
    bool visited   = FALSE;
    bool good_step = FALSE;
    bool end_route = FALSE;
    bool bad_route = FALSE;
    
    for (int step = 1; step < size && end_route == FALSE ; step++) {
        visited   = FALSE;
        good_step = FALSE;
        end_route = FALSE;
        for (unsigned int id_now = 0; id_now < size && good_step == FALSE; id_now++) {
            visited = FALSE;
            if (bridges[route[0][step-1]][id_now] != 0) {
                unsigned int visited_connects = 0;
                for(int i = 0; i <= step; i++) {
                    if (route[0][i] == id_now) {
                        visited = TRUE;
                        visited_connects++;
                    }
                }
                if(visited == FALSE) {
                    // mx_printstrn(islands[id_now]);
                    route[0][step] = id_now;
                    // for(int i = 0; i < step; i++) {

                    // }
                    route[1][step] = mx_connects(size, bridges, id_now) - visited_connects;
                    good_step = TRUE;
                    if (id_now == id_end) {
                        end_route = TRUE;
                    }
                    // break;
                }
            }
        }
    // if(good_step == FALSE) {
    //     bad_route = TRUE;
    // }






        
    
    }




    mx_print_boundary();
    mx_printstr("Path: ");
    mx_printstr(islands[id_start]);
    mx_printstr(" -> ");
    mx_printstr(islands[id_end]);
    mx_printchar(10);
    mx_printstr("Route: ");
    

    for (int i = 0; route[0][i] > -1 ; i++) {
        mx_printstr(islands[route[0][i]]);
        if(route[0][i] == id_end) {
            break;
        }
        mx_printstr(" -> ");
    }
    // mx_printstr(islands[id_end]);

    mx_printchar(10);
    mx_printstr("Distance: ");
    mx_printchar(10);
    mx_print_boundary();

}
