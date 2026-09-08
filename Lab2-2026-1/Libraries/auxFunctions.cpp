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
    char *p = new char[strlen(buffer) + 1]{};
    strcpy(p, buffer);
    return p;
}
void print_filled_line(ofstream &output, char delimitador) {
    output << setw(LINE_SIZE) << setfill(delimitador) << delimitador << setfill(' ') << endl;
}