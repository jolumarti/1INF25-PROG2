//
// Created by jolumarti on 2026-11-06.
//

#ifndef LAB7_2026_1_URGENCIA_HPP
#define LAB7_2026_1_URGENCIA_HPP
#include "Atencion.hpp"


class Urgencia: public Atencion {
private:
    string zona_lesion;
    bool necesita_rx;
public:
    void leer(ifstream &file, int hour) override;

    void imprimir(ofstream &file) override;

    int obtener_prioridad() override;
};


#endif //LAB7_2026_1_URGENCIA_HPP
