#include "src/genericos.hpp"
#include "src/registros.hpp"
#include "src/enteros.hpp"

int main() {
    void *lista1, *lista2;

    generaLista(lista1,read_num,cmp_num,"../data/numeros2.txt");
    imprimeLista(lista1,print_num,"../dist/Repnum.txt");
    generaLista(lista2,read_reg,cmp_reg,"../data/RegistroDeFaltas1.csv");
    imprimeLista(lista2,print_reg,"../dist/Repfalta.txt");

    return 0;
}
