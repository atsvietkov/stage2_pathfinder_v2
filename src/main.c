#include "../inc/pathfinder.h"

// clang -c src/*.c                 
// clang -o a.out *.o -L./libmx -lmx

int main(int argc, char **argv) {
    int status_code = 0;

    status_code = mx_valid_argc(argc);
    if (status_code == 0) {
        status_code = mx_file_exist(argv[1]);
    }
    if(status_code == 0) {
        status_code = mx_file_noempty(argv[1]);
    }



    if (status_code == 1) {
        mx_print_err("usage: ./pathfinder [filename]\n");
        return 1;
    }
    else if (status_code == 2) {
        mx_print_err("error: file ");
        mx_print_err(argv[1]);
        mx_print_err(" does not exist\n");
        return 2;
    }
    else if (status_code == 3) {
        mx_print_err("error: file ");
        mx_print_err(argv[1]);
        mx_print_err(" is empty\n");
        return 2;
    }

    mx_printintn(status_code);
    mx_printstrn("end");
}
