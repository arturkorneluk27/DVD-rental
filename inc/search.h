#ifndef SEARCH_H
#define SEARCH_H

#include "DVD.h"
#include <vector>

// Wyszukuje filmy po tytule
void searchByTitle(const std::vector<DVD> &movies);

// Wyszukuje filmy po gatunku
void searchByGenre(const std::vector<DVD> &movies);

// Wyszukuje filmy po aktorze
void searchByActor(const std::vector<DVD> &movies);

#endif