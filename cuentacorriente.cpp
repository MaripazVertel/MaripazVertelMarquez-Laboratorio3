#include "CuentaCorriente.h"
#include <iostream>
using namespace std;

CuentaCorriente::CuentaCorriente() : nombre(""), apellidos(""), direccion(""), telefono(""), saldo(0.0) {}

CuentaCorriente::CuentaCorriente(string nom, string ape, string dir, string tel, double sal)
    : nombre(nom), apellidos(ape), direccion(dir), telefono(tel), saldo(sal) {}

string CuentaCorriente::getNombre() {
    return nombre;
}

string CuentaCorriente::getApellidos() {
    return apellidos;
}

string CuentaCorriente::getDireccion() {
    return direccion;
}

string CuentaCorriente::getTelefono() {
    return telefono;
}

double CuentaCorriente::getSaldo() {
    return saldo;
}

void CuentaCorriente::setNombre(string nom) {
    nombre = nom;
}

void CuentaCorriente::setApellidos(string ape) {
    apellidos = ape;
}

void CuentaCorriente::setDireccion(string dir) {
    direccion = dir;
}

void CuentaCorriente::setTelefono(string tel) {
    telefono = tel;
}

void CuentaCorriente::retirarDinero(double cantidad) {
    saldo -= cantidad;
}

void CuentaCorriente::ingresarDinero(double cantidad) {
    saldo += cantidad;
}

void CuentaCorriente::consultarCuenta() {
    cout << "Nombre: " << nombre << "\n";
    cout << "Apellidos: " << apellidos << "\n";
    cout << "Direccion: " << direccion << "\n";
    cout << "Telefono: " << telefono << "\n";
    cout << "Saldo: " << saldo << "\n";
}

bool CuentaCorriente::saldoNegativo() {
    if (saldo < 0) {
        return true;
    } else {
        return false;
    }
}
