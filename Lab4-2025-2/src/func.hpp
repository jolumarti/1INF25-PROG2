//
// Created by jolumarti on 2026-10-01.
//

#ifndef LAB4_2025_2_FUNC_HPP
#define LAB4_2025_2_FUNC_HPP
#include "List.hpp"
#include "helpers.hpp"
#include "comunes.h"
void new_list(List &list);
void push_front(List &list, void *element, void *(*clone)(void *));
void push_back(List &list, void *element, void *(*clone)(void *));

void *begin(List &list);
void *end();
void *next(void *node);
void *getValue(void *node);
void foreach(List &list, void(*fun) (void*));
bool findIf(List &list, bool (*cmp)(void *, void *), void *valor_busqueda);
#endif //LAB4_2025_2_FUNC_HPP
