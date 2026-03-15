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
    // Constructores
    Pieza();
    Pieza(string cod, string nom, double cost, int cant, 
          string emp, string fact, string ced);
    
    // Métodos
    void mostrarInfo() const;
    
    // Getters
    string getCodigo() const;
    string getNombre() const;
    double getCosto() const;
    int getCantidad() const;
    string getEmpresa() const;
    string getFactura() const;
    string getCedula() const;
    
    // Setters
    void setCodigo(string cod);
    void setNombre(string nom);
    void setCosto(double cost);
    void setCantidad(int cant);
    void setEmpresa(string emp);
    void setFactura(string fact);
    void setCedula(string ced);
};

#endif
