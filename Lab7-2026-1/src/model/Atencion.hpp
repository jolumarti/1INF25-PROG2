//
// Created by jolumarti on 2026-11-05.
//

#ifndef LAB7_2026_1_ATENCION_HPP
#define LAB7_2026_1_ATENCION_HPP
#include "../Helpers.hpp"

class Atencion {
private:
    int codigo;
    string paciente;
    string descripcion;
    int hora;
public:
    Atencion();
    Atencion(Atencion &other);
    virtual ~Atencion();
    virtual void copy(Atencion &other);
    virtual void leer(ifstream &file, int hour);
    virtual void imprimir(ofstream &file);
    virtual int obtener_prioridad()=0;
};


#endif //LAB7_2026_1_ATENCION_HPP
