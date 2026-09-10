//
// Created by jolumarti on 9/8/26.
//

#include "functions.hpp"

void increaseCategoriesSize(int &cap, int &n, char ***&categorias) {
    cap += INCREMENT;
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

void increaseStreamersSize(int &cap, int &n, char ***&streamers, int **&fechasPromedios,
                           long long **&tiempoRepSegidores) {
    cap += INCREMENT;
    char ***newStreamers = new char **[cap]{};
    int **newFechasPromedios = new int *[cap]{};
    long long **newTiempoRepSegidores = new long long *[cap]{};
    for (int i = 0; i < n; i++) {
        newStreamers[i] = streamers[i];
        newFechasPromedios[i] = fechasPromedios[i];
        newTiempoRepSegidores[i] = tiempoRepSegidores[i];
    }
    delete[] streamers;
    delete[] fechasPromedios;
    delete[] tiempoRepSegidores;
    streamers = newStreamers;
    fechasPromedios = newFechasPromedios;
    tiempoRepSegidores = newTiempoRepSegidores;
}

int readDate(ifstream &input) {
    int year, month, day;
    char c;
    input >> day >> c >> month >> c >> year;
    return year * 10000 + month * 100 + day;
}

void cargarStreamers(const char *file_name, char ***&streamers, int **&fechasPromedios,
                     long long **&tiempoRepSeguidores) {
    ifstream file;
    open_in_file(file, file_name);
    streamers = nullptr;
    fechasPromedios = nullptr;
    tiempoRepSeguidores = nullptr;
    int i = 0, cap = 0;
    while (true) {
        if (i == cap) increaseStreamersSize(cap, i, streamers, fechasPromedios, tiempoRepSeguidores);
        char **streamer = new char *[MAX_ARR_STREAMERS], c;
        int *fechaPromedio = new int[MAX_ARR_FECHA]{};
        long long *tiempoRep = new long long[MAX_ARR_TIEMPO]{};
        //xQcOW,8/1/2022,13/8/2025,6196161750,27716,3246298,QA1080
        streamer[0] = read_line(file, ',');
        if (file.eof()) {
            streamers[i] = nullptr;
            fechasPromedios[i] = nullptr;
            tiempoRepSeguidores[i] = nullptr;
            break;
        }
        fechaPromedio[0] = readDate(file);
        file.get();
        fechaPromedio[1] = readDate(file);
        file >> c >> tiempoRep[0] >> c >> fechaPromedio[3] >> c >> tiempoRep[1] >> c;
        streamer[1] = read_line(file, '\n');
        streamers[i] = streamer;
        fechasPromedios[i] = fechaPromedio;
        tiempoRepSeguidores[i] = tiempoRep;
        i++;
    }
}

void allocate_memory(int cap, int n, char ***&comentarios, char ***&etiquetas) {
    char ***newComentarios = new char **[cap]{};
    char ***newEtiquetas = new char **[cap]{};
    for (int i = 0; i < n; i++) {
        newComentarios[i] = comentarios[i];
        newEtiquetas[i] = etiquetas[i];
    }
    delete[] comentarios;
    delete[] etiquetas;
    comentarios = newComentarios;
    etiquetas = newEtiquetas;
}

char *concat_cstring(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char *result = new char[len1 + len2 + 1];
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

void cargarComentarios(const char *file_name, char ***&comentarios, char ***&etiquetas) {
    ifstream file;
    open_in_file(file, file_name);
    comentarios = nullptr;
    etiquetas = nullptr;
    int i = 0, cap = 0;
    while (true) {
        if (i == cap) allocate_memory(cap + INCREMENT, i, comentarios, etiquetas);
        char **comentario = new char *[MAX_ARR_COMENT]{};
        char **etiqueta = new char *[MAX_ARR_ETIQUETA]{};
        char c, et1[MAX_BUFFER], et2[MAX_BUFFER];
        comentario[0] = read_line(file, ',');
        if (file.eof()) {
            comentarios[i] = nullptr;
            etiquetas[i] = nullptr;
            break;
        }
        file.getline(et1, MAX_BUFFER, '[');
        etiqueta[0] = read_line(file, ' ');
        etiqueta[1] = read_line(file, ']');
        file.getline(et2, MAX_BUFFER, '\n');
        comentario[1] = concat_cstring(et1, et2);
        comentarios[i] = comentario;
        etiquetas[i] = etiqueta;
        i++;
    }
    allocate_memory(i + 1, i, comentarios, etiquetas); // recortar y agregar nullptr al final
}

void print_date(ofstream &output, int date) {
    int year = date / 10000;
    int month = (date / 100) % 100;
    int day = date % 100;
    output << setfill('0') << setw(2) << day << '-' << setw(2) << month << '-' << setw(4) << year << setfill(' ');
}

void print_streamers(char ***streamers, int **fechasPromedios, long long **tiempoRepSegidores, char ***comentarios,
                     char ***etiquetas, ofstream &file, char **cat, int w9) {
    for (int j = 0; streamers[j]; j++) {
        char **streamer = streamers[j];
        if (strcmp(streamer[1], cat[0]) == 0) {
            int *fechas = fechasPromedios[j];
            long long *tiempos = tiempoRepSegidores[j];
            file << setw(w9) << left << streamer[0] << right <<
                    setw(10) << " ";
            print_date(file, fechas[0]);
            file << setw(10) << " ";
            print_date(file, fechas[1]);
            file << setw(w9 - 2) << tiempos[0] / 1000 / 60 / 60 / 24.0 << " (dias) " <<
                    setw(w9 - 6) << tiempos[1] << setw(10) << " ";
            for (int k = 0; etiquetas[k]; k++) {
                char **etiqueta = etiquetas[k];
                char **comentario = comentarios[k];
                for (int l = 0; l < 2; l++) {
                    if (strcmp(etiqueta[l], streamer[0]) == 0) {
                        file << left << " [" << comentario[0] << "] '" << comentario[1] << "'";
                    }
                }
            }
            file << endl;
        }
    }
}

void imprimirReporte(const char *file_name, char ***categorias, char ***streamers, int **fechasPromedios,
                     long long **tiempoRepSegidores, char ***comentarios, char ***etiquetas) {
    ofstream file;
    open_out_file(file, file_name);
    for (int i = 0; categorias[i]; i++) {
        char **cat = categorias[i];
        int wc1 = (LINE_SIZE - strlen(cat[1])) / 2;
        int wc2 = LINE_SIZE - wc1 - strlen(cat[1]);
        int w9 = LINE_SIZE / 9;
        file << setfill('*') << setw(wc1) << '*' << cat[1] <<
                setw(wc2) << '*' << setfill(' ') << endl;
        file << setw(w9) << left << "CUENTA" << right <<
                setw(w9) << "FECHA CREACION" <<
                setw(w9 + 4) << "FECHA ULT. STREAM." <<
                setw(w9) << "TIEMPO REP." <<
                setw(w9) << "CANT. SEGUID." <<
                setw(w9) << "ETIQUETAS" << endl;
        print_filled_line(file, '=');
        print_streamers(streamers, fechasPromedios, tiempoRepSegidores, comentarios, etiquetas, file, cat, w9);
    }
    file.close();
}
