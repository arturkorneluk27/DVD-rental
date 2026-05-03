#ifndef SEARCH_MENU_H
#define SEARCH_MENU_H

#include <vector>
#include "DVD.h"
#include "search.h"

// Wyswietla opcje wyszukiwania, wywoluje odpowiednie funkcje z search.cpp
void searchDVD(const std::vector<DVD> &movies);

#endif