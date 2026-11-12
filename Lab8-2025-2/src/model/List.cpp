//
// Created by jolumarti on 2026-11-10.
//

#include "List.hpp"

void List::crear() {
    lista = nullptr;
}

void List::insertar(Metrica *metrica) {
    Node *node = new Node(metrica);

    if (lista == nullptr || lista->metrica->compare(metrica)) {
        node->next = lista;
        if (lista) lista->prev = node;
        lista = node;
        return;
    }

    Node *cur = lista;
    while (cur->next && !cur->next->metrica->compare(metrica)) {
        cur = cur->next;
    }

    node->next = cur->next;
    node->prev = cur;
    if (cur->next) cur->next->prev = node;
    cur->next = node;
}

void List::eliminarNodos() {
    Node *cur = lista;
    while (cur) {
        Node *next = cur->next;
        if (!cur->metrica->getEstado()) {
            Node *prev = cur->prev;
            if (prev) prev->next = next;
            else lista = next;

            if (next) next->prev = prev;

            delete cur;
        }
        cur = next;
    }
}

void List::reset() {
    Node *cur = lista;
    while (cur != nullptr) {
        Node *next = cur->next;
        delete cur;
        cur = next;
    }
    lista = nullptr;
}

void List::print(ofstream &file) const {
    Node *cur = lista;
    int num = -1, activas = 0, experidas = 0;
    while (cur) {
        Metrica *metrica = cur->metrica;
        if (num != metrica->getType()) {
            if (num != -1) Helpers::print_filled_line(file,  '-');
            print_headers(file, metrica->getType());
            num = metrica->getType();
        }
        metrica->imprimir(file);
        if (metrica->getEstado()) activas++;
        else experidas++;
        cur = cur->next;
    }
    Helpers::print_filled_line(file,  '-');
    file << "Metricas Activas: " << activas << endl;
    file << "Metricas Expiradas: " << experidas << endl;
    file << "Fecha de Reporte: 2025-11-14" << endl;
    Helpers::print_filled_line(file,  '=');
}

void List::print_headers(ofstream &file, MetricaType type) const {
    if (type == BASICA) {
        file << "Metricas Basic" << endl;
    } else if (type == ENGAGEMENT) {
        file << "Metricas Engage" << endl;
    } else if (type == CALIDAD)
        file << "Metricas Quality" << endl;

    file << "Codigo" <<
            setw(14) << "Descripcion" <<
            setw(23) << "Fecha Cal" <<
            setw(11) << "Expira" <<
            setw(13) << "Estado";
    if (type == BASICA) {
        file << setw(11) << "Horas" <<
                setw(14) << "Viewers" << endl;
    } else if (type == ENGAGEMENT) {
        file << setw(12) << "Msgs" <<
                setw(15) << "Chatters" <<
                setw(10) << "Clips" << endl;
    } else if (type == CALIDAD)
        file << setw(14) << "Bitrate" <<
                setw(10) << "Drop%" <<
                setw(12) << "FPS" << endl;
    Helpers::print_filled_line(file,  '-');
}
