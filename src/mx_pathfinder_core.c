#include "../inc/pathfinder.h"

void mx_pathfinder_core(unsigned int size, 
                        int bridges[size][size], 
                        char islands[size][ARRAY_WIDTH], 
                        unsigned int id_start, 
                        unsigned int id_end) 
                        {
    
    unsigned int num_of_bridges = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if(bridges[i][j] > 0) {
                num_of_bridges++;
            }
        }
    }
    int route[(unsigned int)mx_pow(num_of_bridges, num_of_bridges)][size];
    for (int i = 0; i < (unsigned int)mx_pow(num_of_bridges, num_of_bridges); i++) {
        for (int j = 0; j < size; j++) {
            route[i][j] = -1;
        }
    }
    int tmp_route[size];
    for (int i = 0; i < size; i++) {
        tmp_route[i] = -1;
    }
    tmp_route[0] = id_start;
    bool goodstep = FALSE;
    bool checkleft = FALSE;


    for (int step = 1; step < size; step++) {
        goodstep = FALSE;
        for(unsigned int next_id = 0; next_id < size; next_id++) {
            for(int backstep = 0; backstep <= step-1 && goodstep == FALSE; backstep++) {
                checkleft = FALSE;
                if(next_id == tmp_route[backstep]) {
                    checkleft = TRUE;
                    break;
                }
                else if(checkleft == FALSE && backstep == step-1) {
                    tmp_route[step] = next_id;
                    goodstep = TRUE;
                    break;
                }
            }
        }
    }
    unsigned int row = 0;
    bool plusone = FALSE;
    bool end = FALSE;
    if(mx_check_route(size, bridges, tmp_route, id_start, id_end) == TRUE) {
        for (int i = 0; i < size; i++) {
            route[row][i] = tmp_route[i];
            if(tmp_route[i] == id_end) {
                break;
            }
        }
        row++;
    }
    // for(int i = 0; i < size; i++) {
    //     mx_printint(tmp_route[i]);
    //     mx_printchar(' ');
    // }
    // mx_printchar(10);
    for ( ; end == FALSE; ) {
        plusone = FALSE;
        tmp_route[size-1]++;
        if(tmp_route[size-1] >= size) {
            plusone = TRUE;
            tmp_route[size-1] = 0;
        }
        for (int backstep = size -2; plusone == TRUE && backstep > 0; backstep--) {
            tmp_route[backstep]++;
            plusone = FALSE;
            if (tmp_route[backstep] >= size) {
                tmp_route[backstep] = 0;
                plusone = TRUE;
            }
        }
        if(mx_check_route(size, bridges, tmp_route, id_start, id_end) == TRUE) {
            bool not_copy = TRUE;
            for (int i = row-1; i >= 0; i--) {
                if (mx_arrcmp(size, route[i], tmp_route, id_end) == 0) {
                    not_copy = FALSE;
                    break;
                }
            }
            if (not_copy == TRUE) {
                for (int i = 0; i < size ; i++) {
                    route[row][i] = tmp_route[i];
                    if (tmp_route[i] == id_end) {
                        break;
                    }
                }
                row++;
            }
        }
        // for(int i = 0; i < size; i++) {
        //     mx_printint(tmp_route[i]);
        //     mx_printchar(' ');
        // }
        // mx_printchar(10);

        for (int i = 1; i < size; i++) {
            if(tmp_route[i] < size-1) {
                break;
            }
            if (i == size-1) {
                end = TRUE;
            }
        }
    }
        
    // for(int i = 0; i < size; i++) {
    //     mx_printint(tmp_route[i]);
    //     mx_printchar(' ');
    // }
    // mx_printchar(10);

    for (int i = 0; route[i][0] == id_start ; i++) {
        mx_printint(i);
        mx_printstr(" :\t");
        for (int j = 0; j < size; j++) {
            mx_printint(route[i][j]);
            mx_printchar('\t');
        }
        mx_printchar(10);
    }




                        }

    // bool correct_route = FALSE;
    // bool completed = FALSE;

    // for()

    //                     }



    // for (unsigned int row = 0; row < (unsigned int)mx_pow(num_of_bridges, 2) && completed == FALSE; ) {
    //     // mx_printintn(row);
    //     if(correct_route == TRUE) {
    //         correct_route = FALSE;
    //         row++;
    //         for (unsigned int i = 0; i < size; i++) {
    //             route[row][i] = route[row-1][i];
    //         }
    //     }
    //     if(row == 0 && route[row][0] == -1) {
    //         route[row][0] = id_start;
    //         for (unsigned int step = 1; step < size; step++) {
    //             route[row][step] = 0;
    //         }
    //     }
    //     else {
    //         for(unsigned int backstep = size - 1; backstep > 0; ) {
    //             // mx_printintn(backstep);
    //             if (route[row][backstep] >= size-1 && backstep == 1) {
    //                 break;
    //             }
    //             if(route[row][backstep] >= size-1) {
    //                 route[row][backstep] = 0;
    //                 route[row][backstep-1]++;
    //                 backstep--;
    //             }
    //             else {
    //                 route[row][backstep]++;
    //             }
    //         }

    //     }
    //     correct_route = mx_check_route(size, bridges, route[row], id_start, id_end);
    //     for (int i = 0; i < size; i++) {
    //         mx_printint(route[row][i]);
    //         mx_printchar(' ');
    //     }
    //     mx_printchar(10);
    //     if(route[row][1] == size-1) {
    //         for(unsigned int i = 1; i < size; i++) {
    //             if (route[row][i] >= size - 1) {
    //                 completed = TRUE;
    //             }
    //             else {
    //                 completed = FALSE;
    //                 break;
    //             }
    //         }
    //         if(completed == TRUE) {
    //             break;
    //         }
    //     }
    // }
    //                     }


            // route[row][0] = id_start;
            // for (unsigned int step = 1; step < size; step++) {
            //     for(int next_id = 0; next_id < size; next_id++) {
            //         bool visited = FALSE;
            //         for (unsigned int prev = 0; prev < step; prev++) {
            //             if(next_id == route[row][prev]) {
            //                 visited = TRUE;
            //                 break;
            //             }
            //             route[row][step] = next_id;
            //         }
            //     }
            // }
            // mx_valid_route(size, bridges, route[row], id_start, id_end);




