#include "Libraries/funciones.hpp"

int main() {
    struct Cursos cursos[20]{};
    struct Alumnos alumnos[100]{};
    readCursos(cursos, "../Data/Cursos.csv");
    readAlumnos(alumnos, "../Data/Alumnos.csv");
    processMatricula(cursos, alumnos, "../Data/Matricula.csv");
    printCursos(cursos, "../Report/Reporte.txt");
    return 0;
}