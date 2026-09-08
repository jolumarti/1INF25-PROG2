//
// Created by jolumarti on 9/8/26.
//

#include "functions.hpp"

void increaseCategoriesSize(int &cap, int &n, char ***&categorias) {
    cap+= INCREMENT;
    char ***newCategorias = new char **[cap]{};
    for (int i = 0; i < n; i++) {
        newCategorias[i] = categorias[i];
    }
    delete[] categorias;
    categorias = newCategorias;
}
void cargarCategorias(const char *file_name, char ***&categorias) {
    ifstream file;
    open_in_file(file, file_name);
    categorias = nullptr;
    int i = 0, cap = 0;
    while (true) {
        if (i == cap) increaseCategoriesSize(cap, i, categorias);
        char **categoria = new char *[MAX_ARR_CAT];
        categoria[0] = read_line(file, ',');
        if (file.eof()) {
            categorias[i] = nullptr;
            break;
        }
        categoria[1] = read_line(file, ',');
        categoria[2] = read_line(file, '\n');
        categorias[i] = categoria;
        i++;
    }
    file.close();
}
void cargarStreamers(const char *file_name, char ***&streamers, int **&fechasPromedios, long long **&tiempoRepSegidores) {
    ifstream file;
    open_in_file(file, file_name);
    streamers = nullptr;
    fechasPromedios = nullptr;
    tiempoRepSegidores = nullptr;
    int i = 0, cap = 0;
    while (true) {
        if (i == cap) increaseStreamersSize(cap, i, streamers);
        char **streamer = new char *[MAX_ARR_CHAR];
        streamer[0] = read_line(file, ',');
        if (file.eof()) {
            streamers[i] = nullptr;
            break;
        }
        streamer[1] = read_line(file, ',');
        streamer[2] = read_line(file, '\n');
        streamers[i] = streamer;
        i++;
    }
    file.close();
}