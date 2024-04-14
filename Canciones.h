#include <iostream>
#include <string>
using namespace std;

class Duracion {
private:
    int minutos;
    int segundos;

public:
    Duracion(int m = 0, int s = 0) : minutos(m), segundos(s) {}

    int getMinutos() { return minutos; }
    int getSegundos() { return segundos; }

    void setMinutos(int m) { minutos = m; }
    void setSegundos(int s) { segundos = s; }
};

class Cancion {
private:
    string nombre;
    string artista;
    int anio;
    string genero;
    Duracion duracion;

public:
    Cancion(string n = "", string a = "", int y = 0, string g = "", Duracion d = Duracion()) : nombre(n), artista(a), anio(y), genero(g), duracion(d) {}

    string getNombre() { return nombre; }
    string getArtista() { return artista; }
    int getAnio() { return anio; }
    string getGenero() { return genero; }
    Duracion getDuracion() { return duracion; }

    void setNombre(string n) { nombre = n; }
    void setArtista(string a) { artista = a; }
    void setAnio(int y) { anio = y; }
    void setGenero(string g) { genero = g; }
    void setDuracion(Duracion d) { duracion = d; }
};
