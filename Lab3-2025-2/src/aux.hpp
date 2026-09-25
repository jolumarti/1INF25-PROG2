#ifndef AUX_HPP
#define AUX_HPP
#include "utils.hpp"
void open_in_file(ifstream &input, const char *file_name);
void open_out_file(ofstream &output, const char *file_name);
char *read_line(ifstream &input, char deli);
void print_filled_line(ofstream &output, char deli);
char *copy_cstring(const char *source);
#endif //AUX_HPP
