#include "pathfinder.h"

char *mx_parse(char *str, char delim) {
    if(mx_strlen(str) < 1 || !str) {
        return NULL;
    }
    else if(mx_get_char_index(str, delim) < 0) {
        char *result = mx_strdup(str);
        mx_strdel(&str);
        return result;
    }
    else {
        char *result = mx_strndup(str, mx_get_char_index(str, delim));
            char *str_cpy = mx_strdup(str+mx_get_char_index(str, delim)+1);
            mx_memset(str, '\0', sizeof(char)*mx_strlen(str));
            mx_strcpy(str, str_cpy);
            mx_strdel(&str_cpy);
            // if(str_cpy) {
            //     mx_strcpy(str, str_cpy);
            //     mx_strdel(&str_cpy);
            // }
            // else {
            //     mx_strdel(&str);
            // }
        return result;
    }
}

//     if (!str) {
//         return NULL;
//     }

//     if(mx_get_char_index(str, delim) < 1) {
//         char *result = mx_strndup(str, mx_get_char_index(str, delim));
//         char *str_cpy = mx_strdup(str);
//         mx_memset(str, 0, mx_strlen(str));
//         mx_strcpy(str, str_cpy+mx_get_char_index(str_cpy, delim)+1);
//         mx_strdel(&str_cpy);
//         return result;
//     }
//     else {
//         char *result = mx_strdup(str);
//         // mx_strdel(&str);
//         return result;
//     }
// }
