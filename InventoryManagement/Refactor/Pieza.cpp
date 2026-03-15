#include "Pieza.h"
#include <iostream>
using namespace std;

// Constructor por defecto
Pieza::Pieza() {}

// Constructor con parámetros
Pieza::Pieza(string cod, string nom, double cost, int cant, 
             string emp, string fact, string ced) {
    codigo = cod;
    nombre = nom;
    costo = cost;
    cantidad = cant;
    empresa = emp;
    factura = fact;
    cedula = ced;
}

// Mostrar información
void Pieza::mostrarInfo() const {
    cout << "Código: " << codigo << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Costo: " << costo << endl;
    cout << "Cantidad: " << cantidad << endl;
    cout << "Empresa: " << empresa << endl;
    cout << "Factura: " << factura << endl;
    cout << "Cédula quien ingresa: " << cedula << endl;
    cout << "------------------------" << endl;
}

// Getters
string Pieza::getCodigo() const { return codigo; }
string Pieza::getNombre() const { return nombre; }
double Pieza::getCosto() const { return costo; }
int Pieza::getCantidad() const { return cantidad; }
string Pieza::getEmpresa() const { return empresa; }
string Pieza::getFactura() const { return factura; }
string Pieza::getCedula() const { return cedula; }

// Setters
void Pieza::setCodigo(string cod) { codigo = cod; }
void Pieza::setNombre(string nom) { nombre = nom; }
void Pieza::setCosto(double cost) { costo = cost; }
void Pieza::setCantidad(int cant) { cantidad = cant; }
void Pieza::setEmpresa(string emp) { empresa = emp; }
void Pieza::setFactura(string fact) { factura = fact; }
void Pieza::setCedula(string ced) { cedula = ced; }
