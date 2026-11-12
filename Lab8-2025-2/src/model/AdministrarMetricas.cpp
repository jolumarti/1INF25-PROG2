//
// Created by jolumarti on 2026-11-11.
//

#include "AdministrarMetricas.hpp"

#include "MetricaBasica.hpp"
#include "MetricaCalidad.hpp"
#include "MetricaEngagement.hpp"

Metrica * AdministrarMetricas::createMetrica(const string &type) {
    if (type == "BASIC") {
       return new MetricaBasica();
    } else if (type == "ENGAGEMENT") {
        return new MetricaEngagement();
    } else if (type == "QUALITY")
        return new MetricaCalidad();
    return nullptr;
}

AdministrarMetricas::AdministrarMetricas() {
    lista.crear();
}

void AdministrarMetricas::cargarArchivo(const string &filename) {
    ifstream file;
    Helpers::open_if(file, filename);
    while (true) {
        string metricType;
        getline(file, metricType, ',');
        if (file.eof()) break;
        Metrica *metrica = createMetrica(metricType);
        if (metrica) {
            metrica->leer(file);
            lista.insertar(metrica);
        }
    }
}

void AdministrarMetricas::generarReporte(const string &filename) const {
    ofstream file;
    Helpers::open_of(file, filename);
    Helpers::print_filled_line(file,  '=');
    Helpers::print_centered_title(file,"REPORTE DE METRICAS");
    Helpers::print_filled_line(file,  '=');
    lista.print(file);
}

void AdministrarMetricas::eliminarNodos() {
    lista.eliminarNodos();
}

void AdministrarMetricas::eliminarLista() {
    lista.reset();
}
