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
    -Totales por Figura-Color: Listo.
    -Dentro de Color mostrar el orden de las figuras:
    -Figuras ordenadas por el tamanio de sus areas: Casi Listo (falta en orden ascendiente).
*/

int main(int argc, char** argv) {

    Lista listaFiguras; // Lista donde voy a guardar las figuras.
    CrearLista(listaFiguras);   //constructor de la lista

    ifstream archivo_figuras;
    archivo_figuras.open("archivotest.txt", ios::in);   // Abro el archivo (solo leida)

    CargarDesdeArchivo(archivo_figuras, listaFiguras);
    cout << "Lista de Figuras: " << endl;
    recorrerLista(listaFiguras);  //Imprime la lista y calcula el area de las figuras.

    cout << endl;
    cout << "Area Total: " << calcularAreaTotal(listaFiguras) << endl;
    cout << endl;

    cout << "Totales por figura: " << endl;
    totalPorFigura(listaFiguras);

    cout << "Totales por figura-Color: " << endl;
    totalPorFiguraColor(listaFiguras);

    cout << "Orden areas descendente: " << endl;
    string archivo = "archivotest.txt";
    figurasDescendienteArea(archivo);

    archivo_figuras.close();
    return 0;
}

