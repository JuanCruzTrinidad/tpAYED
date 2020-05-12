#pragma once

#ifndef FIGURA_H_INCLUDED
#define FIGURA_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Lista.h"
//#include "pch.h"

using namespace std;

//Definicion de Tipo de Estructura Circulo
typedef struct {
    string forma;
    string color;
    float valor1;
    float valor2;
    float area;
}Figura;

typedef Figura* PtrFigura;

/*
  PRE: la figura no debe haber sido creada.
  POST: figura queda creada y preparada para ser usada.

  figura: estructura de datos a ser creado.
*/
void crearFigura(PtrFigura& figura);

/* GETTERS Y SETTERS DE FIGURA */

string getForma(PtrFigura& figura);

void setForma(PtrFigura& figura, string forma);

string getColor(PtrFigura& figura);

void setColor(PtrFigura& figura, string color);

float getValor1(PtrFigura& figura);

void setValor1(PtrFigura& figura, float valor1);

float getValor2(PtrFigura& figura);

void setValor2(PtrFigura& figura, float valor2);


float convertirStringAFloat(string str); //Es valido crear un .h y .cpp funciones???

float calcularArea(string nombre, float valor, float valor2);

float calcularAreaTotal(Lista& listaFiguras);

void recorrerLista(Lista& listaFiguras);

void totalPorFigura(Lista& listaFiguras);

void CargarListaFiguras(Lista& listaFiguras, string forma, string color, float  valor1, float valor2);

void CargarDesdeArchivo(ifstream& Archivo, Lista& lista);


/*
  PRE: la lista listaFiguras debe haber sido creada y contener elementos.
  POST: se imprime la lista listaFiguras.

  listaFiguras: lista donde estan almacenadas las figuras.
*///

//																									void imprimirListaFiguras(Lista &listaFiguras);

/*
  PRE: la lista datos debe haber sido creada y contener elementos de tipo Figura, el string auxLinea debe contener
  una linea de un txt. Es "Simple" porque solo guarda el valor1.
  POST: se guarda la figura.

  auxLinea: string donde se almacena la linea extraida del archivo.
  datos: lista que contiene las figuras.
  nuevaFigura: Figura a ser insertada en la lista.
*/
//																							void guardarFiguraSimple(string auxLinea, Lista &datos, Figura* nuevaFigura);

/*
  PRE: la lista datos debe haber sido creada y contener elementos de tipo Figura, el string auxLinea debe contener
  una linea de un txt. Es "Compleja" porque guarda el valor1 y el valor2.
  POST: se guarda la figura.

  auxLinea: string donde se almacena la linea extraida del archivo.
  datos: lista que contiene las figuras.
  nuevaFigura: Figura a ser insertada en la lista.
*/
void guardarFiguraCompleja(string auxLinea, Lista& datos, Figura nuevaFigura);

#endif // FIGURA_H_INCLUDED

