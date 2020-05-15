#define _USE_MATH_DEFINES
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

#include <cmath>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>     /* strtof */
#include <iomanip>

#include "Lista.h"
#include "Figura.h"

using namespace std;

/*
    Hay dos variables de datos numericos. Si la figura requiere que se use uno se usa uno, si require que se usen dos
    se usan dos.

    To Do:
    -PRE, POST, descripcion de logica.

    Se necesita saber de cada figura:
    -Tipo: Listo.
    -Color: Listo.
    -Cantidad de Plastico total: Listo.
    -Totales por Figura: Listo.
    -Totales por Figura-Color:
    -Dentro de Color mostrar el orden de las figuras:
    -Figuras ordenadas por el tamanio de sus areas:
*/

int main(int argc, char** argv) {

    Lista listaFiguras; // Lista donde voy a guardar las figuras.
    CrearLista(listaFiguras);   //constructor de la lista

    ifstream Archivo_figuras;
    Archivo_figuras.open("archivotest.txt", ios::in);   // Abro el archivo (solo leida)

    CargarDesdeArchivo(Archivo_figuras, listaFiguras);
    float areaTotal=0;
    recorrerLista(listaFiguras);  //Imprime la lista
    cout << endl;
    cout << "Area Total: " << calcularAreaTotal(listaFiguras) << endl;
    cout << endl;
    cout << "Totales por figura: " << endl;
    totalPorFigura(listaFiguras);
    Archivo_figuras.close();
    return 0;
}

