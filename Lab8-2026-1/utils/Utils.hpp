//
// Created by erasm on 11/06/2026.
//

#ifndef L7261_UTILS_HPP
#define L7261_UTILS_HPP
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>
#define LINE_SIZE 160
using namespace std;

class Utils {
public:
    static void apertura_archivo_lectura(ifstream &, string);

    static void apertura_archivo_escritura(ofstream &, string);

    static char *fecha_a_path(const char *);

    static char *int_a_char(int);

    static void construir_nombre_archivo(char *, const char *, int);

    static void construir_path_dia(char *, const char *);

    static void print_centered_title(ostream &output, const string& title) ;

    static void print_date(ostream &output, int date);

    static void print_filled_line(ostream &output, char deli);
};


#endif //L7261_UTILS_HPP
