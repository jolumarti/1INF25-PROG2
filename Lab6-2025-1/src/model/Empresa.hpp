//
// Created by jolumarti on 2026-10-29.
//

#ifndef LAB6_2025_2_EMPRESA_HPP
#define LAB6_2025_2_EMPRESA_HPP
#include "Multa.hpp"


class Empresa {
private:
    int dni;
    char *nombre;
    char *placa[10];
    int numPlacas;
    Multa multas[100];
    int numMultas;

    void set_nombre(const char* nombre);
    void get_nombre(char* nombre) const;
public:
    Empresa();
    ~Empresa();
    void setPlacaI(const char* placa, int i);
    void getPlacaI(char* placa, int i) const;
    bool find_placa(const char* placa) const;
    bool read(ifstream &i);
    void print(ofstream &o) const;
    void operator+=(const Multa &multa);
};
bool operator>>(ifstream &i, Empresa &empresa);
void operator<<(ofstream &o, const Empresa &empresa);


#endif //LAB6_2025_2_EMPRESA_HPP
