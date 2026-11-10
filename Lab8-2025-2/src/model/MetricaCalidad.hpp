//
// Created by jolumarti on 2026-11-10.
//

#ifndef LAB8_2025_2_METRICACALIDAD_HPP
#define LAB8_2025_2_METRICACALIDAD_HPP
#include "Metrica.hpp"


class MetricaCalidad: public Metrica {
private:
    int bitrate_promedio_kbps;
    double porcentaje_frames_perdidos;
    int fps_promedio;
public:
    void copy(MetricaCalidad &other);

    void leer(ifstream &file);

    void imprimir(ofstream &file) const;
};


#endif //LAB8_2025_2_METRICACALIDAD_HPP
