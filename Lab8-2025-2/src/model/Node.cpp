//
// Created by jolumarti on 2026-11-10.
//

#include "Node.hpp"

Node::Node() {
    metrica = nullptr;
    next = nullptr;
    prev = nullptr;
}

Node::Node(Metrica *metrica): Node() {
    this->metrica = metrica;
}

Node::~Node() {
    delete metrica;
}
