//
// Created by jolumarti on 2026-09-01.
//

#ifndef LAB1_2026_1_ATENCION_HPP
#define LAB1_2026_1_ATENCION_HPP
//01,204,7/4/2025,CONTROL,11:00,PROGRAMADA
struct Atencion {
    int idAtencion;
    int idMascota;
    int idVeterinario;
    int fecha;
    int hora;
    int minutos;
    char *tipo;
    char *estado;

};
#endif //LAB1_2026_1_ATENCION_HPP