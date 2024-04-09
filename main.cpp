#include "CuentaCorriente.h"
#include "Problemas.h"
#include "Archivo.h"
#include <iostream>
using namespace std;

int main() {

    int opcion;
    CuentaCorriente cuenta;

    bool continueCuentaCorriente = true;

    while (continueCuentaCorriente) {
        cout << "Bienvenido al programa principal.\n";
        cout << "Por favor, seleccione una opcion:\n";
        cout << "1. Cuenta Corriente\n";
        cout << "2. Escribir o leer archivo\n";
        cout << "3. Busque un caracter o una secuencia de texto\n";
        cout << "4. Codificacion de un mensaje\n";
        cout << "5. Almacenar informacion de una cancion\n";
        cout << "6. Salir\n";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Problema p;
                p.resolverProblema();
                int opc;
                double cantidad;

                cout << "Bienvenido al programa de Cuenta Corriente.\n";
                cout << "Por favor, seleccione una opcion:\n";
                cout << "1. Ingresar datos de la cuenta.\n";
                cout << "2. Continuar con datos definidos.\n";
                cin >> opc;

                if (opc == 1) {
                    string nombre, apellidos, direccion, telefono;
                    double saldo;

                    cout << "Introduzca su nombre: ";
                    cin >> nombre;
                    cout << "Introduzca sus apellidos: ";
                    cin >> apellidos;
                    cout << "Introduzca su direccion: ";
                    cin.ignore();
                    getline(cin, direccion);
                    cout << "Introduzca su telefono: ";
                    cin >> telefono;
                    cout << "Introduzca su saldo: ";
                    cin >> saldo;

                    cuenta = CuentaCorriente(nombre, apellidos, direccion, telefono, saldo);
                }

                do {
                    cout << "\nSeleccione una opcion:\n";
                    cout << "1. Ingresar dinero.\n";
                    cout << "2. Retirar dinero.\n";
                    cout << "3. Consultar cuenta.\n";
                    cout << "4. Verificar saldo negativo.\n";
                    cout << "5. Salir.\n";
                    cin >> opc;

                    switch (opc) {
                        case 1:
                            cout << "Introduzca la cantidad a ingresar: ";
                            cin >> cantidad;
                            cuenta.ingresarDinero(cantidad);
                            break;
                        case 2:
                            cout << "Introduzca la cantidad a retirar: ";
                            cin >> cantidad;
                            cuenta.retirarDinero(cantidad);
                            break;
                        case 3:
                            cuenta.consultarCuenta();
                            break;
                        case 4:
                            if (cuenta.saldoNegativo()) {
                                cout << "La cuenta se encuentra en numeros rojos.\n";
                            } else {
                                cout << "La cuenta no esta en numeros rojos.\n";
                            }
                            break;
                        case 5:
                            cout << "Hasta luego!\n";
                            continueCuentaCorriente = false;
                            break;
                        default:
                            cout << "Opcion no valida.\n";
                    }
                } while (opc != 5);

                break;
            }
            case 2: {
                Problema2 p;
                p.resolverProblema2();
                Archivo archivo;
                string ubicacion;
                string opcion;

                cout << "Ingrese la ubicacion del archivo: ";
                getline(cin, ubicacion);
                getline(cin, ubicacion);
                cout << "Desea escribir o leer el archivo? (e/l): ";
                getline(cin, opcion);

                if (opcion == "e" || opcion == "E") {
                    archivo.escribir(ubicacion);
                } else if (opcion == "l" || opcion == "L") {
                    archivo.leer(ubicacion);
                } else {
                    cout << "Opcion no valida.\n";
                }
                break;
            }

            case 3: {

                break;
            }
            case 4: {

                break;
            }
            case 5: {

                break;
            }
            case 6: {
                cout << "Hasta luego!.\n";
                break;
            }
        }
    }

    return 0;
}
