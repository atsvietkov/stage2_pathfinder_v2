#include "../libmx/inc/libmx.h"

typedef struct s_islands {
    char *name;
    int id;
    struct s_islands *next;
}       t_islands;

void mx_print_err(const char *str);
char *mx_parse(char *str, char delim);

int mx_valid_argc(int argc);
int mx_file_exist(const char *filename);
int mx_file_noempty(const char *filename);
int mx_valid_line(const char *buffer1, const char *buffer2, unsigned int buffer3);
unsigned int mx_line_amount(char *file);

t_islands *mx_create_node_isl(char *isl_name);
void mx_push_back_isl(char *isl_name, t_islands **isl_list);
int mx_find_isl(char *isl_name, t_islands **isl_list);
