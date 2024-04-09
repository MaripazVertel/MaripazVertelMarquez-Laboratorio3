#include "BuscadorTexto.h"
#include <fstream>
#include <iostream>
#include <algorithm>

BuscadorTexto::BuscadorTexto(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo);
    contadorResultados = 0; // Inicializar contador de resultados
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            texto += linea;
            texto += '\n';
        }
        archivo.close();
    } else {
        cerr << "Error: No se pudo abrir el archivo." << endl;
    }
}

void BuscadorTexto::buscarCaracter(const char &caracter) {
    int contador = 0;
    char caracterLowerCase = tolower(caracter); // Convertir a minúscula
    for (char c : texto) {
        if (tolower(c) == caracterLowerCase) { // Convertir el carácter actual a minúscula para comparar
            contador++;
        }
    }
    sprintf(resultados[contadorResultados++], "El carácter '%c' se repite %d veces en el texto.", caracter, contador);
}

void BuscadorTexto::buscarSecuencia(const string &secuencia) {
    string secuenciaLowerCase = secuencia;
    transform(secuenciaLowerCase.begin(), secuenciaLowerCase.end(), secuenciaLowerCase.begin(), ::tolower); // Convertir la secuencia a minúscula
    size_t pos = texto.find(secuenciaLowerCase);
    int contador = 0;
    while (pos != string::npos) {
        contador++;
        pos = texto.find(secuenciaLowerCase, pos + 1);
    }
    sprintf(resultados[contadorResultados++], "La secuencia \"%s\" se repite %d veces en el texto.", secuencia.c_str(), contador);
}

void BuscadorTexto::buscarRepeticiones(const string &item, int repeticiones) {
    size_t pos = 0;
    int contador = 0;
    while ((pos = texto.find(item, pos)) != string::npos) {
        contador++;
        if (contador == repeticiones) {
            sprintf(resultados[contadorResultados++], "La secuencia \"%s\" se repite %d veces en el texto.", item.c_str(), contador);
            break;
        }
        pos += item.length();
    }
}

void BuscadorTexto::escribirResultados(const string &nombreArchivo) const {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (int i = 0; i < contadorResultados; ++i) {
            archivo << resultados[i] << endl;
        }
        archivo.close();
        cout << "Resultados escritos en el archivo: " << nombreArchivo << endl;

        // Ahora, abrimos el archivo y mostramos su contenido
        ifstream archivoMostrar(nombreArchivo);
        if (archivoMostrar.is_open()) {
            string linea;
            cout << "Contenido del archivo:" << endl;
            while (getline(archivoMostrar, linea)) {
                cout << linea << endl;
            }
            archivoMostrar.close();
        } else {
            cerr << "Error: No se pudo abrir el archivo para mostrar su contenido." << endl;
        }
    } else {
        cerr << "Error: No se pudo abrir el archivo de salida." << endl;
    }
}
