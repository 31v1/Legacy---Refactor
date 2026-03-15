#include "Validaciones.h"
#include <sstream>
using namespace std;

//Revisa que la fecha sea del tamaño adecuado
bool validarFecha(const string& fecha) {
    if (fecha.length() != 10)
        return false;
    if ((fecha[2] != '/') || (fecha[5] != '/'))
        return false;

    //Uso de la clase isstringsteam para extraer la informacion de la fecha
    int dia, mes, anho;
    char barra1, barra2;
    istringstream iss(fecha);
    iss >> dia >> barra1 >> mes >> barra2 >> anho;

    if ((iss.fail()) || (barra1 != '/') || (barra2 != '/'))
        return false;
    if ((dia < 1) || (dia > 31) || (mes < 1) || (mes > 12))
        return false;
    //Valida dias de meses de 30 dias
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
        return false;
    return true;
}
