//
// Created by jolumarti on 2026-09-03.
//

#include "funciones.hpp"


void openOutArch(ofstream &arch, const char *nomArch) {
    arch.open(nomArch, ios::out);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nomArch << endl;
        exit(1);
    }
    arch << setprecision(2) << fixed;
}
void openInArch(ifstream &arch, const char *nomArch) {
    arch.open(nomArch, ios::in);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nomArch << endl;
        exit(1);
    }
}

void readAlumnos(struct Alumnos *alumnos, const char *file_name) {
    ifstream alumnosArch;
    int i = 0;
    openInArch(alumnosArch, file_name);
    while (true) {
        struct Alumnos alumno{};
        alumnosArch >> alumno;
        if (alumnosArch.eof()) break;
        alumnos[i] = alumno;
        i++;
    }
}
void readCursos(struct Cursos *cursos, const char *file_name) {
    ifstream cursosArch;
    int i = 0;
    openInArch(cursosArch, file_name);
    while (true) {
        struct Cursos curso{};
        cursosArch >> curso;
        if (cursosArch.eof()) break;
        cursos[i] = curso;
        i++;
    }
}
char* leerLinea(ifstream &input, char delim) {
    char buffer[BUFFER_SIZE], *ptr;
    input.getline(buffer, BUFFER_SIZE, delim);
    if (input.eof()) return nullptr;
    ptr = new char[strlen(buffer) + 1];
    strcpy(ptr, buffer);
    return ptr;
}

void processMatricula(struct Cursos *cursos, const struct Alumnos *alumnos, const char *file_name) {
    ifstream matriculaArch;
    openInArch(matriculaArch, file_name);
    while (true) {
        char *codCurso = leerLinea(matriculaArch, ',');
        if (matriculaArch.eof()) break;
        int codAlumno;
        matriculaArch >> codAlumno;
        matriculaArch.get();
        struct Cursos tempCurso{};
        struct Alumnos tempAlumno{};
        tempCurso.codigo = codCurso;
        tempAlumno.codigo = codAlumno;
        int idAlumno = alumnos <= tempAlumno;
        int idCurso = cursos <= tempCurso;
        if (idCurso != NOT_FOUND && idAlumno != NOT_FOUND) {
            cursos[idCurso] += alumnos[idAlumno];
        } else {
            cout << "Error: Alumno o Curso no encontrado para matricula: " << codCurso << ", " << codAlumno << endl;
        }
    }
}
void printLine(ofstream &output, const char c) {
    output << setfill(c) << setw(60) << c << setfill(' ') << endl;
}
void printCursos(struct Cursos *cursos, const char *file_name) {
    ofstream cursosArch;
    openOutArch(cursosArch, file_name);
    int i = 0;
    while (cursos[i].codigo != nullptr) {
        ++cursos[i];
        cursosArch << cursos[i];
        printLine(cursosArch, '-');
        i++;
    }
}
