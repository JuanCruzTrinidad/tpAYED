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
    -Tratar de laburar con el constructor, con los gets y los sets.
    -PRE, POST, descripcion de logica.

    Se necesita saber de cada figura:
    -Tipo: Listo.
    -Color: Listo.
    -Cantidad de Plastico: No.
*/


/*Recorro la lista e imprimo */

void recorrer(Lista& lista) {
    PtrNodoLista cursor = lista.Primero;
    while (cursor != Fin_Lista()) {
        cout << ((Figura*)cursor->DatoLista)->forma << " ";
        cout << ((Figura*)cursor->DatoLista)->color << " ";
        cout << ((Figura*)cursor->DatoLista)->valor1 << "; ";
        if (((Figura*)cursor->DatoLista)->valor2 > 0) {
            cout << ((Figura*)cursor->DatoLista)->valor2 << " ";
        }
        cout << endl;
        cout << calcularArea(((Figura*)cursor->DatoLista)->forma, ((Figura*)cursor->DatoLista)->valor1, ((Figura*)cursor->DatoLista)->valor2) << endl;
        cursor = cursor->SgteDL;
    }
    delete (cursor);
}

/*Cargo uno a uno los valores mediante los Set */
void CargarLista(Lista& listaFiguras, string forma, string color, float  valor1, float valor2)
{
    PtrFigura nuevo;
    crearFigura(nuevo);
    setForma(nuevo, forma);
    setColor(nuevo, color);
    setValor1(nuevo, valor1);
    if (valor2 != 0) {
     setValor2(nuevo, valor2);
    }
    else {
        setValor2(nuevo, 0);
    }
    AdicionarFinal(listaFiguras, nuevo);
    /* delete (nuevo);*/
}

void CargarDesdeArchivo(ifstream& Archivo, Lista& Lista)
{

    string linea, Dato2, Dato1, Dato3, Dato4;

    while (!Archivo.eof())
    {
        string Dato1  = Dato3 = Dato2 = Dato4 = "";
        float a, b = 0.0;
        int separador = 0;
        string aux;
        getline(Archivo, linea);
        for (int i = 0; i < linea.size(); i++)
        {
            if (linea.at(i) == ' ')
                separador++;
            else
            {
                if (separador == 0)
                    Dato1 = Dato1 + linea.at(i);
                if (separador == 1)
                    Dato2 = Dato2 + linea.at(i);
                if (separador == 2)
                    aux = linea.at(i);
                    Dato3.append(aux);
                    aux = "";
            }
            if (linea.at(i) == ';'){
                i++;
                while (linea.size() > i)
                {
                    aux = linea.at(i);
                    Dato4.append(aux);
                    i++;
                }
                }
            
        }
        a = convertirStringAFloat(Dato3);
        if (Dato4.size() > 0) {
            b = convertirStringAFloat(Dato4);
        }
        CargarLista(Lista, Dato1, Dato2, a, b);
    }
}


int main(int argc, char** argv) {

    Lista listaFiguras; 															// Lista donde voy a guardar las figuras.
    CrearLista(listaFiguras);														//constructor de la lista

    ifstream Archivo_figuras;
    Archivo_figuras.open("archtest.txt", ios::in); 									// Abro el archivo (solo leida)

    CargarDesdeArchivo(Archivo_figuras, listaFiguras);
    recorrer(listaFiguras); 														//Imprime la lista
    Archivo_figuras.close();
    return 0;
}

