#ifndef PIEZA_H
#define PIEZA_H

#include <string>
using namespace std;

class Pieza {
private:
    string codigo;
    string nombre;
    double costo;
    int cantidad;
    string empresa;
    string factura;
    string cedula;

public:
    //constructor con parametros
    Pieza(string cod, string nom, double cost, int cant, string emp, string fact, string ced);
    //Constructor por defecto
    Pieza();

    // mostrar informacion pieza
    void mostrarInfo();

    // Métodos 'get' y 'set' para cada atributo
    string getCodigo() const;
    void setCodigo(string cod);

    string getNombre() const;
    void setNombre(string nom);

    double getCosto() const;
    void setCosto(double cost);

    int getCantidad() const;
    void setCantidad(int cant);

    string getEmpresa() const;
    void setEmpresa(string emp);

    string getFactura() const;
    void setFactura(string fact);

    string getCedula() const;
    void setCedula(string ced);
};

#endif
