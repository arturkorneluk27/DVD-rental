#ifndef ADMIN_DVD_MENU_H
#define ADMIN_DVD_MENU_H

#include "DVD.h"
#include <vector>

// Dodaje nowe DVD do systemu
void addDVD(std::vector<DVD> &movies);

// Usuwa DVD z systemu
void removeDVD(std::vector<DVD> &movies);

// Edytuje dane istniejacego DVD
void editDVD(std::vector<DVD> &movies);

// Menu zarzadzania DVD
void manageDVDs(std::vector<DVD> &movies);

#endif