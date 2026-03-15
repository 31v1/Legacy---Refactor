#include "Pedido.h"
#include <iostream>
using namespace std;

//constructores
Pedido::Pedido(string cod, string codPieza, int cant, string idEmpleado, string fechaSoli, string estad) {
    codigo = cod;
    codigoPieza = codPieza;
    cantidad = cant;
    identificacionEmpleado = idEmpleado;
    fechaSolicitud = fechaSoli;
    estado = estad;
}

Pedido::Pedido() {}

// Métodos 'get' y 'set' para cada atributo
string Pedido::getCodigo() const { return codigo; }
void Pedido::setCodigo(string cod) { codigo = cod; }

string Pedido::getCodigoPieza() const { return codigoPieza; }
void Pedido::setCodigoPieza(string codPieza) { codigoPieza = codPieza; }

int Pedido::getCantidad() const { return cantidad; }
void Pedido::setCantidad(int cant) { cantidad = cant; }

string Pedido::getFechaSolicitud() const { return fechaSolicitud; }
void Pedido::setFechaSolicitud(string fechaSoli) { fechaSolicitud = fechaSoli; }

string Pedido::getIdentificacionEmpleado() const { return identificacionEmpleado; }
void Pedido::setIdentificacionEmpleado(string idEmpleado) { identificacionEmpleado = idEmpleado; }

string Pedido::getEstado() const { return estado; }
void Pedido::setEstado(string estad) { estado = estad; }
