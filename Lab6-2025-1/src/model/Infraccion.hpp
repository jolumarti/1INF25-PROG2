//
// Created by jolumarti on 2026-10-29.
//

#ifndef LAB6_2025_2_INFRACCION_HPP
#define LAB6_2025_2_INFRACCION_HPP
#include "../Helpers.hpp"


class Infraccion {
private:
    int codigo;
    double multa;
    char *descripcion;
    char *gravedad;

    void set_descripcion(const char *descripcion);

    void get_descripcion(char *descripcion) const;

    void set_gravedad(const char *gravedad);

    void get_gravedad(char *gravedad) const;

    void copy(const Infraccion &other);

public:
    Infraccion();

    Infraccion(const Infraccion &other);

    ~Infraccion();

    int get_codigo() const;

    double get_multa() const;

    bool read(ifstream &i);

    void print(ofstream &o) const;

    void operator=(const Infraccion &other);
};

bool operator>>(ifstream &i, Infraccion &infraccion);

void operator<<(ofstream &o, const Infraccion &infraccion);

#endif //LAB6_2025_2_INFRACCION_HPP
