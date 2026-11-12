//
// Created by jolumarti on 2026-11-11.
//

#include "Par.hpp"

Par::Par() {
    value = nullptr;
}

Par::Par(int _llave): Par() {
    key = _llave;
}

Par::~Par() {
    delete value;
}
