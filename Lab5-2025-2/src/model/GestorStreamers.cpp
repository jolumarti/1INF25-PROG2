//
// Created by jolumarti on 2026-10-08.
//

#include "GestorStreamers.hpp"

GestorStreamers::GestorStreamers() {
    data = nullptr;
    dataVista = nullptr;
    cantidad_datos = 0;
    cantidad_datos_vista = 0;
}

GestorStreamers::~GestorStreamers() {
    delete[] data;
    delete[] dataVista;
}

void GestorStreamers::resize_data(Streamer *&arr, int cap, int num) {
    Streamer *new_arr = new Streamer[cap]{};
    for (int i = 0; i < num; ++i) {
        new_arr[i].copiar(arr[i]);
    }
    delete[] arr;
    arr = new_arr;
}

void GestorStreamers::cargar_datos(const char *filename) {
    ifstream file;
    Helpers::open_ifstream(file, filename);
    int cap = 0;
    while (true) {
        if (cap == cantidad_datos) {
            cap += INCREMENT;
            resize_data(data, cap, cantidad_datos);
        }
        Streamer streamer;
        if (!streamer.leer_streamer(file)) break;
        data[cantidad_datos++].copiar(streamer);
    }
    resize_data(data, cantidad_datos, cantidad_datos);
}

void GestorStreamers::mostrar_menu() {
    bool is_loaded = false;
    char option{};
    ofstream file;
    Helpers::open_ofstream(file, "../dist/reporte.txt");
    while (true) {
        print_menu();
        cin >> option;
        switch (option) {
            case 'a':
                if (!is_loaded) cargar_datos("../data/streamers.csv");
                is_loaded = true;
                cout << "Datos cargados correctamente.\n";
                break;
            case 'b':
                if (verify_loaded(is_loaded)) {
                    cout << "Seleccionar Reporte para Mostrar:\n";
                    select_report(cout);
                    pause_menu();
                }
                break;
            case 'c':
                if (verify_loaded(is_loaded)) {
                    cout << "Seleccionar Reporte para Generar:\n";
                    select_report(file);
                    pause_menu();
                }
                break;
            case 'd':
                if (verify_loaded(is_loaded)) {
                    all_reports(file);
                    cout << "Todos los reportes fueron generados. ";
                    pause_menu();
                }
                break;
        }
        if (option == 'e') break;
    }
}

void GestorStreamers::copiar_datos() {
    delete[] dataVista;
    dataVista = new Streamer[cantidad_datos]{};
    cantidad_datos_vista = cantidad_datos;
    for (int i = 0; i < cantidad_datos; ++i) {
        dataVista[i].copiar(data[i]);
    }
}

void GestorStreamers::cortar_datos(int cant) {
    resize_data(dataVista, cant, cant);
    cantidad_datos_vista = cant;
}

void GestorStreamers::print_menu() {
    cout << "a) Cargar Datos\n" <<
            "b) Mostrar Reporte\n";
    print_menu_reports();
    cout << "c) Generar Reporte\n";
    print_menu_reports();
    cout << "d) Generar Todos los reportes\n" <<
            "e) Terminar\n" << "Ingresa opcion: ";
}

void GestorStreamers::print_menu_reports() {
    cout << "   i) Reporte Top10 streamers por numero de seguidores.\n" <<
            "   ii) Reporte Bottom10 streamers por tiempo total transmitido.\n" <<
            "   iii) Reporte Top5 categorias con mayor promedio de espectadores.\n" <<
            "   iv) Reporte de Categoria\n" <<
            "   v) Reporte de Influencia\n";
}

bool GestorStreamers::verify_loaded(bool is_loaded) {
    if (!is_loaded) {
        cout << "Error: Debes cargar los datos antes de generar reportes.\n";
        pause_menu();
        return false;
    }
    return true;
}

void GestorStreamers::select_report(ostream &out) {
    char option[4];
    while (true) {
        print_menu_reports();
        cout << "Ingrese opcion: ";
        cin >> setw(4) >> option;
        if (strcmp(option, "i") == 0) report_top10_followers(out);
        else if (strcmp(option, "ii") == 0) report_bot10_duration(out);
        else if (strcmp(option, "iii") == 0) report_top5_viewers(out);
        else if (strcmp(option, "iv") == 0) report_category(out);
        else if (strcmp(option, "v") == 0) report_influence(out);
        else {
            out << "Opcion invalida. Intente otra vez.\n";
            continue;
        }
        break;
    }
}

void GestorStreamers::pause_menu() {
    cout << "\nPresiona enter para continuar.\n";
    cin.ignore();
    cin.get();
}

