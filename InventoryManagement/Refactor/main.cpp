#include <iostream>
#include <clocale>
#include <vector>
#include "Pieza.h"
#include "Pedido.h"
#include "Inventario.h"

using namespace std;

void mostrarMenu() {
    cout << "\n=== SISTEMA ASADAS ===\n";
    cout << "1. Inventario\n";
    cout << "2. Pedido\n";
    cout << "3. Reporte de Inventario\n";
    cout << "4. Reporte de Pedidos\n";
    cout << "6. Salir\n";
    cout << "Ingrese una opción: ";
}

int main() {
    setlocale(LC_ALL, "spanish");
    
    vector<Pieza> inventario;  // Aquí cargaremos desde archivo después
    vector<Pedido> pedidos;     // Aquí cargaremos desde archivo después
    
    int opcion;
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch(opcion) {
            case 1: {
                char subopcion;
                cout << "\na. Ingresar pieza\n";
                cout << "b. Consultar pieza\n";
                cout << "c. Modificar pieza\n";
                cout << "d. Eliminar pieza\n";
                cout << "Ingrese una opción: ";
                cin >> subopcion;
                
                switch(subopcion) {
                    case 'a':
                        ingresarPieza(inventario);
                        break;
                    case 'b':
                        consultarPieza(inventario);
                        break;
                    case 'c':
                        modificarPieza(inventario);
                        break;
                    case 'd':
                        eliminarPieza(inventario);
                        break;
                    default:
                        cout << "Opción inválida\n";
                }
                break;
            }
            case 2:
                cout << "Módulo de pedidos - En desarrollo\n";
                break;
            case 3:
                cout << "Reporte de inventario - En desarrollo\n";
                break;
            case 4:
                cout << "Reporte de pedidos - En desarrollo\n";
                break;
            case 6:
                cout << "Guardando datos y saliendo...\n";
                break;
            default:
                cout << "Opción inválida\n";
        }
        
    } while(opcion != 6);
    
    return 0;
}
