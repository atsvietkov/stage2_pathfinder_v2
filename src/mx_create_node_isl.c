#include "../inc/pathfinder.h"

t_islands *mx_create_node_isl(char *isl_name) {
    t_islands *node = malloc(sizeof(t_islands));
    // if(!isl_name) {
    //     return NULL;
    // }
    // else {
        node->id=-1;
        node->name=isl_name;
        node->next=NULL;
        return node;
    // }
}
