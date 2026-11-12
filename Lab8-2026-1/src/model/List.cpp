//
// Created by jolumarti on 2026-11-11.
//

#include "List.hpp"

List::List() {
    head = nullptr;
}

List::~List() {
    destroy();
}

void List::insert(int llave, Atencion *valor) {
    Node *node = new Node(llave, valor);
    insertRecursive(head, nullptr, node);
}

void List::insertRecursive(Node *&cur,
                           Node *prev,
                           Node *node) {
    if (!cur || node->compare(cur)) {
        node->next = cur;
        node->prev = prev;

        if (cur) cur->prev = node;

        cur = node;
        return;
    }

    insertRecursive(cur->next, cur, node);
}

void List::print(ofstream &file, int priority) const {
    printRecursive(head, file, priority);
}

void List::printRecursive(const Node *cur,
                          ofstream &file,
                          int priority) const {
    if (!cur) return;
    if (cur->cmp_priority(priority))cur->print(file);
    printRecursive(cur->next, file, priority);
}

void List::destroy() {
    cout << "Eliminando Lista" << endl;
    Node *cur = head;
    while (cur != nullptr) {
        Node *next = cur->next;
        delete cur;
        cur = next;
    }
    head = nullptr;
}
