#include "libmx.h"

void mx_printint_err(int n) {
    if (n == -2147483648) {
        write(2, "-2147483648", 11);
    }
    else {
        bool negative = 0;
        if (n < 0) {
            n *= -1;
            negative = 1;
        }

        int len = 0;
        int n_cpy = n;
        for ( ; n_cpy > 0; len++) {
            n_cpy /= 10;
        }

        if (n == 0) {
            // mx_printchar(0+48);
            write(1, 0+48, 1);
        }
        else {
            int arr[len];
            for(int i = 0; i < len; i++) {
                arr[i] = n % 10;
                n /= 10;
            }
            if (negative == 1) {
                // mx_printchar('-');
                write(2, '-', 1);
            }
            for (int i = len-1; i >= 0; i--) {
                // mx_printchar(arr[i]+48);
                write(2, arr[i]+48, 1);
            }
        }
    }
}
