#include "Libraries/functions.hpp"

int main() {
    char ***categorias;
    cargarCategorias("../data/categorias.csv",
                     categorias);
    char ***streamers;
    int **fechasPromedios;
    long long **tiempoRepSeguidores;
    cargarStreamers("../data/streamers.csv",
                    streamers,
                    fechasPromedios,
                    tiempoRepSeguidores);
    char ***comentarios;
    char ***etiquetas;
    cargarComentarios("../data/comentarios.csv",
                      comentarios,
                      etiquetas);
    imprimirReporte("../report/reporte.txt",
                    categorias,
                    streamers,
                    fechasPromedios,
                    tiempoRepSeguidores,
                    comentarios,
                    etiquetas);
    return 0;
}
