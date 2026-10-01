//
// Created by jolumarti on 2026-09-24.
//

#include "registros.hpp"
//101,17/4/2025,CONTROL,11:00,PROGRAMADA,Luna,Labrador,Negro,CANINO
bool leerRegistro(ifstream &file, void *&data) {
    int cod, yy, mm, dd, h, m;
    char *tipo, *estado, *nombre, *raza, *especie, *color, c;
    file >> cod >> c >> dd >> c >> mm >> c >> yy >> c;
    if (file.eof()) return false;
    tipo = read_line(file, ',');
    file >> h >> c >> m >> c;
    estado = read_line(file, ',');
    nombre = read_line(file, ',');
    raza = read_line(file, ',');
    color = read_line(file, ',');
    especie = read_line(file, '\n');
    void **aux = new void *[8];
    aux[COD] = new int(cod);
    aux[FECHA] = new int(yy * 10000 + mm * 100 + dd);
    aux[HORA] = new int(h * 100 + m);
    aux[TIPO] = tipo;
    aux[ESTADO] = estado;
    aux[NOMBRE] = nombre;
    aux[RAZA] = raza;
    aux[COLOR] = color;
    aux[ESPECIE] = especie;
    data = aux;
    return true;
}

int compararReg(const void *data1, const void *data2) {
    void **list1 = (void **) data1;
    void **list2 = (void **) data2;
    void **reg1 = (void **) list1[DATA];
    void **reg2 = (void **) list2[DATA];
    int *fecha1 = (int *) reg1[FECHA];
    int *fecha2 = (int *) reg2[FECHA];
    int *hora1 = (int *) reg1[HORA];
    int *hora2 = (int *) reg2[HORA];
    return *fecha1 * 10000 + *hora1 - *fecha2 * 10000 - *hora2;
}

void print_date(ofstream &file, int *date) {
    int yy, mm, dd;
    yy = *date / 10000;
    mm = (*date / 100) % 100;
    dd = *date % 100;
    file << yy << "/" << setfill('0') << setw(2) << mm << "/" << setw(2) << dd << setfill(' ');
}

void print_time(ofstream &file, int *time) {
    int hh, mm;
    hh = *time / 100;
    mm = *time % 100;
    file << setfill('0') << setw(2) << hh << ":" << setw(2) << mm << setfill(' ');
}

void imprimeReg(ofstream &file, void **node) {
    file << "FEACHA"  <<  setw(14) << "HORA" <<
        setw(10) << "CODIGO" <<
        setw(11) << "NOMBRE" <<
        setw(LINE_SIZE / 6-2) << "RAZA" <<
        setw(LINE_SIZE / 6+7) << "COLOR" << endl;
    print_filled_line(file, '=');
    while (node) {
        void **reg = (void **) node[DATA];
        int *fecha = (int *) reg[FECHA];
        int *hora = (int *) reg[HORA];
        int *codigo = (int *) reg[COD];
        char *nombre = (char *) reg[NOMBRE];
        char *raza = (char *) reg[RAZA];
        char *color = (char *) reg[COLOR];
        print_date(file, fecha);
        file << setw(6) << " ";
        print_time(file, hora);
        file << setw(4) << " " << left <<  setw(10) << *codigo <<
                setw(LINE_SIZE / 6) << nombre <<
                setw(LINE_SIZE / 6+6) << raza <<
                setw(LINE_SIZE / 6) << color << right <<
                endl;
        node = (void **) node[NEXT];
    }
}
