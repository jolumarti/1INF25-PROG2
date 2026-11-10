//
// Created by jolumarti on 2026-11-10.
//

#ifndef LAB8_2025_2_METRICA_HPP
#define LAB8_2025_2_METRICA_HPP
#include "../Helpers.hpp"

class Metrica {
private:
    int id;
    string descripcion;
    int fecha_calculo;
    int fecha_expiracion;
    bool estado;

public:
    virtual void copy(Metrica &other);

    virtual void leer(ifstream &file);

    virtual void imprimir(ofstream &file) const;
};


#endif //LAB8_2025_2_METRICA_HPP
