//
// Created by jolumarti on 2026-11-10.
//

#include "MetricaEngagement.hpp"

void MetricaEngagement::copy(MetricaEngagement &other) {
    Metrica::copy(other);
    mensajes_chat = other.mensajes_chat;
    usuarios_unicos_chat = other.usuarios_unicos_chat;
    clips_generados = other.clips_generados;
}

void MetricaEngagement::leer(ifstream &file) {
    //ENGAGEMENT,573984,161,Q&A largo,2025-08-07,2025-12-31,1586,571,27
    Metrica::leer(file);
    char c;
    file >> mensajes_chat >> c >> usuarios_unicos_chat >> c >> clips_generados;
    file.get();
}

void MetricaEngagement::imprimir(ofstream &file) const {
    Metrica::imprimir(file);
}
