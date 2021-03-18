#include "../inc/pathfinder.h"

void mx_push_back_isl(char *isl_name, t_islands **isl_list) {
    mx_printstrn("1");
    if (mx_find_isl(isl_name, isl_list) == -1) {
        t_islands *node = mx_create_node_isl(isl_name);
        if(isl_list == NULL || *isl_list == NULL) {
            node->id=0;
            *isl_list = node;
        }
        else {
            int last_id = -1;
            t_islands *tmp = *isl_list;
            while(tmp->next) {
                last_id = tmp->id;
                tmp = tmp->next;
            }
            node->id = last_id+1;
            tmp->next = node;
        }
    }
    
}

// void mx_push_back(t_list **list, void *data) {
//     t_list *node = mx_create_node(data);
//     if(list == NULL || *list == NULL) {
//         *list = node;
//     }
//     else {
//         t_list *tmp = *list;
//         while(tmp->next) {
//             tmp = tmp->next;
//         }
//         tmp->next = node;
//     }
// }