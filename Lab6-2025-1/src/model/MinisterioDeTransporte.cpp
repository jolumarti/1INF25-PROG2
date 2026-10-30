//
// Created by jolumarti on 2026-10-29.
//

#include "MinisterioDeTransporte.hpp"

void MinisterioDeTransporte::resize(int cap) {
    Infraccion *aux = new Infraccion[cap]{};
    for (int i = 0; i < numInf; i++) {
        aux[i] = infracciones[i];
    }
    delete[] infracciones;
    infracciones = aux;
}

int MinisterioDeTransporte::find_infraccion(int codigo) const {
    for (int i = 0; i < numInf; i++) {
        if (infracciones[i].get_codigo() == codigo) {
            return i;
        }
    }
    return NOT_FOUND;
}

int MinisterioDeTransporte::find_empresa(const char *placa) const {
    for (int i = 0; i < numEmp; i++) {
        if (empresas[i].find_placa(placa)) {
            return i;
        }
    }
    return NOT_FOUND;
}


MinisterioDeTransporte::MinisterioDeTransporte() {
    numInf = 0;
    infracciones = nullptr;
    numEmp = 0;
}

MinisterioDeTransporte::~MinisterioDeTransporte() {
    delete[] infracciones;
}


void MinisterioDeTransporte::operator<(const char *filename) {
    ifstream file;
    Helpers::open_ifstream(file, filename);
    int cap = 0;
    while (true) {
        Infraccion infraccion;
        if (!(file >> infraccion)) break;
        if (numInf == cap) {
            cap += INCREMENT;
            resize(cap);
        }
        infracciones[numInf++] = infraccion;
    }
    resize(numInf);
}

void MinisterioDeTransporte::operator<=(const char *filename) {
    ifstream file;
    Helpers::open_ifstream(file, filename);
    while (true) {
        Empresa &empresa = empresas[numEmp];
        if (!(file >> empresa)) break;
        numEmp++;
    }
}

void MinisterioDeTransporte::operator<<=(const char *filename) {
    ifstream file;
    Helpers::open_ifstream(file, filename);
    while (true) {
        Multa multa;
        if (!(file >> multa)) break;
        char placa[M_BUFFER];
        int codigo = multa.get_codigoInfraccion();
        multa.get_placa(placa);
        int id_empresa = find_empresa(placa);
        int id_infraccion = find_infraccion(codigo);
        if (id_empresa != NOT_FOUND && id_infraccion != NOT_FOUND) {
            Empresa &empresa = empresas[id_empresa];
            Infraccion &infraccion = infracciones[id_infraccion];
            multa.set_multa(infraccion.get_multa());
            empresa += multa;
        }
    }
}

void MinisterioDeTransporte::operator>>(const char *filename) const {
    ofstream o;
    Helpers::open_ofstream(o, filename);
    Helpers::print_centered_title(o, "MINISTERIO DE TRANSPORTE");
    Helpers::print_filled_line(o, '=');
    print_infracciones(o);
    Helpers::print_filled_line(o, '=');
    print_empresas(o);
}


void MinisterioDeTransporte::print_infracciones(ofstream &o) const {
    Helpers::print_centered_title(o, "TABLA DE INFRACCIONES");
    Helpers::print_filled_line(o, '-');
    o << setw(8) << "CODIGO" <<
            setw(10) << "MULTA" <<
            setw(12) << "GRAVEDAD" <<
            setw(16) << "DESCRIPCION" << endl;
    Helpers::print_filled_line(o, '-');
    for (int i = 0; i < numInf; i++) {
        o << infracciones[i];
    }
}

void MinisterioDeTransporte::print_empresas(ofstream &o) const {
    Helpers::print_centered_title(o, "RELACION DE EMPRESAS CON INFRACCIONES DE TRANSITO");
    Helpers::print_filled_line(o, '-');
    o << setw(6) << "DNI" <<
            setw(12) << "NOMBRE" <<
            setw(53) << "PLACAS DE VEHICULOS" << endl;
    Helpers::print_filled_line(o, '-');
    for (int i = 0; i < numEmp; i++) {
        o << empresas[i];
    }
}
