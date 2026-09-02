#include "Libraries/Overloads.hpp"

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
int main() {
    struct Cursos cursos[20]{};// inicializados
    struct Alumnos alumnos[100]{};// inicializados
    cout << "Leyendo  Cursos" << endl;
    readCursos(cursos, "../Data/Cursos.csv");
    cout << "Leyendo  Alumnos" << endl;
    readAlumnos(alumnos, "../Data/Alumnos.csv");
    struct Alumnos &alumno = alumnos[1];
    struct Cursos &curso = cursos[2];
    cout << boolalpha;
    cout << "Codigo de alumno es igual " << (alumno>alumno.codigo) << endl;
    cout << "Codigo de curso no es igual " << (curso>"123") << endl;
    cout << "Agregar Curso a Alumno " << (curso+= alumno) << endl;
    cout << "Buscar Alumno 1=" << (alumnos<=alumno) << endl;
    cout << "Buscar Curso 2=" << (cursos<=curso) << endl;
    ++curso; // calcular tipoFinal
    cout << "Imprimir Curso" << endl << curso;
    cout << "Tipo: " << alumno.tipo << endl;
    cout << "Tipo: " << curso.numpresencial << endl;
    return 0;
}