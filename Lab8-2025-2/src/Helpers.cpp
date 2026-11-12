//
// Created by jolumarti on 2026-10-08.
//

#include "Helpers.hpp"

void Helpers::open_if(ifstream &input,  const string &filename){
    input.open(filename, ios::in);
    if (!input.is_open()) {
        cout << "El archivo no se pudo abrir: " << filename << endl;
        exit(1);
    }
}

void Helpers::open_of(ofstream &output, const string &filename){
    output.open(filename, ios::out);
    if (!output.is_open()) {
        cout << "El archivo no se pudo abrir: " << filename << endl;
        exit(1);
    }
    output << fixed << setprecision(2);
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

string Helpers::int_a_char(int n) {
    return to_string(n);
}

void Helpers::construir_nombre_archivo(char *destino, const char *base, int hh) {
    strcpy(destino, base);

    char buffer_hh[10];
    sprintf(buffer_hh, "%02d", hh);

    strcat(destino, buffer_hh);
    strcat(destino, ".csv");
}

