//
// Created by jolumarti on 9/1/26.
//

#include "functions.hpp"

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
    int timeDiff = timeInSeconds(t1) - timeInSeconds(t2);
    if (timeDiff < 0) timeDiff += 24*60*60; // Ajuste para tiempos que cruzan la medianoche
    return seconds2Time(timeDiff);
}

void readInfoLine(ifstream &file, int *&datoInts, char **&datoTexto, float *&datoFloats) {
    int horaIngreso, horaAlta, presionSis, presionDias;
    datoInts = new int[MAX_ARR_INT]{};
    char *idPaciente, *nombre, *especialidad, c;
    datoTexto = new char *[MAX_ARR_CHAR]{};
    float temp;
    datoFloats = new float[MAX_ARR_FLOAT]{};
    file.get();
    idPaciente = read_line(file, ',');
    nombre = read_line(file, ',');
    horaIngreso = readTime(file);
    file.get();
    file >> temp >> c >> presionSis >> c >> presionDias >> c;
    horaAlta = readTime(file);
    file.get();
    especialidad = read_line(file, '\n');
    datoInts[0] = horaIngreso;
    datoInts[1] = horaAlta;
    datoInts[2] = presionSis;
    datoInts[3] = presionDias;
    datoTexto[0] = idPaciente;
    datoTexto[1] = nombre;
    datoTexto[2] = especialidad;
    datoFloats[0] = temp;
}

void resizeArr(int cap, int n, int *&fechas, char ***&datosDeTexto, int **&datosEnteros,
               float **&datosDePuntoFlotante) {
    int *newFechas = new int[cap]{};
    char ***newDatosDeTexto = new char **[cap]{};
    int **newDatosEnteros = new int *[cap]{};
    float **newDatosDePuntoFlotante = new float *[cap]{};
    for (int i = 0; i < n; i++) {
        newFechas[i] = fechas[i];
        newDatosDeTexto[i] = datosDeTexto[i];
        newDatosEnteros[i] = datosEnteros[i];
        newDatosDePuntoFlotante[i] = datosDePuntoFlotante[i];
    }
    delete[] fechas;
    delete[] datosDeTexto;
    delete[] datosEnteros;
    delete[] datosDePuntoFlotante;
    fechas = newFechas;
    datosEnteros = newDatosEnteros;
    datosDeTexto = newDatosDeTexto;
    datosDePuntoFlotante = newDatosDePuntoFlotante;
}

// lo hacemos por incrementos, just for fun
void increaseCap(int &cap, int n, int *&fechas, char ***&datosDeTexto,
                 int **&datosEnteros, float **&datosDePuntoFlotante) {
    cap += INCREMENT;
    resizeArr(cap, n, fechas, datosDeTexto, datosEnteros, datosDePuntoFlotante);
}

void orderedInsertion(int *&fechas, char ***&datosDeTexto, int **&datosEnteros, float **&datosDePuntoFlotante, int n,
                      int fecha, int *datoInts, char **datoTexto, float *datoFloats) {
    int i;
    for (i = n - 1; i >= 0 && fechas[i] > fecha; i--) {
        fechas[i + 1] = fechas[i]; // mueve a la derecha
        datosEnteros[i + 1] = datosEnteros[i];
        datosDePuntoFlotante[i + 1] = datosDePuntoFlotante[i];
        datosDeTexto[i + 1] = datosDeTexto[i];
    }
    fechas[i + 1] = fecha; // insertar en la posición correcta
    datosEnteros[i + 1] = datoInts;
    datosDePuntoFlotante[i + 1] = datoFloats;
    datosDeTexto[i + 1] = datoTexto;
}

