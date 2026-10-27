//
// Created by jolumarti on 2026-10-08.
//

#include "Helpers.hpp"

void Helpers::open_ifstream(ifstream &input, const char *filename) {
    input.open(filename, ios::in);
    if (!input.is_open()) {
        cout << "El archivo no se pudo abrir: " << filename << endl;
        exit(1);
    }
}

void Helpers::open_ofstream(ofstream &output, const char *filename) {
    output.open(filename, ios::out);
    if (!output.is_open()) {
        cout << "El archivo no se pudo abrir: " << filename << endl;
        exit(1);
    }
    output << fixed << setprecision(2);
}

char * Helpers::read_line(ifstream &input, char deli) {
    char buffer[L_BUFFER];
    input.getline(buffer, L_BUFFER, deli);
    int len = strlen(buffer);
    char *p = new char[len + 1]{};
    if (len > 0 && buffer[len - 1] == '\r') buffer[len - 1] = '\0';
    strcpy(p, buffer);
    return p;
}

void Helpers::print_filled_line(ofstream &output, char deli) {
    output << setw(LINE_SIZE) << setfill(deli) << deli << setfill(' ') << endl;
}

char * Helpers::copy_cstring(const char *source) {
    char *copy = new char[strlen(source) + 1]{};
    strcpy(copy, source);
    return copy;
}

void Helpers::get_str(char *this_str, char *cstr) {
    if (this_str) strcpy(cstr, this_str);
    else cstr[0] = 0;
}

void Helpers::set_str(char *&this_str, const char *cstr) {
    if (this_str) delete[] this_str;
    this_str = new char[strlen(cstr)+1];
    strcpy(this_str, cstr);
}
