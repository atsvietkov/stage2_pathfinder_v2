#include "libmx.h"

int mx_quicksort(int *arr, int left, int right) {
    int swap = 0;
    if (!arr) {
        swap = -1;
    }
    else {
        if (left < right) {
            int l = left;
            int r = right;
            int pivot = arr[right];

            while (l <= r) {
                while (arr[l] < pivot) {
                    l++;
                }
                while (arr[r] > pivot) {
                    r--;
                }
                if (l <= r) {
                    if (arr[r] != arr[l]) {
                        int temp = arr[l];
                        arr[l] = arr[r];
                        arr[r] = temp;
                        swap++;
                    }
                    r--;
                    l++;
                }
            }
            swap += mx_quicksort(arr, left, r);
            swap += mx_quicksort(arr, l, right);
        }
    }
    return swap;
}
