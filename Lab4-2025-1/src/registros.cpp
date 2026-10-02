//
// Created by jolumarti on 2026-09-24.
//

#include "registros.hpp"


//26522329,U5W-825,22/11/2019,101,SANCHEZ DEL CASTILLO FIORELLA ROSARIO
bool read_reg(ifstream &file, void *&data) {
    int licencia, yy,dd,mm;
    char *placa, *infraccion, *nombre, c;
    file >> licencia >> c;
    if (file.eof()) return false;
    placa = read_line(file, ',');
    file >> dd >> c >> mm >> c >> yy >> c;
    infraccion = read_line(file, ',');
    nombre = read_line(file, '\n');
    void **aux = new void*[5];
    aux[LICENCIA] = new int(licencia);
    aux[PLACA] = placa;
    aux[FECHA] = new int(yy*10000+mm*100+dd);
    aux[INFRACCION] = infraccion;
    aux[NOMBRE] = nombre;
    data = aux;
    return true;
}

bool cmp_reg(void *node) {
    void **aux = (void **) node;
    void** reg = (void**) aux[DATA];
    char* infraccion = (char*) reg[INFRACCION];
    return infraccion[0]=='1';
}

void print_date(ofstream &file, int *date) {
    int yy, mm, dd;
    yy = *date / 10000;
    mm = (*date / 100) % 100;
    dd = *date % 100;
    file << yy << "/" << setfill('0') << setw(2) << mm << "/" << setw(2) << dd << setfill(' ');
}

void print_reg(ofstream &file, void *node, bool first) {
    void **aux = (void **) node;
    void** reg = (void**) aux[DATA];
    char* infraccion = (char*) reg[INFRACCION];
    char* nombre = (char*) reg[NOMBRE];
    int* licencia = (int*) reg[LICENCIA];
    int* fecha = (int*) reg[FECHA];

    if (first) {
        file  << "FECHA"<<setw(LINE_SIZE/5-1) << "LICENCIA"<<setw(LINE_SIZE/7-2) << "NOMBRE"<<
            setw(LINE_SIZE/2+8) << "FALTA"<< endl;
        print_filled_line(file, '=');
    }
    print_date(file, fecha);
    file << setw(4) << ' ' <<  left <<
        setw(LINE_SIZE/7) << *licencia<<
        setw(LINE_SIZE/2-5) << nombre<< right <<
        setw(LINE_SIZE/5) << infraccion<< endl;
}


