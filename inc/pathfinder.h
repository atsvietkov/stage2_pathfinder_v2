# include "libmx.h"

# define ARRAY_WIDTH 64
# define TRUE  1
# define FALSE 0

typedef struct s_islands {
    char *name;
    unsigned int id;
    struct s_islands *next;
}       t_islands;

void mx_print_err(const char *str);
char *mx_parse(char *str, char delim);

int mx_valid_argc(int argc);
int mx_file_exist(const char *filename);
int mx_file_noempty(const char *filename);
int mx_valid_line(const char *buffer1, const char *buffer2, unsigned int buffer3);
unsigned int mx_line_amount(char *file);

void mx_print_boundary();
void mx_pathfinder_core(int size, 
                        int bridges[size][size], 
                        char islands[size][ARRAY_WIDTH], 
                        int id_start, 
                        int id_end);
bool mx_check_route(int size,
                    int bridges[size][size],
                    int route[size],
                    int id_start,
                    int id_end);
int mx_arrcmp(unsigned int size, int route1[size], int route2[size], unsigned int id_end);
