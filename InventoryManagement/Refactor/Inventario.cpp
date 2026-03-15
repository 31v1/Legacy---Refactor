#include "Inventario.h"
#include "Validaciones.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>
using namespace std;

//Guardar pieza en archivo
void guardarPiezaArchivo(const Pieza& pieza) {
    ofstream archivo("Inventario.txt", ios::app);
    if (archivo.is_open()) {
        archivo << pieza.getCodigo() << " "
                << pieza.getNombre() << " "
                << pieza.getCosto() << " "
                << pieza.getCantidad() << " "
                << pieza.getEmpresa() << " "
                << pieza.getFactura() << " "
                << pieza.getCedula() << endl;
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para guardar la pieza" << endl;
    }
}

//subir archivo de inventario
vector<Pieza> subirInventario() {
    vector<Pieza> inventario;
    ifstream archivo("Inventario.txt");
    if (archivo.is_open()) {
        string codigo, nombre, empresa, factura, cedula;
        double costo;
        int cantidad;
        while (archivo >> codigo >> nombre >> costo >> cantidad >> empresa >> factura >> cedula) {
            Pieza pieza;
            pieza.setCodigo(codigo);
            pieza.setNombre(nombre);
            pieza.setCosto(costo);
            pieza.setCantidad(cantidad);
            pieza.setEmpresa(empresa);
            pieza.setFactura(factura);
            pieza.setCedula(cedula);
            inventario.push_back(pieza);
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para cargar el inventario." << endl;
    }
    return inventario;
}

//Opcion a
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
        cout << "Costo incorrecto. Debe ser un número positivo. Intente nuevamente: .";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> cost;
    }

    cout << "Ingrese la cantidad de piezas: ";
    cin >> cant;
    while ((cin.fail()) || (cant < 0)) {
        cout << "Cantidad incorrecta. Debe ser un número positivo. Intente nuevamente: .";
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

    Pieza nuevaPieza(cod, nom, cost, cant, emp, fact, ced);
    guardarPiezaArchivo(nuevaPieza);
    inventario.push_back(nuevaPieza); // para mantener el vector actualizado
}

//Opcion b
void consultarPieza(const vector<Pieza>& inventario) {
    string piezaConsultar;
    cout << "Ingrese el código de la pieza a consultar: ";
    cin >> piezaConsultar;

    bool encontrado = false;
    for (const auto& pieza : inventario) {
        if (pieza.getCodigo() == piezaConsultar) {
            encontrado = true;
            cout << "Informacion actual de la pieza \n";
            pieza.mostrarInfo();
        }
    }

    if (!encontrado) {
        cout << "Pieza no encontrada" << endl;
    }
}

//Opcion c
void modificarPieza(vector<Pieza>& inventario) {
    string codigoPieza;
    cout << "Ingrese el código de la pieza a modificar: ";
    cin >> codigoPieza;

    bool encontrado = false;

    for (auto& pieza : inventario) {
        if (pieza.getCodigo() == codigoPieza) {
            encontrado = true;

            cout << "Informacíon actual de la pieza \n";
            pieza.mostrarInfo();

            string nuevoNombre, nuevaEmpresa, nuevaFactura, nuevaCedula;
            double nuevoCosto;
            int nuevaCantidad;

            cout << "Ingrese el nuevo nombre de la pieza: ";
            cin.ignore();
            getline(cin, nuevoNombre);

            cout << "Ingrese el nuevo costo de la pieza: ";
            cin >> nuevoCosto;
            cin.ignore();
            while ((cin.fail()) || (nuevoCosto < 0)) {
                cout << "Costo incorrecto. Deber ser un número positivo. Intente de nuevo: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> nuevoCosto;
            }

            cout << "Ingrese la nueva cantidad de piezas: ";
            cin >> nuevaCantidad;
            cin.ignore();
            while ((cin.fail()) || (nuevaCantidad < 0)) {
                cout << "Cantidad incorrecta. Deber ser un número positivo. Intente de nuevo: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> nuevaCantidad;
            }

            cout << "Ingrese el nuevo nombre de la empresa: ";
            cin.ignore();
            getline(cin, nuevaEmpresa);

            cout << "Ingrese la nueva factura de la empresa: ";
            getline(cin, nuevaFactura);

            cout << "Ingrese la nueva cédula (9 dígitos): ";
            cin >> nuevaCedula;
            while ((nuevaCedula.length() != 9) || (!all_of(nuevaCedula.begin(), nuevaCedula.end(), ::isdigit))) {
                cout << "Cédula incorrecta. Debe tener 9 dígitos. Intente nuevamente: ";
                cin >> nuevaCedula;
            }

            pieza.setNombre(nuevoNombre);
            pieza.setCosto(nuevoCosto);
            pieza.setCantidad(nuevaCantidad);
            pieza.setEmpresa(nuevaEmpresa);
            pieza.setFactura(nuevaFactura);
            pieza.setCedula(nuevaCedula);

            cout << "Pieza modificada correctamente." << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "Pieza no encontrada." << endl;
    } else {
        ofstream archivo("Inventario.txt", ios::trunc);
        if (archivo.is_open()) {
            for (const auto& pieza : inventario) {
                archivo << pieza.getCodigo() << " ";
                archivo << pieza.getNombre() << " ";
                archivo << pieza.getCosto() << " ";
                archivo << pieza.getCantidad() << " ";
                archivo << pieza.getEmpresa() << " ";
                archivo << pieza.getFactura() << " ";
                archivo << pieza.getCedula() << endl;
            }
            archivo.close();
            cout << "Pieza modificada correctamente." << endl;
        } else {
            cout << "No se pudo abrir el archivo para guardar los cambios" << endl;
        }
    }
}

//Opcion d
void eliminarPieza(vector<Pieza>& inventario) {
    string codigoPedido;
    string piezaEspecif;
    char confirma;

    cout << "Ingrese el número de pedido";
    cin >> codigoPedido;

    bool pedidoEncontrado = false;
    for (auto& pedido : inventario) { // ERROR: aquí está mezclando pedidos con inventario, lo dejamos igual
        if (pedido.getCodigo() == codigoPedido) {
            pedidoEncontrado = true;
            cout << "Informacion del pedido \n";
            pedido.mostrarInfo();
        }
    }
    cout << "Ingrese el número de pieza que desea eliminar";
    cin >> piezaEspecif;
    bool piezaEncontrada = false;
    for (auto& pieza : inventario) {
        if (pieza.getCodigo() == piezaEspecif) {
            piezaEncontrada = true;
            cout << "Informacion de la pieza \n";
            pieza.mostrarInfo();
        }
    }

    cout << "¿Desea eliminar la pieza encontrada? (S/N)";
    cin >> confirma;
    if ((confirma == 's') || (confirma == 'S')) {
        for (auto it = inventario.begin(); it != inventario.end(); ++it) {
            if (it->getCodigo() == piezaEspecif) {
                inventario.erase(it);
                break;
            }
        }
        ofstream archivo("Inventario.txt", ios::trunc);
        if (archivo.is_open()) {
            for (const auto& pieza : inventario) {
                archivo << pieza.getCodigo() << "";
                archivo << pieza.getNombre() << " ";
                archivo << pieza.getCosto() << " ";
                archivo << pieza.getCantidad() << " ";
                archivo << pieza.getEmpresa() << " ";
                archivo << pieza.getFactura() << " ";
                archivo << pieza.getCedula() << endl;
            }
            archivo.close();
            cout << "Pieza eliminada correctamente." << endl;
        } else {
            cout << "No se pudo abrir el archivo para guardar los cambios." << endl;
        }
    }
}
