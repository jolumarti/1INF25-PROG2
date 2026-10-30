//
// Created by jolumarti on 2026-10-29.
//

#ifndef LAB6_2025_2_MULTA_HPP
#define LAB6_2025_2_MULTA_HPP

#include "../Helpers.hpp"

class Multa {
private:
    char *placa;
    int fechaDeInfraccion;
    int fechaDePago;
    int codigoInfraccion;
    double multa;

    void set_placa(const char *placa);
    void copy(const Multa &other);

public:
    Multa();

    Multa(const Multa &other);

    ~Multa();

    bool read(ifstream &i);
    void print(ofstream &o) const;

    void set_multa(double multa);
    void get_placa(char *placa) const;
    int get_codigoInfraccion() const;
    void operator=(const Multa &other);
};

bool operator>>(ifstream &i, Multa &multa);
void operator<<(ofstream &o, const Multa &multa);

#endif //LAB6_2025_2_MULTA_HPP
