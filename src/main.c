#include "../inc/pathfinder.h"

// clang -c src/*.c                 
// clang -o a.out *.o -L./libmx -lmx

// int main() {
//     char *a = "128";
//     char *b = "-";

//     mx_printintn(mx_atoui(a));
//     mx_printintn(mx_atoui(b));

// }

int main(int argc, char **argv) {
    int status_code = 0;
    unsigned int nodes_q_line = 0;
    char *file = mx_file_to_str(argv[1]);
    char *nodes[256];
    int line_counter = 0;

    status_code = mx_valid_argc(argc);
    if (status_code == 0) {
        status_code = mx_file_exist(argv[1]);
    }
    if (status_code == 0) {
        status_code = mx_file_noempty(argv[1]);
    }
    if (status_code == 0) {
        nodes_q_line = mx_atoui(mx_parse(file, '\n'));
        if (nodes_q_line < 1) {
            status_code = 0;
        }
    }
    if (status_code == 0) {
        unsigned int lines_in_file = mx_line_amount(file);
        char islands[nodes_q_line][64];
        bool end_of_islands = 0;
        unsigned int islands_line = 0;
        unsigned int bridges[nodes_q_line][nodes_q_line];
    
        mx_memset(islands, '\0', sizeof(char)*nodes_q_line*64);
        mx_memset(bridges, 0, sizeof(unsigned int)*nodes_q_line*nodes_q_line);
        
        for (int i = 0; i < nodes_q_line; i++) {
            for (int j = 0; j < nodes_q_line; j++) {
                mx_printint(bridges[i][j]);
                mx_printchar('\t');
            }
            mx_printchar(10);
        }

        char *file_cpy = mx_strdup(file);
        unsigned int sum_of_bridges = 0;
        for (line_counter = 0; status_code == 0 && line_counter < lines_in_file; line_counter++) {
            char *line = mx_parse(file_cpy, '\n');
            char *buf1 = mx_parse(line, '-');
            char *buf2 = mx_parse(line, ',');
            unsigned int buf3 = mx_atoui(mx_parse(line, '\n'));
            bool island_exist = 0;
            

            status_code = mx_valid_line(buf1, buf2, buf3);
            
            if(status_code == 0) {
                island_exist = 0;
                for (int i = 0; mx_strlen(islands[i]) > 0 && i < nodes_q_line; i++) {
                    if(mx_strcmp(buf1, islands[i]) == 0) {
                        island_exist = 1;
                        break;
                    }
                }
                if(end_of_islands == 1 && island_exist == 0) {
                    status_code = 6;
                }
                if(island_exist == 0 && status_code == 0) {
                    for (int i = 0; /* i < mx_strlen(buf1) */ buf1[i]; i++) {
                        islands[islands_line][i] = buf1[i];
                    }
                    mx_printstrn(islands[islands_line]);    // debug
                    islands_line++;
                    if (islands_line == nodes_q_line) {
                        end_of_islands = 1;
                    }
                }
                island_exist = 0;
                for (int i = 0; mx_strlen(islands[i]) > 0 && i < nodes_q_line; i++) {
                    if(mx_strcmp(buf2, islands[i]) == 0) {
                        island_exist = 1;
                        break;
                    }
                }
                if(end_of_islands == 1 && island_exist == 0) {
                    status_code = 6;
                }
                if(island_exist == 0 && status_code == 0) {
                    for (int i = 0; /* i < mx_strlen(buf2) */ buf2[i]; i++) {
                        islands[islands_line][i] = buf2[i];
                    }
                    mx_printstrn(islands[islands_line]);    // debug
                    islands_line++;
                    if (islands_line == nodes_q_line) {
                        end_of_islands = 1;
                    }
                }
            }
            sum_of_bridges += buf3;
            
            unsigned int id_buf1 = 0;
            unsigned int id_buf2 = 0;

            

            for (int i = 0; islands[i][0] !=  '\0'; i++) {
                if (mx_strcmp(buf1, islands[i]) == 0) {
                    id_buf1 = i;
                }
                else if (mx_strcmp(buf2, islands[i]) == 0) {
                    id_buf2 = i;
                }
            }
            if (bridges[id_buf1][id_buf2] != 0 || bridges[id_buf2][id_buf1] != 0) {
                status_code = 7;
                break;
            }
            bridges[id_buf1][id_buf2] = buf3;
            bridges[id_buf2][id_buf1] = buf3;

            mx_strdel(&buf1);
            mx_strdel(&buf2);
        }

        for (int i = 0; i < nodes_q_line; i++) {
            for (int j = 0; j < nodes_q_line; j++) {
                mx_printint(bridges[i][j]);
                mx_printchar('\t');
            }
            mx_printchar(10);
        }

        if(status_code == 0 && islands_line < nodes_q_line) {
            status_code = 6;
        }
        else if (status_code == 0 && sum_of_bridges > INT_MAX) {
            status_code = 8;
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
        mx_printint_err(line_counter+1);
        mx_print_err(" is not valid\n");
    }
    else if (status_code == 6) {
        mx_print_err("error: invalid number of islands\n");
    }
    else if (status_code == 7) {
        mx_print_err("error: duplicate bridges\n");
    }
    else if (status_code == 8) {
        mx_print_err("error : sum of bridges length is too big\n");
    }
    mx_printstrn("--------");
    mx_printstr("Status code: ");
    mx_printintn(status_code);
    mx_printstr("Line 1: ");
    mx_printintn(nodes_q_line);
    mx_printstr("line_counter: ");
    mx_printintn(line_counter+1);
    mx_printstrn("end");

    mx_strdel(&file);
    return status_code;
}