void GestorStreamers::print_title(ostream &out, const char *title) {
    int mid = LINE_SIZE / 2 + strlen(title) / 2;
    Helpers::print_filled_line(out, '=');
    out << setw(mid) << setfill(' ') << title << endl;
    Helpers::print_filled_line(out, '=');
    out << "Streamer" <<
            setw(LINE_SIZE / 5 + 1) << "Categoria" <<
            setw(LINE_SIZE / 5 + 6) << "Seguidores" <<
            setw(LINE_SIZE / 5) << "Tiempo(dias)" <<
            setw(LINE_SIZE / 5 + 2) << "Prom. Espectadores" << '\n';
    Helpers::print_filled_line(out, '-');
}

void GestorStreamers::print_data(ostream &out) {
    for (int i = 0; i < cantidad_datos_vista; i++) {
        Streamer &streamer = dataVista[i];
        streamer.mostrar_streamer(out);
    }
}

void GestorStreamers::all_reports(ostream &out) {
    report_top10_followers(out);
    report_bot10_duration(out);
    report_top5_viewers(out);
    report_influence(out);
    report_category(out);
}

void GestorStreamers::report_top10_followers(ostream &out) {
    copiar_datos();
    qsort(dataVista, cantidad_datos_vista, sizeof(Streamer), cmp_top10_followers);
    cortar_datos(10);
    print_title(out, "Reporte Top10 streamers por número de seguidores");
    print_data(out);
}

void GestorStreamers::report_bot10_duration(ostream &out) {
    copiar_datos();
    qsort(dataVista, cantidad_datos_vista, sizeof(Streamer), cmp_bot10_duration);
    cortar_datos(10);
    print_title(out, "Reporte Bottom10 streamers por tiempo total transmitido");
    print_data(out);
}

void GestorStreamers::report_top5_viewers(ostream &out) {
    copiar_datos();
    qsort(dataVista, cantidad_datos_vista, sizeof(Streamer), cmp_top5_viewers);
    cortar_datos(5);
    print_title(out, "Reporte Top5 categorías con mayor promedio de espectadores");
    print_data(out);
}

void GestorStreamers::report_influence(ostream &out) {
    copiar_datos();
    qsort(dataVista, cantidad_datos_vista, sizeof(Streamer), cmp_influence);
    print_title(out, "Reporte de Influencia");
    print_data(out);
}

void GestorStreamers::report_category(ostream &out) {
    copiar_datos();
    qsort(dataVista, cantidad_datos_vista, sizeof(Streamer), cmp_category);
    print_title(out, "Reporte de Categoría");
    print_data(out);
}

int GestorStreamers::cmp_top10_followers(const void *a, const void *b) {
    const Streamer &s1 = *(Streamer *) (a);
    const Streamer &s2 = *(Streamer *) (b);
    return s2.get_n_seguidores() - s1.get_n_seguidores();
}

int GestorStreamers::cmp_bot10_duration(const void *a, const void *b) {
    const Streamer &s1 = *(Streamer *) (a);
    const Streamer &s2 = *(Streamer *) (b);
    if (s1.get_tiempo_total() < s2.get_tiempo_total())return -1;
    if (s1.get_tiempo_total() > s2.get_tiempo_total())return 1;
    return 0;
}

int GestorStreamers::cmp_top5_viewers(const void *a, const void *b) {
    const Streamer &s1 = *(Streamer *) (a);
    const Streamer &s2 = *(Streamer *) (b);
    double v1 = s1.get_promedio_espectadores();
    double v2 = s2.get_promedio_espectadores();
    if (v1 < v2) return 1;
    if (v1 > v2) return -1;
    return 0;
}

int GestorStreamers::cmp_influence(const void *a, const void *b) {
    const Streamer &s1 = *(Streamer *) (a);
    const Streamer &s2 = *(Streamer *) (b);
    long long inf1 = s1.get_promedio_espectadores() * (s1.get_tiempo_total() /
                                                       log(s1.get_n_seguidores() + 1));
    long long inf2 = s2.get_promedio_espectadores() * (s2.get_tiempo_total() /
                                                       log(s2.get_n_seguidores() + 1));
    if (inf1 < inf2) return 1;
    if (inf1 > inf2) return -1;
    return 0;
}

int GestorStreamers::cmp_category(const void *a, const void *b) {
    const Streamer &s1 = *(Streamer *) (a);
    const Streamer &s2 = *(Streamer *) (b);
    char cat1[M_BUFFER], cat2[M_BUFFER];
    s1.get_categoria(cat1);
    s2.get_categoria(cat2);
    return strcmp(cat1, cat2);
}
