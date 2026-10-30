//
// Created by jolumarti on 10/27/26.
//

#ifndef LAB6_2026_1_CONTROL_HPP
#define LAB6_2026_1_CONTROL_HPP
#include "Cita.hpp"


class Control: public Cita {
private:
    double costo;
    int codmed;

public:
    Control();
    void read(istream &i) override;
    void print(ostream &o) const override;

    double get_costo() const;

    void set_costo(const double costo);

    int get_codmed() const;

    void set_codmed(const int codmed);
    void copy(const Control &other);
};


#endif //LAB6_2026_1_CONTROL_HPP
