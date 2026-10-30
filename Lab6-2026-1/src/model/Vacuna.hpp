//
// Created by jolumarti on 2026-10-28.
//

#ifndef LAB6_2026_1_VACUNA_HPP
#define LAB6_2026_1_VACUNA_HPP
#include "Cita.hpp"


class Vacuna : public Cita {
private:
    int dosis;
    int meses;

public:
    Vacuna();
    ~Vacuna();
    void read(istream &i) override;
    void print(ostream &o) const override;

    int get_dosis() const;

    void set_dosis(const int dosis);

    int get_meses() const;

    void set_meses(const int meses);

};


#endif //LAB6_2026_1_VACUNA_HPP
