//
// Created by erasm on 11/06/2026.
//

#ifndef L7261_GESTOREMERGENCIAS_HPP
#define L7261_GESTOREMERGENCIAS_HPP
#include "Emergencia.hpp"
#include "Urgencia.hpp"
#include "NoUrgencia.hpp"
#include "List.hpp"

class  GestorAtenciones {
private:
    Atencion **atenciones;

    int hh;

    int cantidad_atenciones;

    int capacidad;

    List atenciones_prioridad;

    void set_hh(const string &filename);

public:
    GestorAtenciones();

    ~GestorAtenciones();

    void cargar_atenciones(const char *nombreArchivo, int);

    void cargar_atenciones_prioridad(const char *nombreArchivo);
    void imprime_atenciones_prioridad(const char *nombreArchivo) const;

    void agregar_atencion(Atencion *);

    void procesar_dia(const char *fecha);

    void print_headers(ofstream &output, int priority) const;

    void generar_reporte_diario(const char *nombre_reporte);

    Atencion *reservar_memoria_atencion(char);

    void reservar_memoria();

};


#endif //L7261_GESTOREMERGENCIAS_HPP
