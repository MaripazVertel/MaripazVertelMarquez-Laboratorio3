#ifndef BUSCADOR_TEXTO_H
#define BUSCADOR_TEXTO_H
#include <string>
using namespace std;

class BuscadorTexto {
public:
    BuscadorTexto(const string &nombreArchivo);
    void buscarCaracter(const char &caracter);
    void buscarSecuencia(const string &secuencia);
    void buscarRepeticiones(const string &item, int repeticiones);
    void escribirResultados(const string &nombreArchivo) const;

private:
    string texto;
    char resultados[100][100]; // Arreglo para almacenar los resultados
    int contadorResultados;
};

#endif
