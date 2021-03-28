#include "libmx.h"

int mx_atoi(const char *str) {
    int result = 0;
    bool negative = 0;
    bool positive = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(result == 0 && negative == 0 && positive == 0) {
            if(mx_isdigit(str[i])) {
                result *= 10;
                result += (str[i] - 48);
            }
            else if(str[i] == '-') {
                negative = 1;
            }
            else if(str[i] == '+') {
                positive = 1;
            }
            else {
                return 0;
            }
        }
        else if(result != 0 || negative != 0 || positive != 0) {
            if(mx_isdigit(str[i])) {
                result *= 10;
                result += (str[i] - 48);
            }
            else {
                return 0;
            }
        }
    }
    if(negative) {
        result *= -1;
    }
    return result;
}
