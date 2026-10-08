//
// Created by jolumarti on 2026-10-08.
//

#ifndef LAB_STREAMER_HPP
#define LAB_STREAMER_HPP
#include "../Helpers.hpp"

class Streamer {
private:
    char *cuenta;
    char *categoria;
    long long tiempo_total;
    double promedio_espectadores;
    int n_seguidores;

public:
    Streamer();
    ~Streamer();
    void get_cuenta(char * cuenta) const;

    void set_cuenta(char * const cuenta);

    void get_categoria(char *  categoria) const;

    void set_categoria(char * const categoria);

    long long get_tiempo_total() const;

    void set_tiempo_total(const long long tiempo_total);

    double get_promedio_espectadores() const;

    void set_promedio_espectadores(const double promedio_espectadores);

    int get_n_seguidores() const;

    void set_n_seguidores(const int n_seguidores);

    bool leer_streamer(ifstream &file);
    void mostrar_streamer(ostream &out);
    void copiar(const Streamer &other);
};


#endif //LAB_STREAMER_HPP
