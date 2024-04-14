#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include "Canciones.h"
using namespace std;

const int MAX_CANCIONES = 100;
Cancion Canciones[MAX_CANCIONES];
int numCanciones = 0;

void imprimirCanciones() {
    for (int i = 0; i < numCanciones; i++) {
        cout << "Cancion " << i + 1 << ":" << endl;
        cout << "Nombre: " << Canciones[i].getNombre() << endl;
        cout << "Artista: " << Canciones[i].getArtista() << endl;
        cout << "Anio: " << Canciones[i].getAnio() << endl;
        cout << "Genero: " << Canciones[i].getGenero() << endl;
        cout << "Duracion: " << Canciones[i].getDuracion().getMinutos() << ":" << Canciones[i].getDuracion().getSegundos() << endl;
    }
}


void agregarCancion() {
    string nombre, artista, genero;
    int anio, minutos, segundos;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la nueva línea

    cout << "Ingrese nombre de la cancion: ";
    getline(cin, nombre);
    cout << "Ingrese nombre del artista: ";
    getline(cin, artista);
    cout << "Ingrese anio: ";
    cin >> anio;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la nueva línea
    cout << "Ingrese genero: ";
    getline(cin, genero);
    cout << "Ingrese duracion (minutos): ";
    cin >> minutos;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la nueva línea
    cout << "Ingrese duracion (segundos): ";
    cin >> segundos;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la nueva línea

    Cancion nuevaCancion(nombre, artista, anio, genero, Duracion(minutos, segundos));
    Canciones[numCanciones++] = nuevaCancion;
}



void eliminarCancion() {
    int indice;
    cout << "Ingrese el indice de la cancion a eliminar: ";
    cin >> indice;

    cout << "Canciones antes de eliminar:\n";
    imprimirCanciones();

    for (int i = indice; i < numCanciones - 1; i++) {
        Canciones[i] = Canciones[i + 1];
    }
    numCanciones--;

    cout << "Canciones despues de eliminar:\n";
    imprimirCanciones();
}


void ordenarCanciones() {
    int opcion;
    cout << "Elija el criterio de ordenamiento:\n";
    cout << "1. Nombre\n";
    cout << "2. Artista\n";
    cout << "3. Anio de lanzamiento\n";
    cout << "4. Duracion\n";
    cin >> opcion;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    for (int i = 0; i < numCanciones - 1; i++) {
        for (int j = 0; j < numCanciones - i - 1; j++) {
            bool swap = false;
            switch (opcion) {
                case 1: // Ordenar por nombre
                    swap = Canciones[j].getNombre() > Canciones[j + 1].getNombre();
                    break;
                case 2: // Ordenar por artista
                    swap = Canciones[j].getArtista() > Canciones[j + 1].getArtista();
                    break;
                case 3: // Ordenar por año de lanzamiento
                    swap = Canciones[j].getAnio() > Canciones[j + 1].getAnio();
                    break;
                case 4: { // Ordenar por duración
                    int durationJ = Canciones[j].getDuracion().getMinutos() * 60 + Canciones[j].getDuracion().getSegundos();
                    int durationJPlus1 = Canciones[j + 1].getDuracion().getMinutos() * 60 + Canciones[j + 1].getDuracion().getSegundos();
                    swap = durationJ > durationJPlus1;
                    break;
                }
                default:
                    cout << "Opcion no valida. Intente de nuevo.\n";
                    return;
            }
            if (swap) {
                Cancion temp = Canciones[j];
                Canciones[j] = Canciones[j + 1];
                Canciones[j + 1] = temp;
            }
        }
    }

    imprimirCanciones();
}


void cambiarCancion() {
    int indice;

    cout << "Ingrese indice de la cancion a cambiar: ";
    cin >> indice;

    if (indice >= 0 && indice < numCanciones) {
        cout << "Seleccione el atributo que desea cambiar:\n";
        cout << "1. Nombre\n";
        cout << "2. Artista\n";
        cout << "3. Anio de lanzamiento\n";
        cout << "4. Genero\n";
        cout << "5. Duracion\n";

        int opcion;
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1: {
                string nuevoNombre;
                cout << "Ingrese el nuevo nombre de la cancion: ";
                getline(cin, nuevoNombre);
                Canciones[indice].setNombre(nuevoNombre);
                break;
            }
            case 2: {
                string nuevoArtista;
                cout << "Ingrese el nuevo nombre del artista: ";
                getline(cin, nuevoArtista);
                Canciones[indice].setArtista(nuevoArtista);
                break;
            }
            case 3: {
                int nuevoAnio;
                cout << "Ingrese el nuevo anio de lanzamiento: ";
                cin >> nuevoAnio;
                Canciones[indice].setAnio(nuevoAnio);
                break;
            }
            case 4: {
                string nuevoGenero;
                cout << "Ingrese el nuevo genero de la cancion: ";
                getline(cin, nuevoGenero);
                Canciones[indice].setGenero(nuevoGenero);
                break;
            }
            case 5: {
                int nuevosMinutos, nuevosSegundos;
                cout << "Ingrese la nueva duracion en minutos: ";
                cin >> nuevosMinutos;
                cout << "Ingrese la nueva duracion en segundos: ";
                cin >> nuevosSegundos;
                Canciones[indice].setDuracion(Duracion(nuevosMinutos, nuevosSegundos));
                break;
            }
            default:
                cout << "Opcion no valida.\n";
                break;
        }
    } else {
        cout << "Indice de cancion fuera de rango.\n";
    }
}


void leerArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo + ".txt");

    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para leer." << endl;
    }
}

void guardarEnArchivo() {
    string nombreArchivo;
    cout << "Ingrese el nombre del archivo para guardar: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la nueva línea
    getline(cin, nombreArchivo);

    ofstream archivo(nombreArchivo + ".txt"); // Abre el archivo en modo de escritura

    if (archivo.is_open()) {
        for (int i = 0; i < numCanciones; i++) {
            archivo << "Cancion " << i + 1 << ":\n";
            archivo << "Nombre: " << Canciones[i].getNombre() << "\n";
            archivo << "Artista: " << Canciones[i].getArtista() << "\n";
            archivo << "Anio: " << Canciones[i].getAnio() << "\n";
            archivo << "Genero: " << Canciones[i].getGenero() << "\n";
            archivo << "Duracion: " << Canciones[i].getDuracion().getMinutos() << ":" << Canciones[i].getDuracion().getSegundos() << "\n";
            archivo << "\n"; // Linea en blanco entre cada canción
        }
        archivo.close();
        cout << "Se ha guardado exitosamente en " << nombreArchivo << ".txt\n";
    } else {
        cout << "No se pudo abrir el archivo para guardar.\n";
    }
    leerArchivo(nombreArchivo);
}

void cargarDeArchivo() {

}
