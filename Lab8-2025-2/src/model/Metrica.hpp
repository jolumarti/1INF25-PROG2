//
// Created by jolumarti on 2026-11-10.
//

#ifndef LAB8_2025_2_METRICA_HPP
#define LAB8_2025_2_METRICA_HPP
#include "../Helpers.hpp"
enum MetricaType {BASICA, CALIDAD, ENGAGEMENT};
class Metrica {
private:
    int id;
    string descripcion;
    int fecha_calculo;
    int fecha_expiracion;
    bool estado;

public:
    virtual ~Metrica();
    virtual void copy(Metrica &other);
    virtual void leer(ifstream &file);
    virtual void imprimir(ofstream &file) const;
    virtual MetricaType getType() const = 0;
    bool compare(Metrica *other);
    bool getEstado() const;
};


#endif //LAB8_2025_2_METRICA_HPP
