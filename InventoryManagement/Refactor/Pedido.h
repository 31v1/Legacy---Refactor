#ifndef PEDIDO_H
#define PEDIDO_H

#include <string>
using namespace std;

class Pedido {
private:
    string codigo;
    string codigoPieza;
    int cantidad;
    string identificacionEmpleado;
    string fechaSolicitud;
    string estado;

public:
    //constructores
    Pedido(string cod, string codPieza, int cant, string idEmpleado, string fechaSoli, string estad);
    Pedido();

    // Métodos 'get' y 'set' para cada atributo
    string getCodigo() const;
    void setCodigo(string cod);

    string getCodigoPieza() const;
    void setCodigoPieza(string codPieza);

    int getCantidad() const;
    void setCantidad(int cant);

    string getFechaSolicitud() const;
    void setFechaSolicitud(string fechaSoli);

    string getIdentificacionEmpleado() const;
    void setIdentificacionEmpleado(string idEmpleado);

    string getEstado() const;
    void setEstado(string estad);
};

#endif
