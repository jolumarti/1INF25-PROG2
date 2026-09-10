#include "Libraries/functions.hpp"

int main() {
    char ***categorias;
    cargarCategorias("../data/categorias.csv",
                     categorias);
    char ***streamers;
    int **fechasPromedios;
    long long **tiempoRepSegidores;
    cargarStreamers("../data/streamers.csv",
                    streamers,
                    fechasPromedios,
                    tiempoRepSegidores);
    char ***comentarios;
    char ***etiquetas;
    cargarComentarios("../data/comentarios.csv",
                      comentarios,
                      etiquetas);
    imprimirReporte("../report/reporte.txt",
                    categorias,
                    streamers,
                    fechasPromedios,
                    tiempoRepSegidores,
                    comentarios,
                    etiquetas);
    return 0;
}
