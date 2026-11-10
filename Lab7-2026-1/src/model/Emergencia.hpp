//
// Created by jolumarti on 2026-11-06.
//

#ifndef LAB7_2026_1_EMERGENCIA_HPP
#define LAB7_2026_1_EMERGENCIA_HPP
#include "Atencion.hpp"


class Emergencia : public Atencion {
private:
    bool requiere_rcp;
    int minutos_sin_pulso;

public:
    void leer(ifstream &file, int hour) override;

    void imprimir(ofstream &file) override;

    int obtener_prioridad() override;
};


#endif //LAB7_2026_1_EMERGENCIA_HPP
