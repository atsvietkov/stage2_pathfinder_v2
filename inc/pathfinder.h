#include "../libmx/inc/libmx.h"

void mx_print_err(const char *str);
char *mx_parse(char *str, char delim);

int mx_valid_argc(int argc);
int mx_file_exist(const char *filename);
int mx_file_noempty(const char *filename);
int mx_valid_line(const char *buffer1, const char *buffer2, unsigned int buffer3);
unsigned int mx_line_amount(char *file);
