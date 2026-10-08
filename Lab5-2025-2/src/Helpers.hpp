//
// Created by jolumarti on 2026-10-08.
//

#ifndef LAB_HELPERS_HPP
#define LAB_HELPERS_HPP
#include "common.hpp"

class Helpers {
public:
    static void open_ifstream(ifstream &input, const char *filename);
    static void open_ofstream(ofstream &output, const char *filename);
    static char *read_line(ifstream &input, char deli);
    static void print_filled_line(ostream &output, char deli);
    static char *copy_cstring(const char *source);
    static void get_str(char *this_str, char *cstr);
    static void set_str(char *&this_str, const char* cstr);
};


#endif //LAB_HELPERS_HPP
