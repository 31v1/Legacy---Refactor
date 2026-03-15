#include "Pieza.h"
#include <iostream>
using namespace std;

//constructor con parametros
Pieza::Pieza(string cod, string nom, double cost, int cant, string emp, string fact, string ced) {
    codigo = cod;
    nombre = nom;
    costo = cost;
    cantidad = cant;
    empresa = emp;
    factura = fact;
    cedula = ced;
}

//Constructor por defecto
Pieza::Pieza() {}

// mostrar informacion pieza
void Pieza::mostrarInfo() {
    cout << "Pieza con "
         << "Código: " << codigo << ", "
         << "Nombre: " << nombre << ", "
         << "Costo: " << costo << ", "
         << "Cantidad: " << cantidad << ", "
         << "Empresa: " << empresa << ", "
         << "Factura: " << factura << ", "
         << "Cédula: " << cedula << ", " << endl;
}

// Métodos 'get' y 'set' para cada atributo
string Pieza::getCodigo() const { return codigo; }
void Pieza::setCodigo(string cod) { codigo = cod; }

string Pieza::getNombre() const { return nombre; }
void Pieza::setNombre(string nom) { nombre = nom; }

double Pieza::getCosto() const { return costo; }
void Pieza::setCosto(double cost) { costo = cost; }

int Pieza::getCantidad() const { return cantidad; }
void Pieza::setCantidad(int cant) { cantidad = cant; }

string Pieza::getEmpresa() const { return empresa; }
void Pieza::setEmpresa(string emp) { empresa = emp; }

string Pieza::getFactura() const { return factura; }
void Pieza::setFactura(string fact) { factura = fact; }

string Pieza::getCedula() const { return cedula; }
void Pieza::setCedula(string ced) { cedula = ced; }