void cargarInformacion(const char *fileName, int *&fechas, char ***&datosDeTexto,
                       int **&datosEnteros, float **&datosDePuntoFlotante) {
    ifstream file;
    open_in_file(file, fileName);
    int n{}, cap{};
    while (true) {
        if (n == cap) increaseCap(cap, n, fechas, datosDeTexto, datosEnteros, datosDePuntoFlotante);
        //6/04/2024,864-13-9865,S Valadez,03:54:00,36.8,121,99,05:33:10,Ginecologia
        int fecha = readDate(file);
        if (file.eof()) {
            fechas[n] = 0;
            datosEnteros[n] = nullptr;
            datosDePuntoFlotante[n] = nullptr;
            datosDeTexto[n] = nullptr;
            resizeArr(n + 1, n, fechas, datosDeTexto, datosEnteros, datosDePuntoFlotante);
            // recortamos el tamaño del arreglo a n
            break;
        }
        int *datoInts{};
        char **datoTexto{};
        float *datoFloats{};
        readInfoLine(file, datoInts, datoTexto, datoFloats);
        orderedInsertion(fechas, datosDeTexto, datosEnteros, datosDePuntoFlotante, n,
                         fecha, datoInts, datoTexto, datoFloats);
        n++;
    }
}

void completarInformacion(int **&datosEnteros, float **&datosDePuntoFlotante) {
    cout << "Ingresar costo por hora: " << endl;
    // float costoHora{10}; // Prueba de costo
    float costoHora{};
    cin >> costoHora;
    cout << "Costo por hora: " << costoHora << endl;
    for (int i = 0; datosEnteros[i] != nullptr; i++) {
        int horaIngreso = datosEnteros[i][0];
        int horaAlta = datosEnteros[i][1];
        int duracion = calDuration(horaAlta, horaIngreso);
        datosEnteros[i][4] = duracion;
        datosDePuntoFlotante[i][1] = costoHora * duracion / 3600.0; // costo total
    }
}

void printTime(ofstream &output, int time, int width) {
    int hours = time / 10000;
    int minutes = (time % 10000) / 100;
    int seconds = time % 100;
    output << setw(width) << ' ' << setw(2) << setfill('0') << hours << ":"
            << setw(2) << setfill('0') << minutes << ":"
            << setw(2) << setfill('0') << seconds << setfill(' ');
}

void printDate(ofstream &output, int date) {
    int year = date / 10000;
    int month = (date % 10000) / 100;
    int day = date % 100;
    output << setw(2) << setfill('0') << day << "/"
            << setw(2) << setfill('0') << month << "/"
            << setw(4) << setfill('0') << year << setfill(' ');
}

void reporteDeAtenciones(const char *fileName, int *fechas, char ***datosDeTexto,
                         int **datosEnteros, float **datosDePuntoFlotante) {
    ofstream output;
    open_out_file(output, fileName);
    int temp = INT_MIN, columnSize = LINE_SIZE/9;
    output << setw(LINE_SIZE / 2+16) << "CLINICA DE URGENCIAS PROG2 SALUD" << endl;
    output << setw(LINE_SIZE / 2+11) << "REGISTRO DE ATENCIONES" << endl;
    for (int i = 0; fechas[i] != 0; i++) {
        if (fechas[i] != temp) {
            temp = fechas[i];
            print_filled_line(output, '=');
            output << "FECHA: ";
            printDate(output, fechas[i]);
            output << endl << "REGISTRO DE ATENCIONES:" << endl;
            print_filled_line(output, '-');

            output << setw(6) << "ID" << setw(columnSize+4) << "NOMBRE" << setw(columnSize-1) << "INGRESO"
        << setw(columnSize-2) << "ALTA" << setw(columnSize+1) << "DURACION" << setw(columnSize-1) << "COSTO"
            << setw(columnSize+4) << "TEMPERATURA" << setw(columnSize+4) << "PRESION ARTERIAL"
            << setw(columnSize+3) << "ESPECIALIDAD" << endl;

        }
        output << datosDeTexto[i][0] // ID Paciente
                << setw(columnSize) << datosDeTexto[i][1]; // Nombre
        printTime(output, datosEnteros[i][0], columnSize-9);// Hora Ingreso
        printTime(output, datosEnteros[i][1], columnSize-9);// Hora Alta
        printTime(output, datosEnteros[i][4], columnSize-9);// Duracion
               output << setw(columnSize) << datosDePuntoFlotante[i][1] // Costo Total
                << setw(columnSize) << datosDePuntoFlotante[i][0] // Temp
                << setw(columnSize-2) << datosEnteros[i][2] << '/' << left
                << setw (5) << datosEnteros[i][3] <<right // Presiones
                << setw(columnSize+6) << datosDeTexto[i][2] // Especialidad
                << endl;
    }
}
