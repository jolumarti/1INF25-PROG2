//
// Created by jolumarti on 10/27/26.
//

#ifndef LAB6_2026_1_OPERACION_HPP
#define LAB6_2026_1_OPERACION_HPP
#include "Cita.hpp"


class Operacion : public Cita {
private:
    bool anestesiageneral;
    int nummedicos;
    double total;

public:
    bool is_anestesiageneral() const;

    void set_anestesiageneral(bool anestesiageneral);

    int get_nummedicos() const;

    void set_nummedicos(int nummedicos);

    double get_total() const;

    void set_total(double total);
    Operacion();
    ~Operacion();
    void read(istream& i);
    void print(ostream& o) const override;
};


#endif //LAB6_2026_1_OPERACION_HPP
