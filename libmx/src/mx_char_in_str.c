#include "libmx.h"

bool mx_char_in_str(char *s, char c) {
    if(s != NULL) {
        for (int i = 0; i < mx_strlen(s); i++) {
            if(s[i] == c) {
                return 1;
            }
        }
    }
    return 0;
}
