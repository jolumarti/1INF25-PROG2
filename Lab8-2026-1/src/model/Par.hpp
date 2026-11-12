//
// Created by jolumarti on 2026-11-11.
//

#ifndef LAB8_2026_1_PAR_HPP
#define LAB8_2026_1_PAR_HPP
#include "Atencion.hpp"


class Par {
private:
    int key;
    Atencion *value;

public:
    Par();
    Par(int _llave);
    ~Par();

    friend class Node;
};


#endif //LAB8_2026_1_PAR_HPP
