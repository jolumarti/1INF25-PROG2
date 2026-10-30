//
// Created by jolumarti on 10/27/26.
//

#ifndef LAB6_2026_1_MASCOTA_HPP
#define LAB6_2026_1_MASCOTA_HPP
#include "../Helpers.hpp"

class Mascota {
private:
    int codigo;
    char tipo;

    char *nombre;
    char *raza;

public:
    Mascota();
    ~Mascota();


    int get_codigo() const;

    void set_codigo(const int codigo);

    char get_tipo() const;

    void set_tipo(const char tipo);


    void get_nombre(char *nombre) const;

    void set_nombre(const char *nombre);


    void get_raza(char *raza) const;

    void set_raza(const char *raza);

    void read(istream &i);
    void print(ostream &o) const;
    void copy(const Mascota &other);
};


#endif //LAB6_2026_1_MASCOTA_HPP
