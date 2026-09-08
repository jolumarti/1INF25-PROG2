#include "Libraries/functions.hpp"

int main() {
    char ***categorias;
    cargarCategorias("categorias.csv",
                     categorias);
    char ***streamers;
    int **fechasPromedios;
    long long **tiempoRepSegidores;
    cargarStreamers("streamers.csv",
                    streamers,
                    fechasPromedios,
                    tiempoRepSegidores);
    // char ***comentarios;
    // char ***etiquetas;
    // cargarComentarios("comentarios.csv",
    //                   comentarios,
    //                   etiquetas);
    // imprimirReporte("reporte.txt",
    //                 categorias,
    //                 streamers,
    //                 fechasPromedios,
    //                 tiempoRepSegidores,
    //                 comentarios,
    //                 etiquetas);
    return 0;
    return 0;
}
