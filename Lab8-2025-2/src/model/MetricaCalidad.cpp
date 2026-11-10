//
// Created by jolumarti on 2026-11-10.
//

#include "MetricaCalidad.hpp"

void MetricaCalidad::copy(MetricaCalidad &other) {
    Metrica::copy(other);
    bitrate_promedio_kbps = other.bitrate_promedio_kbps;
    porcentaje_frames_perdidos = other.porcentaje_frames_perdidos;
    fps_promedio = other.fps_promedio;
}

void MetricaCalidad::leer(ifstream &file) {
    //QUALITY,314875,3033,Bitrate consistente,2025-07-27,2025-12-31,7586,0.063,48
    Metrica::leer(file);
    char c;
    file >> bitrate_promedio_kbps >> c >> porcentaje_frames_perdidos >> c >> fps_promedio;
    file.get();
}

void MetricaCalidad::imprimir(ofstream &file) const {
    Metrica::imprimir(file);
}
