#ifndef COMMON_HPP
#define COMMON_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <climits>

#define MAX_BUFFER 120
#define MAX_VENTAS 200
#define INCREMENT 5
#define LINE_SIZE 160
#define NOT_FOUND -1
#define DET_TEXTOS 4
#define DET_VALORES 5

enum dataPaciente {ID, NAME, AGE, GENDER, VISITS, TOTAL};
enum dataVisita {DATE, HOUR, COST};

using namespace std;

#endif // COMMON_HPP
