#include "src/genericos.hpp"
#include "src/registros.hpp"
#include "src/enteros.hpp"
#define MAX 300

int main() {
    void *arreglo1[MAX]{}, *arreglo2[MAX]{};
    void *lista1, *lista2;
    procesarArreglo(arreglo1, leenum, "../data/numeros1.txt");
    crearLista(arreglo1, lista1, comparanum);
    procesarArreglo(arreglo2, leenum, "../data/numeros2.txt");
    crearLista(arreglo2, lista2, comparanum);
    fusionaListas(lista1, lista2, comparanum);
    imprimeLista(lista1, imprimenum, "../dist/Repnum.txt");
    procesarArreglo(arreglo1, leerRegistro, "../data/Atenciones1.csv");
    crearLista(arreglo1,lista1,compararReg);
    procesarArreglo(arreglo2,leerRegistro,"../data/Atenciones2.csv");
    crearLista(arreglo2,lista2,compararReg);
    fusionaListas(lista1,lista2,compararReg);
    imprimeLista(lista1,imprimeReg,"../dist/Repreg.txt");
    return 0;
}
