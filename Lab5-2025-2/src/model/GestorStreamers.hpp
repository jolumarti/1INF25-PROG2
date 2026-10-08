//
// Created by jolumarti on 2026-10-08.
//

#ifndef LAB_GESTORSTREAMERS_HPP
#define LAB_GESTORSTREAMERS_HPP
#include "Streamer.hpp"


class GestorStreamers {
private:
    Streamer *data;
    Streamer *dataVista;
    int cantidad_datos;
    int cantidad_datos_vista;


public:
    GestorStreamers();
    ~GestorStreamers();
    void resize_data(Streamer *&arr, int cap, int num);
    void cargar_datos(const char *filename);
    void mostrar_menu();
    void copiar_datos();
    void cortar_datos(int cant);
    void print_menu();
    void print_menu_reports();
    bool verify_loaded(bool is_loaded);
    void select_report(ostream &out);
    void pause_menu();
    void print_title(ostream &out, const char* title);
    void print_data(ostream &out);
    void all_reports(ostream &out);
    void report_top10_followers(ostream &out);
    void report_bot10_duration(ostream &out);
    void report_top5_viewers(ostream &out);
    void report_influence(ostream &out);
    void report_category(ostream &out);
    static int cmp_top10_followers(const void* a, const void* b);
    static int cmp_bot10_duration(const void* a, const void* b);
    static int cmp_top5_viewers(const void* a, const void* b);
    static int cmp_influence(const void* a, const void* b);
    static int cmp_category(const void* a, const void* b);

    
};


#endif //LAB_GESTORSTREAMERS_HPP
