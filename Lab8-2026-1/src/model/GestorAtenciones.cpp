//
// Created by erasm on 11/06/2026.
//

#include "GestorAtenciones.hpp"

void GestorAtenciones::set_hh(const string &filename) {
    hh = stoi(filename.substr(filename.size() - 6, 2));
}

GestorAtenciones::GestorAtenciones() {
    cantidad_atenciones = 0;
    atenciones = nullptr;
    capacidad = 0;
}

GestorAtenciones::~GestorAtenciones() {
    delete [] atenciones;
}

void GestorAtenciones::cargar_atenciones(const char *nombreArchivo, int hh) {
    ifstream input;
    Utils::apertura_archivo_lectura(input, nombreArchivo);
    while (true) {
        int tipo;
        input >> tipo;

        if (input.eof()) break;

        input.ignore(); // coma

        Atencion *atencion = reservar_memoria_atencion(tipo);

        atencion->leer(input, hh);

        agregar_atencion(atencion);
    }

    input.close();
}

void GestorAtenciones::cargar_atenciones_prioridad(const char *nombreArchivo) {
    ifstream input;
    Utils::apertura_archivo_lectura(input, nombreArchivo);
    set_hh(nombreArchivo);
    while (true) {
        int tipo;
        input >> tipo;
        if (input.eof()) break;
        input.ignore(); // coma
        Atencion *atencion = reservar_memoria_atencion(tipo);
        atencion->leer(input, hh);
        atenciones_prioridad.insert(atencion->conseguir_llave(), atencion);
    }

    input.close();
}


void GestorAtenciones::agregar_atencion(Atencion *atencion) {
    if (cantidad_atenciones == capacidad)
        reservar_memoria();
    atenciones[cantidad_atenciones] = atencion;
    cantidad_atenciones++;
}

void GestorAtenciones::procesar_dia(const char *fecha) {
    char path_dia[200];

    Utils::construir_path_dia(path_dia, fecha);

    for (int hh = 0; hh < 1; hh++) {
        char archivo[300];
        Utils::construir_nombre_archivo(archivo, path_dia, hh);

        cout << archivo << endl;

        cargar_atenciones(archivo, hh);
    }
}

void GestorAtenciones::print_headers(ofstream &output, int priority) const {
    if (priority == 1) output << "EMERGENCIAS: " << "\n";
    else if (priority == 2) output << "URGENCIAS: " << "\n";
    else if (priority == 3) output << "NO URGENCIAS: " << "\n";
    output <<
            setw(10) << "PRIORIDAD" <<
            setw(10) << "CODIGO" <<
            setw(20) << "PACIENTE" <<
            setw(60) << "DESCRIPCION";
    if (priority == 1) {
        output << setw(11) << "RCP?";
        output << setw(12) << "NO PULSO";
        output << setw(20) << "OBSERVACION";
    } else if (priority == 2) {
        output << setw(21) << "ZONA LESION";
        output << setw(10) << "RX?";
        output << setw(25) << "OBSERVACION";
    } else if (priority == 3) {
        output << setw(20) << "ESPECIALIDAD";
        output << setw(24) << "PROGRAMADA?";
    }
    output << "\n";
}


void GestorAtenciones::imprime_atenciones_prioridad(const char *nombreArchivo) const {
    ofstream output;
    Utils::apertura_archivo_escritura(output, nombreArchivo);

    Utils::print_filled_line(output, '=');
    Utils::print_centered_title(output, "REPORTE DE ATENCIONES PRIORIZADAS");
    Utils::print_centered_title(output, "FECHA: 23-01-1990   HORA: " + to_string(hh));
    Utils::print_filled_line(output, '=');
    for (int i=1; i<=3; i++) {
        if (i > 1)         Utils::print_filled_line(output, '=');
        print_headers(output, i);
        atenciones_prioridad.print(output, i);
    }
    output.close();
}

void GestorAtenciones::generar_reporte_diario(const char *nombre_reporte) {
    ofstream output;
    Utils::apertura_archivo_escritura(output, nombre_reporte);
    cout << cantidad_atenciones << endl;
    for (int h = 0; h < 1; h++) {
        output << "============================\n";
        output << "HORA: " << h << "\n";
        output << "============================\n";

        output << "============================\n";
        output << "EMERGENCIAS: " << "\n";
        output << "============================\n";
        for (int i = 0; i < cantidad_atenciones; i++) {
            if (atenciones[i]->get_hora_ingreso() == h and atenciones[i]->obtenerPrioridad() == 1) {
                atenciones[i]->imprimir(output); // POLIMORFISMO
            }
        }
        output << "============================\n";
        output << "URGENCIAS: " << "\n";
        output << "============================\n";
        for (int i = 0; i < cantidad_atenciones; i++) {
            if (atenciones[i]->get_hora_ingreso() == h and atenciones[i]->obtenerPrioridad() == 2) {
                atenciones[i]->imprimir(output); // POLIMORFISMO
            }
        }
        output << "============================\n";
        output << "NO URGENCIAS: " << "\n";
        output << "============================\n";
        for (int i = 0; i < cantidad_atenciones; i++) {
            if (atenciones[i]->get_hora_ingreso() == h and atenciones[i]->obtenerPrioridad() == 3) {
                atenciones[i]->imprimir(output); // POLIMORFISMO
            }
        }

        output << "\n";
    }

    output.close();
}

Atencion *GestorAtenciones::reservar_memoria_atencion(char tipo) {
    switch (tipo) {
        case 1:
            return new Emergencia();

        case 2:
            return new Urgencia();

        case 3:
            return new NoUrgencia();

        default:
            return nullptr;
    }
}

void GestorAtenciones::reservar_memoria() {
    capacidad += 5;
    if (atenciones == nullptr) {
        atenciones = new Atencion *[capacidad]{};
    } else {
        Atencion **aux = new Atencion *[capacidad]{};
        for (int i = 0; i < cantidad_atenciones; i++) {
            aux[i] = atenciones[i];
        }
        delete[] atenciones;
        atenciones = aux;
    }
}