//     // for (int i = 0; i < (unsigned int)mx_pow(num_of_bridges, 2); i++) {
//     //     mx_printint(i);
//     //     mx_printstr("\t:: ");
//     //     for (int j = 0; j < size; j++) {
//     //         mx_printint(route[i][j]);
//     //         mx_printchar(' ');
//     //     }
//     //     mx_printchar(10);
//     // }

    
//     // route[0][0] = id_start;
//     bool valid_route = FALSE;
//     for(unsigned int row = 0; row < (unsigned int)mx_pow(num_of_bridges, 2);  ) {
//         if(valid_route == TRUE) {
//             row++;
//             valid_route = FALSE;
//             for (int i = 0; i < size; i++) {
//                 route[row][i] = route[row-1][i];
//             }
//         }
//         route[row][0] = id_start;

        
//         if(row == 0) {
//             for(unsigned int i = 1; i < size)
//             // for(unsigned int step = 1; step < size; step++) {
//             //     for(int next_id = 0; next_id < size; next_id++) {
//             //         route[row][step] = next_id;
//             //     }
//             // }
//         }
//         else {
//             for (unsigned int backstep = size-1; backstep > 0; backstep--) {
//                 if (route[row][backstep] < size-1) {
//                     route[row][backstep]++;
//                 }
//             }
//         }
//         valid_route = mx_check_route(size, bridges, route[row], id_start, id_end);
//     }
// }

            // if(row == 0) {
            //     for (unsigned int i = 0; i < size; i++) {
            //         if(i != id_start) {
            //             route[row][step] = i;
            //         }
            //     }
            // }
            // else if(route[row][1] != -1) {

            // }


            // }
            // valid_route = mx_check_route(size, bridges, route[row], id_start, id_end);

    //     }
    // }
    


    // // // // // // // // 

    /*                       
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

*/

// }
