//
// Created by jolumarti on 2026-11-10.
//

#ifndef LAB8_2025_2_METRICAENGAGEMENT_HPP
#define LAB8_2025_2_METRICAENGAGEMENT_HPP
#include "Metrica.hpp"


class MetricaEngagement: public Metrica {
private:
    int mensajes_chat;
    int usuarios_unicos_chat;
    int clips_generados;
public:
    void copy(MetricaEngagement &other);

    void leer(ifstream &file);

    void imprimir(ofstream &file) const;
    MetricaType getType() const override;

};


#endif //LAB8_2025_2_METRICAENGAGEMENT_HPP
