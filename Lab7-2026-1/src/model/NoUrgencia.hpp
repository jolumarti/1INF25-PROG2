//
// Created by jolumarti on 2026-11-06.
//

#ifndef LAB7_2026_1_NOURGENCIA_HPP
#define LAB7_2026_1_NOURGENCIA_HPP

#include "Atencion.hpp"


class NoUrgencia: public Atencion {
private:
    string especialidad;
    bool es_consulta_programada;
public:
    void leer(ifstream &file, int hour) override;

    void imprimir(ofstream &file) override;

    int obtener_prioridad() override;
};


#endif //LAB7_2026_1_NOURGENCIA_HPP
