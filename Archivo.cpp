#include "Archivo.h"
#include <iostream>
#include <fstream>
using namespace std;

void Archivo::escribir(string ubicacion) {
    ofstream archivo(ubicacion, ios::app);
    if (!archivo) {
        cout << "No se pudo abrir el archivo para escribir.\n";
        return;
    }
    string texto;
    do {
        cout << "Ingrese el texto que desea guardar en el archivo: ";
        getline(cin, texto);
        archivo << texto << "\n";
        cout << "¿Desea escribir mas texto en el archivo? (s/n): ";
        getline(cin, texto);
    } while (texto == "s" || texto == "S");
    archivo.close();
}

void Archivo::leer(string ubicacion) {
    ifstream archivo(ubicacion);
    if (!archivo) {
        cout << "No se pudo abrir el archivo para leer.\n";
        return;
    }
    string linea;
    while (getline(archivo, linea)) {
        cout << linea << "\n";
    }
    archivo.close();
}
