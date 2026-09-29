//
// Created by jolumarti on 2026-09-12.
//

#include "functions.hpp"
using namespace std;

void cargarPacientes(const char *file_name, char ***&pacientes) {
    ifstream input;
    open_in_file(input, file_name);
    int numPacientes;
    input >> numPacientes;
    input.ignore();
    pacientes = new char **[numPacientes + 1]{};
    for (int i = 0; i < numPacientes; ++i) {
        pacientes[i] = new char *[3]{};
        for (int j = 0; j < 3; ++j) {
            pacientes[i][j] = read_line(input);
        }
    }
    input.close();
}