#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Pieza.h"
#include <vector>
using namespace std;

// Declaración de funciones de inventario
void ingresarPieza(vector<Pieza>& inventario);
void consultarPieza(const vector<Pieza>& inventario);
void modificarPieza(vector<Pieza>& inventario);
void eliminarPieza(vector<Pieza>& inventario);

#endif
