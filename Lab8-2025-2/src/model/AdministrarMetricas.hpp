//
// Created by jolumarti on 2026-11-11.
//

#ifndef LAB8_2025_2_ADMINISTRARMETRICAS_HPP
#define LAB8_2025_2_ADMINISTRARMETRICAS_HPP
#include "List.hpp"


class AdministrarMetricas {
    List lista;
    Metrica* createMetrica(const string& type);
public:
    AdministrarMetricas();
    void cargarArchivo(const string &filename);
    void generarReporte(const string &filename) const;
    void eliminarNodos();
    void eliminarLista();
};


#endif //LAB8_2025_2_ADMINISTRARMETRICAS_HPP
