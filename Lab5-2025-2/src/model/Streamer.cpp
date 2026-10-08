//
// Created by jolumarti on 2026-10-08.
//

#include "Streamer.hpp"


Streamer::Streamer() {
    cuenta = nullptr;
    categoria = nullptr;
}

Streamer::~Streamer() {
    delete [] cuenta;
    delete [] categoria;
}

void Streamer::get_cuenta(char *cuenta) const {
    Helpers::get_str(this->cuenta, cuenta);
}

void Streamer::set_cuenta(char * const cuenta) {
    Helpers::set_str(this->cuenta, cuenta);
}

void Streamer::get_categoria(char *categoria) const {
    Helpers::get_str(this->categoria, categoria);
}

void Streamer::set_categoria(char * const categoria) {
    Helpers::set_str(this->categoria, categoria);
}

long long Streamer::get_tiempo_total() const {
    return tiempo_total;
}

void Streamer::set_tiempo_total(const long long tiempo_total) {
    this->tiempo_total = tiempo_total;
}

double Streamer::get_promedio_espectadores() const {
    return promedio_espectadores;
}

void Streamer::set_promedio_espectadores(const double promedio_espectadores) {
    this->promedio_espectadores = promedio_espectadores;
}

int Streamer::get_n_seguidores() const {
    return n_seguidores;
}

void Streamer::set_n_seguidores(const int n_seguidores) {
    this->n_seguidores = n_seguidores;
}

bool Streamer::leer_streamer(ifstream &file) {
    char buffer[M_BUFFER], c;
    //XStormHD,5758257274,38932.69,4865726,PUBG
    file.getline(buffer, M_BUFFER, ',');
    if (file.eof()) return false;
    set_cuenta(buffer);
    file >> tiempo_total >> c >> promedio_espectadores >> c >>n_seguidores >> c;
    file.getline(buffer, M_BUFFER, '\n');
    set_categoria(buffer);
    return true;
}

void Streamer::mostrar_streamer(ostream &out) {
    out <<  setw(LINE_SIZE / 5) <<left << cuenta <<
            setw(LINE_SIZE / 5) << categoria << right <<
            setw(13) << n_seguidores <<
            setw(LINE_SIZE / 5-2) << tiempo_total/60/60/24 <<
            setw(LINE_SIZE / 5+2) << promedio_espectadores << '\n';
}

void Streamer::copiar(const Streamer &other) {
    set_cuenta(other.cuenta);
    set_categoria(other.categoria);
    tiempo_total = other.tiempo_total;
    promedio_espectadores = other.promedio_espectadores;
    n_seguidores = other.n_seguidores;
}
