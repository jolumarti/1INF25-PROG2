//
// Created by jolumarti on 2026-11-10.
//

#ifndef LAB8_2025_2_METRICABASICA_HPP
#define LAB8_2025_2_METRICABASICA_HPP
#include "Metrica.hpp"


class MetricaBasica : public Metrica {
private:
    double horas_transmitidas;
    int espectadores_promedio;

public:
    void copy(MetricaBasica &other);

    void leer(ifstream &file);

    void imprimir(ofstream &file) const;
    MetricaType getType() const override;
};


#endif //LAB8_2025_2_METRICABASICA_HPP
