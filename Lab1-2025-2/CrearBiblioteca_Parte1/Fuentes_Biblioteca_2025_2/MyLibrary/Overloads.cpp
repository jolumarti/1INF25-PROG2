//
// Created by jolumarti on 2026-09-03.
//

#include "Overloads.hpp"

char* readLine(ifstream &input, char delim) {
    char buffer[BUFFER_SIZE], *ptr;
    input.getline(buffer, BUFFER_SIZE, delim);
    if (input.eof()) return nullptr;
    ptr = new char[strlen(buffer) + 1];
    strcpy(ptr, buffer);
    return ptr;
}
//INF263,Algoritmia,3.75,35030611,INGA_FLORES_CESAR_ADOLFO
void operator>>(ifstream &input, struct Cursos &curso) {
    int codDocente;
    curso.codigo = readLine(input, ',');
    if (input.eof()) return;
    curso.nombre = readLine(input, ',');
    input >> curso.creditos;
    input.get();
    input >> codDocente;
    input.get();
    curso.docente = readLine(input, '\n');
}
//202111260,GORDILLO/CASTRO/RONAL,P
void operator>>(ifstream &input, struct Alumnos &alumno) {
    input >> alumno.codigo;
    input.get();
    if (input.eof()) return;
    alumno.nombre = readLine(input, ',');
    input >> alumno.tipo;
    input.get();
}

bool operator>(const struct Alumnos &alumno, const int codigo) {
    return alumno.codigo == codigo;
}
bool operator>(const struct Cursos &curso, const char *codigo) {
    return strcmp(curso.codigo, codigo) == 0;
}

void copyString(char *&dest, const char *src) {
    dest = new char[strlen(src) + 1];
    strcpy(dest, src);
}
bool operator+=(struct Cursos &curso, const struct Alumnos &alumno) {
    switch (alumno.tipo) {
        case 'P':
            curso.presencial[curso.numpresencial] = alumno;
            curso.numpresencial++;
            break;
        case 'S':
            curso.semipresencial[curso.numsemipresencial] = alumno;
            curso.numsemipresencial++;
            break;
        case 'V':
            curso.vvirtual[curso.numvirtual] = alumno;
            curso.numvirtual++;
            break;
        default:
            return false;
    }
    return true;
}
int operator<=(const struct Alumnos *alumnos, const struct Alumnos &alumno){
    int i = 0;
    while (alumnos[i].codigo) {
        if (alumnos[i].codigo == alumno.codigo) return i;
        i++;
    }
    return NOT_FOUND;
}
int operator<=(const struct Cursos *cursos, const struct Cursos &curso){
    int i = 0;
    while (cursos[i].codigo) {
        if (strcmp(cursos[i].codigo, curso.codigo) == 0) return i;
        i++;
    }
    return NOT_FOUND;
}
void operator++ (struct Cursos &curso) {
    int total = curso.numpresencial + curso.numsemipresencial + curso.numvirtual;
    float pctPresencial = (curso.numpresencial * 100.0) / total;
    if (pctPresencial > 50) copyString (curso.tipofinal, "La clase se dictara en aula");
    else copyString (curso.tipofinal, "La clase se dictara 100% virtual");
}

void operator <<(ostream &output, const struct Cursos &curso) {
    output << curso.codigo << "  " << curso.nombre << endl;
    output  << curso.docente << endl << left;
    output << setw(30)  << "Alumnos Presenciales: " << curso.numpresencial << endl;
    output << setw(30)  << "Alumnos Semipresenciales: " << curso.numsemipresencial << endl;
    output << setw(30) << "Alumnos Virtuales: " << curso.numvirtual << endl;
    output  << curso.tipofinal << endl;
}