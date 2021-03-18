#include "../inc/pathfinder.h"

int mx_find_isl(char *isl_name, t_islands **isl_list) {
    t_islands *tmp = *isl_list;
    int result = -1;
    while (tmp->next) {
        if(mx_strcmp(tmp->name, isl_name) == 0) {
            result = tmp->id;
            break;
        }
        tmp = tmp->next;
    }
    if(result == -1 && mx_strcmp(tmp->name, isl_name) == 0) {
        result = tmp->id;
    }
    free(tmp);
    return result;
}
