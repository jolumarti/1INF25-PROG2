#include "src/model/GestorAtenciones.hpp"

int main() {
    GestorAtenciones gestor;
    cout<<"Comienza la Carga de Atenciones por Prioridad"<<endl;
    gestor.cargar_atenciones_prioridad("../data/1992/01/23/10.csv");
    cout<<"Termina la Carga de Atenciones por Prioridad"<<endl;
    gestor.imprime_atenciones_prioridad("../dist/report.txt");
    cout<<"Termina la Impresion de Atenciones por Prioridad"<<endl;
    return 0;
}