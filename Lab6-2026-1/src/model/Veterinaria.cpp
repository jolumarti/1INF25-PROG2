//
// Created by jolumarti on 2026-10-28.
//

#include "Veterinaria.hpp"

void Veterinaria::resize_control() {
    Control *aux = new Control[capaControl]{};
    for (int i=0; i<numdatControl; i++) {
        aux[i].copy(arrControl[i]);
    }
    delete[] arrControl;
    arrControl = aux;
}

void Veterinaria::print_headers(ostream &o, const char *title) const {
    o << title << endl << setw(8) << "Fecha" << setw(8) << "Hora" <<
        setw(7) << "Raza" << setw(22) << "Nombre";
}

void Veterinaria::print_control(ostream &o) const {
    print_headers(o, "Citas de Control:");
    o << setw(22) << "Cod Medico" << setw(8) << "Monto" << endl;
    Helpers::print_filled_line(o, '-');
    double total{};
    for (int i=0; i<numdatControl; i++) {
        arrControl[i].print(o);
        total += arrControl[i].get_costo();
    }
    o << "Monto por control: " << total << endl;
}

void Veterinaria::print_vacuna(ostream &o) const {
    print_headers(o, "Citas de Vacunas:");
    o << setw(22) << "Dosis" << setw(21) << "Meses proxima dosis" << endl;
    Helpers::print_filled_line(o, '-');
    int total{}, i {};
    while (arrVacuna[i].get_fecha()) {
        arrVacuna[i].print(o);
        total ++;
        i++;
    }
    o << "Numero de Vacunas: " << total << endl;
}

void Veterinaria::print_operacion(ostream &o) const {
    print_headers(o, "Citas de Operaciones:");
    o << setw(22) << "Anestesia" << setw(21) << "Numero de medicos" << endl;
    Helpers::print_filled_line(o, '-');
    double total{};
    int i {};
    while (arrOperacion[i].get_fecha()) {
        arrOperacion[i].print(o);
        total += arrOperacion[i].get_total();
        i++;
    }
    o << "Total de operaciones: " << total << endl;
}


Veterinaria::Veterinaria() {
    arrControl = nullptr;
    numdatControl = 0;
    capaControl = 0;
}

Veterinaria::~Veterinaria() {
    delete[] arrControl;
}

void Veterinaria::cargacitas() {
    ifstream file;
    Helpers::open_ifstream(file, "../data/Atenciones.csv");
    char c;
    int numVacuna = 0, numOperacion = 0;
    while (true) {
        file >> c;
        if (file.eof()) break;
        Cita *cita{};
        if (c == 'C') {
            if (numdatControl == capaControl) {
                capaControl += INCREMENT;
                resize_control();
            }
            cita = &arrControl[numdatControl++];
        } else if (c == 'V') cita = &arrVacuna[numVacuna++];
        else if (c == 'O') cita = &arrOperacion[numOperacion++];
        else break; // Invalid character
        cita->read(file);
    }
    capaControl = numdatControl;
    resize_control();
}

void Veterinaria::muestracitas() const {
    ofstream file;
    Helpers::open_ofstream(file, "../dist/reporte.txt");
    print_control(file);
    file << endl;
    print_vacuna(file);
    file << endl;
    print_operacion(file);
}
