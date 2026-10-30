//
// Created by jolumarti on 2026-10-29.
//

#ifndef LAB6_2025_2_MINISTERIODETRANSPORTE_HPP
#define LAB6_2025_2_MINISTERIODETRANSPORTE_HPP
#include "Empresa.hpp"
#include "Infraccion.hpp"


class MinisterioDeTransporte {
private:
    Infraccion *infracciones;
    int numInf;
    Empresa empresas[50];
    int numEmp;

    void resize(int cap);

    int find_infraccion(int codigo) const;

    int find_empresa(const char *placa) const;

public:
    MinisterioDeTransporte();

    ~MinisterioDeTransporte();

    void operator<(const char *filename);

    void operator<=(const char *filename);

    void operator<<=(const char *filename);

    void operator>>(const char *filename) const;

    void print_infracciones(ofstream &o) const;

    void print_empresas(ofstream &o) const;
};


#endif //LAB6_2025_2_MINISTERIODETRANSPORTE_HPP
