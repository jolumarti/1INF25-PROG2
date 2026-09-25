#ifndef LAB2_2025_2_UTILS_HPP
#define LAB2_2025_2_UTILS_HPP
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <climits>
#define MAX_BUFFER 120
#define INCREMENT 5
#define LINE_SIZE 90
#define NOT_FOUND -1

#define MAX_ARR_CAT 3
#define MAX_ARR_FECHA 3
#define MAX_ARR_STREAMERS 2
#define MAX_ARR_TIEMPO 2
#define MAX_ARR_COMENT 2
#define MAX_ARR_ETIQUETA 2

enum dataStreamer {ACCOUNT, FOLLOWERS, CATEGORY, COMMENTS};
enum dataComment {ID, SENDER, RECEIVER, TEXT};
enum dataSComment { S_RECEIVER, S_TEXT};

using namespace std;
#endif //LAB2_2025_2_UTILS_HPP
