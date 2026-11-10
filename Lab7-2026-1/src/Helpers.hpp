//
// Created by jolumarti on 2026-10-08.
//

#ifndef LAB_HELPERS_HPP
#define LAB_HELPERS_HPP

#define S_BUFFER 16
#define M_BUFFER 64
#define L_BUFFER 128
#define XL_BUFFER 256
#define INCREMENT 5
#define LINE_SIZE 180
#define NOT_FOUND -1
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

class Helpers {
public:
    static void open_ifstream(ifstream &input, const char *filename);

    static void open_ofstream(ofstream &output, const char *filename);

    static void print_filled_line(ostream &output, char deli);

    static void print_centered_title(ostream &output, const char *title);

    static void print_date(ostream &output, int date);

    static void get_str(char *this_str, char *cstr);

    static void set_str(char *&this_str, const char *cstr);

    static int date_to_int(int dd, int mm, int yy);

    static string int_a_char(int n);

    static void construir_nombre_archivo(char *destino, const char *base, int hh);
};


#endif //LAB_HELPERS_HPP
