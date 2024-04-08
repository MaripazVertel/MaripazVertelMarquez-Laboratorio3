#ifndef CUENTACORRIENTE_H
#define CUENTACORRIENTE_H
#include <string>
using namespace std;

class CuentaCorriente {
private:
    string nombre, apellidos, direccion, telefono;
    double saldo;

public:

    CuentaCorriente();
    CuentaCorriente(string, string, string, string, double);


    string getNombre();
    string getApellidos();
    string getDireccion();
    string getTelefono();
    double getSaldo();

    void setNombre(string);
    void setApellidos(string);
    void setDireccion(string);
    void setTelefono(string);


    void retirarDinero(double);
    void ingresarDinero(double);
    void consultarCuenta();
    bool saldoNegativo();
};

#endif
