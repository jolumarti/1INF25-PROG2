//
// Created by jolumarti on 2026-09-03.
//

#include "auxFunctions.hpp"

void open_in_file(ifstream &input, const char *file_name) {
    input.open(file_name, ios::in);
    if (!input.is_open()) {
        cout << "El archivo no se pudo abrir: " << file_name << endl;
        exit(1);
    }
}

void open_out_file(ofstream &output, const char *file_name) {
    output.open(file_name, ios::out);
    if (!output.is_open()) {
        cout << "El archivo no se pudo abrir: " << file_name << endl;
        exit(1);
    }
    output << fixed << setprecision(2);
}

char *read_line(ifstream &input, char deli) {
    char buffer[MAX_BUFFER];
    input.getline(buffer, MAX_BUFFER, deli);
    int len = strlen(buffer);
    char *p = new char[len + 1]{};
    if (buffer[len - 1] == '\r') buffer[len - 1] = '\0'; // remove \r if present recheck on unbut
    strcpy(p, buffer);
    return p;
}

char *copy_cstring(const char *source) {
    char *copy = new char[strlen(source) + 1]{};
    strcpy(copy, source);
    return copy;
}

void print_filled_line(ofstream &output, char delimitador) {
    output << setw(LINE_SIZE) << setfill(delimitador) << delimitador << setfill(' ') << endl;
}
