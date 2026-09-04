//
// Created by jolumarti on 9/1/26.
//

#include "functions.hpp"

void open_in_file(ifstream &input, const char *file_name) {
    input.open(file_name, ios::in);
    if (!input.is_open()) {
        cout << "El archivo no se pudo abrir: " << file_name << endl;
        exit(1);
    }
}

void open_out_file(ofstream &output, const char *file_name) {
    output.open(file_name, ios::out);
    if (!output.is_open()) {
        cout << "El archivo no se pudo abrir: " << file_name << endl;
        exit(1);
    }
    output << fixed << setprecision(2);
}

char *readLine(ifstream &input, const char deli) {
    char buffer[MAX_BUFFER];
    input.getline(buffer, MAX_BUFFER, deli);
    char *p = new char[strlen(buffer) + 1]{};
    strcpy(p, buffer);
    return p;
}

int readDate(ifstream &input) {
    int year, month, day;
    char c;
    input >> day >> c >> month >> c >> year;
    return year * 10000 + month * 100 + day;
}

int readTime(ifstream &input) {
    int hours, minutes, seconds;
    char c;
    input >> hours >> c >> minutes >> c >> seconds;
    return hours * 10000 + minutes * 100 + seconds;
}

int timeInSeconds(const int time) {
    int hours, minutes, seconds;
    hours = time / 10000;
    minutes = (time % 10000) / 100;
    seconds = time % 100;
    return hours * 3600 + minutes * 60 + seconds;
}

int seconds2Time(const int secs) {
    int hours, minutes, seconds;
    hours = secs / 3600;
    minutes = (secs % 3600) / 60;
    seconds = secs % 60;
    return hours * 10000 + minutes * 100 + seconds;
}

int calDuration(const int t1, const int t2) {
    return seconds2Time(timeInSeconds(t1) - timeInSeconds(t2));
}

void readInfoLine(ifstream &file, int **datoInts, char **datoTexto, float **datoFloats) {
    int horaIngreso, horaAlta, presionSis, presionDias;
    char *idPaciente, *nombre, *especialidad, c;
    float temp;

    file.get();
    idPaciente = readLine(file, ',');
    nombre = readLine(file, ',');
    horaIngreso = readTime(file);
    file.get();
    file >> temp >> c >> presionSis >> presionDias >> c;
    horaAlta = readTime(file);
    file.get();
    especialidad = readLine(file, '\n');

    datoInts[0] = new int(horaIngreso);
    datoInts[1] = new int(presionSis);
    datoInts[2] = new int(presionDias);
    datoInts[3] = new int(horaAlta);

    datoTexto[0] = idPaciente;
    datoTexto[1] = nombre;
    datoTexto[2] = especialidad;

    datoFloats[0] = new float(temp);
}

// lo hacemos por incrementos, just for fun
void cargarInformacion(const char *fileName, int *&fechas, char **&datosDeTexto,
                       int **&datoEnteros, float **&DatosDePuntoFlotante) {
    ifstream file;
    open_in_file(file, fileName);
    while (true) {
        //6/04/2024,864-13-9865,S Valadez,03:54:00,36.8,121,99,05:33:10,Ginecologia
        int fecha = readDate(file);
        if (file.eof()) break;
        int *datoInts[5]{};
        char *datoTexto[3]{};
        float *datoFloats[2]{};
        readInfoLine(file, datoInts, datoTexto, datoFloats);

    }
}
