//
// Created by jolumarti on 2026-10-07.
//

#ifndef LAB5_2026_1_VACUNAAPLICADA_HPP
#define LAB5_2026_1_VACUNAAPLICADA_HPP
#include "../Helpers.hpp"

class VacunaAplicada {
private:
    char *nombre;
    int fecha;
    double dosis;
    char *colegiatura;
public:
    VacunaAplicada();

    ~VacunaAplicada();

    void get_nombre(char *nombre) const;

    void set_nombre(const char *nombre);

    int get_fecha() const;

    void set_fecha(const int fecha);

    double get_dosis() const;

    void set_dosis(const double dosis);

    void get_colegiatura(char *colegiatura) const;

    void set_colegiatura(const char *colegiatura);

    bool read(istream &file);

    void operator=(const VacunaAplicada &other);
    bool operator==(const VacunaAplicada &other);
    void print(ostream &file);
};

bool operator>>(istream &file, VacunaAplicada &vacuna_aplicada);
void operator<<(ostream &file,  VacunaAplicada &vacuna_aplicada);

#endif //LAB5_2026_1_VACUNAAPLICADA_HPP
