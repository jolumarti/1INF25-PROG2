//
// Created by jolumarti on 10/27/26.
//

#ifndef LAB6_2026_1_CITA_HPP
#define LAB6_2026_1_CITA_HPP

#include "../Helpers.hpp"
#include "Mascota.hpp"

class Cita {
private:
    int fecha;
    int hora;
    Mascota Amascota;

public:
    Cita();
    virtual ~Cita();
    virtual void read(istream& i);
    virtual void print(ostream& o) const;

    int get_fecha() const;

    void set_fecha(int fecha);

    int get_hora() const;

    void set_hora(int hora);
    void copy(const Cita &other);


};


#endif //LAB6_2026_1_CITA_HPP
