//
// Created by jolumarti on 2026-09-03.
//

#ifndef LAB2_2026_2_AUXFUNCTIONS_HPP
#define LAB2_2026_2_AUXFUNCTIONS_HPP
#include "Utils.hpp"
void open_in_file(ifstream &input, const char *file_name);
void open_out_file(ofstream &output, const char *file_name);
char *read_line(ifstream &input, char deli);
void print_filled_line(ofstream &output, char deli);

#endif //LAB2_2026_2_AUXFUNCTIONS_HPP