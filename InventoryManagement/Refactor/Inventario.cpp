#include "Inventario.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <fstream>
using namespace std;

void ingresarPieza(vector<Pieza>& inventario) {
    string cod, nom, emp, fact, ced;
    double cost;
    int cant;
    
    cout << "Ingrese el código de la pieza (Formato: P#######): ";
    cin >> cod;
    while ((cod[0] != 'P') || (cod.length() != 9)) {
        cout << "Código de pieza incorrecto. Formato correcto: P#######. Intente nuevamente: ";
        cin >> cod;
    }
    
    cout << "Ingrese el nombre de la pieza: ";
    cin.ignore();
    getline(cin, nom);
    
    cout << "Ingrese el costo de la pieza: ";
    cin >> cost;
    while (cin.fail() || cost < 0) {
        cout << "Costo incorrecto. Debe ser un número positivo. Intente nuevamente: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> cost;
    }
    
    cout << "Ingrese la cantidad de piezas: ";
    cin >> cant;
    while (cin.fail() || cant < 0) {
        cout << "Cantidad incorrecta. Debe ser un número positivo. Intente nuevamente: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> cant;
    }
    
    cout << "Ingrese el nombre de la empresa que provee las piezas: ";
    cin.ignore();
    getline(cin, emp);
    
    cout << "Ingrese la factura de la empresa: ";
    getline(cin, fact);
    
    cout << "Ingrese su cédula (9 dígitos): ";
    cin >> ced;
    while ((ced.length() != 9) || (!all_of(ced.begin(), ced.end(), ::isdigit))) {
        cout << "Cédula incorrecta. Debe tener 9 dígitos. Intente nuevamente: ";
        cin >> ced;
    }
    
    // Crear y agregar la pieza
    Pieza nuevaPieza(cod, nom, cost, cant, emp, fact, ced);
    inventario.push_back(nuevaPieza);
    
    cout << "Pieza ingresada correctamente." << endl;
}

void consultarPieza(const vector<Pieza>& inventario) {
    string codigoConsultar;
    cout << "Ingrese el código de la pieza a consultar: ";
    cin >> codigoConsultar;
    
    bool encontrado = false;
    for (const auto& pieza : inventario) {
        if (pieza.getCodigo() == codigoConsultar) {
            encontrado = true;
            cout << "Información de la pieza:" << endl;
            pieza.mostrarInfo();
            break;
        }
    }
    
    if (!encontrado) {
        cout << "Pieza no encontrada." << endl;
    }
}

// Las otras funciones (modificar, eliminar) las completamos después
void modificarPieza(vector<Pieza>& inventario) {
    cout << "Función modificar pieza - En desarrollo" << endl;
}

void eliminarPieza(vector<Pieza>& inventario) {
    cout << "Función eliminar pieza - En desarrollo" << endl;
}
