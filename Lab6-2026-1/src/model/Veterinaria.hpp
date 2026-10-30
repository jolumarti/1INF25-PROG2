//
// Created by jolumarti on 2026-10-28.
//

#ifndef LAB6_2026_1_VETERINARIA_HPP
#define LAB6_2026_1_VETERINARIA_HPP
#include "Control.hpp"
#include "Operacion.hpp"
#include "Vacuna.hpp"


class Veterinaria {
private:
    Control *arrControl;
    Vacuna arrVacuna[50];
    Operacion arrOperacion[50];
    int numdatControl;
    int capaControl;
    void resize_control();
    void print_headers(ostream &o, const char *title) const;
    void print_control(ostream &o) const;
    void print_vacuna(ostream &o) const;
    void print_operacion(ostream &o) const;

public:
    Veterinaria();
    Veterinaria(const Veterinaria &) = delete;
    Veterinaria &operator=(const Veterinaria &) = delete;
    ~Veterinaria();
    void cargacitas();
    void muestracitas() const;

};


#endif //LAB6_2026_1_VETERINARIA_HPP
