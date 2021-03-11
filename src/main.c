#include "../inc/pathfinder.h"

// clang -c src/*.c                 
// clang -o a.out *.o -L./libmx -lmx

int main(int argc, char **argv) {
    int status_code = 0;
    unsigned int nodes_q_line = 0;
    char *file = mx_file_to_str(argv[1]);
    char *nodes[256];
    int line_counter = 2;

    status_code = mx_valid_argc(argc);
    if (status_code == 0) {
        status_code = mx_file_exist(argv[1]);
    }
    if (status_code == 0) {
        status_code = mx_file_noempty(argv[1]);
    }
    if (status_code == 0) {
        // char *file = mx_file_to_str(argv[1]);
        nodes_q_line = mx_atoui(mx_parse(file, '\n'));
        if (nodes_q_line < 1) {
            status_code = 0;
        }
    }
    
    if (status_code == 0) {
        char *file_cpy = mx_strdup(file);
        for ( ; file_cpy; line_counter++) {
            char *line = mx_parse(file_cpy, '\n');
            // mx_printstrn(file_cpy);
            mx_printstrn("----");
            char *buf1 = mx_parse(line, '-');
            char *buf2 = mx_parse(line, ',');
            int   buf3 = mx_atoui(mx_parse(line, '\n'));
            mx_printstrn(buf1);
            mx_printstrn(buf2);
            mx_printintn(buf3);
            status_code = mx_valid_line(buf1, buf2, buf3);
            // mx_strdel(&line);
            mx_strdel(&buf1);
            mx_strdel(&buf2);
            if (status_code != 0) {
                break;
            }
        }
    }


    if (status_code == 1) {
        mx_print_err("usage: ./pathfinder [filename]\n");
    }
    else if (status_code == 2) {
        mx_print_err("error: file ");
        mx_print_err(argv[1]);
        mx_print_err(" does not exist\n");
    }
    else if (status_code == 3) {
        mx_print_err("error: file ");
        mx_print_err(argv[1]);
        mx_print_err(" is empty\n");
    }
    else if (status_code == 4) {
        mx_print_err("error: line 1 is not valid\n");
    }
    else if (status_code == 5) {
        mx_print_err("error: line ");
        // mx_print_err(line_counter);
        mx_print_err(" is not valid\n");
    }

    mx_printintn(status_code);
    mx_printintn(nodes_q_line);
    mx_printintn(line_counter);
    mx_printstrn("end");

    mx_strdel(&file);
    return status_code;
}
