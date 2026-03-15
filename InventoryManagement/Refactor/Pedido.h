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
    // Constructores
    Pedido();
    Pedido(string cod, string codPieza, int cant, string idEmpleado, 
           string fechaSoli, string estad);
    
    // Métodos
    void mostrarInfo() const;
    
    // Getters
    string getCodigo() const;
    string getCodigoPieza() const;
    int getCantidad() const;
    string getIdentificacionEmpleado() const;
    string getFechaSolicitud() const;
    string getEstado() const;
    
    // Setters
    void setCodigo(string cod);
    void setCodigoPieza(string codPieza);
    void setCantidad(int cant);
    void setIdentificacionEmpleado(string idEmpleado);
    void setFechaSolicitud(string fechaSoli);
    void setEstado(string estad);
};

#endif
