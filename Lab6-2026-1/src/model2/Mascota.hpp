//
// Created by jolumarti on 2026-10-07.
//

#ifndef LAB5_2026_1_MASCOTA_HPP
#define LAB5_2026_1_MASCOTA_HPP
#include "VacunaAplicada.hpp"

class Mascota {

private:
    int dni;
    char *nombre;
    char *especie;
    int edad;
    double peso;
    char *colegiatura;
    VacunaAplicada listaVacunas[20];
    int numVacunas;

public:
    Mascota();
    ~Mascota();
    int get_dni() const;

    void set_dni(int dni);

    void get_nombre(char *nombre) const;

    void set_nombre(const char *nombre);

    void get_especie(char *especie) const;

    void set_especie(const char *especie);

    int get_edad() const;

    void set_edad(int edad);

    double get_peso() const;

    void set_peso(double peso);

    void get_colegiatura(char *colegiatura) const;

    void set_colegiatura(const char *colegiatura);

    int get_num_vacunas() const;

    void set_num_vacunas(int num_vacunas);

    bool read(istream &file);
    void print(ostream &file);
    void print_vacunas(ostream &file);

    void operator=(const Mascota &other);
    void operator+=(const VacunaAplicada &vacuna);
    bool operator~();


};
bool operator>>(istream &file, Mascota &mascota);
void operator<<(ostream &file, Mascota &mascota);

#endif //LAB5_2026_1_MASCOTA_HPP
