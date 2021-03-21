#include "../inc/pathfinder.h"

void mx_pathfinder_core(unsigned int size, 
                        int bridges[size][size], 
                        char islands[size][ARRAY_WIDTH], 
                        unsigned int id_start, 
                        unsigned int id_end) {
    int route[2][size];
    // mx_memset(route, 0, sizeof(unsigned int) * 2 * size);
    for (int i = 0; i < size; i++) {
        route[0][i] = -1;
        route[1][i] = -1;
    }


    route[0][0] = id_start;
    bool visited   = FALSE;
    bool good_step = FALSE;
    bool end_route = FALSE;
    bool bad_route = FALSE;
    
    for (int step = 1; step < size && end_route == FALSE ; step++) {
        visited   = FALSE;
        good_step = FALSE;
        end_route = FALSE;
        for (unsigned int id_now = 0; id_now < size && good_step == FALSE; id_now++) {
            if (bridges[route[0][step-1]][id_now] != 0) {
                for(int i = 0; i <= step; i++) {
                    if (route[0][i] == id_now) {
                        visited = TRUE;
                        break;
                    }
                }
                if(visited == FALSE) {
                    mx_printstrn(islands[id_now]);
                    route[0][step] = id_now;
                    good_step = TRUE;
                    if (id_now == id_end) {
                        end_route = TRUE;
                    }
                    // break;
                }
            }
        }
        // if(route[0][step] == id_end) {
        //     end_route = TRUE;
        // }





            // mx_printstrn("1");
            // for(unsigned int i = 0; i <= step ; i++) {
            //     mx_printstrn("2");
            //     if (route[0][i] == id_now) {
            //         visited = TRUE;
            //         mx_printstrn("3");
            //         break;
            //     }
            // }
            // mx_printstrn("4");
            // if(visited == FALSE && bridges[route[0][step-1]][id_now] != 0) {
            //     mx_printstrn("5");
            //     mx_printstrn("Mark.");
            //     route[0][step] = id_now;
            //     good_step = TRUE;
                
            //     break;
            // }
            // // else if()
        // }

        // mx_printstrn("6");
        // if(route[0][step] == id_end) {
        //     mx_printstrn("7");
        //     end_route = TRUE;
        //     break;
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
