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

void Helpers::print_filled_line(ostream &output, char deli) {
    output << setw(LINE_SIZE) << setfill(deli) << deli << setfill(' ') << endl;
}

void Helpers::print_centered_title(ostream &output, const char *title) {
    int length = LINE_SIZE + strlen(title);
    output << setw(length / 2) << title  << endl;
}

void Helpers::print_date(ostream &output, int date) {
    int yy, mm, dd;
    yy = date / 10000;
    mm = (date / 100) % 100;
    dd = date % 100;
    output << setw(2) << setfill('0') << dd << '/' << setw(2) << mm << '/' << yy << setfill(' ');
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
    char *aux = nullptr;
    if (cstr != nullptr) {
        aux = new char[strlen(cstr) + 1];
        strcpy(aux, cstr);
    }
    delete[] this_str;
    this_str = aux;
}

int Helpers::date_to_int(int dd, int mm, int yy) {
    return dd + mm * 100 + yy * 10000;
}
