#include "libmx.h"

unsigned int mx_atoui(char *str) {
    unsigned int result = 0;
    if (!str) {
        return 0;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if(mx_isdigit(str[i])) {
            result *= 10;
            result += (str[i]-48);
        }
        else {
            result = 0;
            break;
        }
    }
    mx_strdel(&str);
    return result;
}
