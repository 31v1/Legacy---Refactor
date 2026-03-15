#include "Pedido.h"
#include <iostream>
using namespace std;

// Constructor por defecto
Pedido::Pedido() {}

// Constructor con parámetros
Pedido::Pedido(string cod, string codPieza, int cant, string idEmpleado, 
               string fechaSoli, string estad) {
    codigo = cod;
    codigoPieza = codPieza;
    cantidad = cant;
    identificacionEmpleado = idEmpleado;
    fechaSolicitud = fechaSoli;
    estado = estad;
}

// Mostrar información
void Pedido::mostrarInfo() const {
    cout << "Código de pedido: " << codigo << endl;
    cout << "Código de pieza: " << codigoPieza << endl;
    cout << "Cantidad: " << cantidad << endl;
    cout << "Cédula empleado: " << identificacionEmpleado << endl;
    cout << "Fecha solicitud: " << fechaSolicitud << endl;
    cout << "Estado: " << estado << endl;
    cout << "------------------------" << endl;
}

// Getters
string Pedido::getCodigo() const { return codigo; }
string Pedido::getCodigoPieza() const { return codigoPieza; }
int Pedido::getCantidad() const { return cantidad; }
string Pedido::getIdentificacionEmpleado() const { return identificacionEmpleado; }
string Pedido::getFechaSolicitud() const { return fechaSolicitud; }
string Pedido::getEstado() const { return estado; }

// Setters
void Pedido::setCodigo(string cod) { codigo = cod; }
void Pedido::setCodigoPieza(string codPieza) { codigoPieza = codPieza; }
void Pedido::setCantidad(int cant) { cantidad = cant; }
void Pedido::setIdentificacionEmpleado(string idEmpleado) { identificacionEmpleado = idEmpleado; }
void Pedido::setFechaSolicitud(string fechaSoli) { fechaSolicitud = fechaSoli; }
void Pedido::setEstado(string estad) { estado = estad; }
