#include "src/genericos.hpp"
#include "src/registros.hpp"
#include "src/enteros.hpp"
#define MAX 300

int main() {
    void*arreglo1[MAX]{},*arreglo2[MAX]{};
    void*lista1,*lista2;
    procesaArreglo(arreglo1,leenum,"../data/numeros1.txt");
    creaLista(arreglo1,lista1,comparanum);
    procesaArreglo(arreglo2,leenum," ../data/numeros2.txt");
    creaLista(arreglo2,lista2,comparanum);
    // fusionaListas(lista1,lista2,verificanum);
    // imprimeLista(lista1,imprimenum," ../dist/Repnum.txt");
    // procesaArreglo(arreglo1,leeregistro," ../data/Atenciones1.csv");
    // creaLista(arreglo1,lista1,comparareg);
    // procesaArreglo(arreglo2,leeregistro," ../data/Atenciones2.csv");
    // creaLista(arreglo2,lista2,comparareg);
    // fusionaListas(lista1,lista2,verificareg);
    // imprimeLista(lista1,imprimeregistro," ../dist/Repreg.txt");
    return 0;
}
