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

/*
  Definicion de tipo de estructura Figura
*/
typedef struct {
    string forma;
    string color;
    float valor1;
    float valor2;
    float area;
}Figura;

/*
  
*/
typedef Figura* PtrFigura;

/*
  PRE: la figura no debe haber sido creada.
  POST: figura queda creada y preparada para ser usada.

  figura: estructura de datos a ser creada.
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

/*
  PRE:
  POST:

  Archivo:
  lista:

  acavalalogica
*/
void CargarDesdeArchivo(ifstream& Archivo, Lista& lista);

/*
  PRE:
  POST:

  listaFiguras:
  forma:
  color:
  valor1:
  valor2:

  acavalalogica
*/
void CargarListaFiguras(Lista& listaFiguras, string forma, string color, float valor1, float valor2);

/*
  PRE: el string a convertir debe contener solo numeros.
  POST: devuelve str convertido en un dato tipo float.

  str: string a convertir a float.
  return: el float convertido.

  Primero tomamos un string llamado str. Luego nos fijamos si contiene una coma(,). Si no la contiene se 
  transforma en float y sale. Si la contiene reemplaza la coma por un punto, lo transforma en float y sale.
*/
float convertirStringAFloat(string str); //Es valido crear un .h y .cpp funciones???

/*
  PRE:
  POST:

  listaFiguras:

  acavalalogica
*/
void recorrerLista(Lista& listaFiguras);

/*
  PRE: 
  POST:

  nombre:
  valor1:
  valor2:
  return:

  acavalalogica
*/
float calcularArea(string nombre, float valor1, float valor2);

/*
  PRE: la listaFiguras debe haber sido creada.
  POST: devuelve el area total de las figuras que se encuentran en la lista.

  listaFiguras: lista sobre la cual se invoca la primitiva.
  return: float que contiene el areaTotal.

  Se inicializa un cursor en el primer elemento de la lista. Este cursor va a recorrer toda la lista hasta que termine.
  Mientras el cursor recorre la lista se van sumando las areas de las figuras.
*/
float calcularAreaTotal(Lista& listaFiguras);

/*
  PRE: la listaFiguras debe haber sido creada.
  POST: se imprimen las figuras con la cantidad que corresponde.

  listaFiguras: lista sobre la cual se invoca la primitiva.

  Se inicializa un cursor en el primer elemento de la lista y un array del tipo string que contiene todas las formas
  posibles. Se hace un ciclo for que funciona como recorredor del array figuras, y dentro se recorre toda la lista
  con el cursor.
  Si la forma de la figura actual coincide con la figura de figuras[] se suma 1 al contador. Cuando termina de recorrer
  la lista se imprime la figura correspondiente a figuras[] y la cantidad de veces que aparecio.
*/
void totalPorFigura(Lista& listaFiguras);

void totalPorFiguraColor(Lista& listaFiguras);

void coloresEnListaFiguras(Lista& listaFiguras, string colores[10]);

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
//void guardarFiguraCompleja(string auxLinea, Lista& datos, Figura nuevaFigura);

#endif // FIGURA_H_INCLUDED

