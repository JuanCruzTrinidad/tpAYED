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
  PRE: el archivo que contiene las figuras debe estar abierto y la lista debe estar inicializada.
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
  PRE: los valores pasados como parámetros tienen que tener relación con las figuras.
  POST: devuelve el area de la figura correspondiente.

  nombre: forma de la figura.
  valor1: valor1 de la figura.
  valor2: valor2 de la figura.
  return: el area correspondiente.

  Se compara el parametro nombre con una serie de if's. Si el nombre coincide con alguno entra y hace el calculo del
  area. Devuelve ese resultado.
*/
float calcularArea(string nombre, float valor1, float valor2);

/*
  PRE: la listaFiguras debe haber sido creada.
  POST: inserta el area de cada figura en la listaFiguras.

  listaFiguras: lista sobre la cual se invoca la primitiva.

  Se recorre la lista, se llama a calcularArea que devuelve el area y se inserta el dato en la figura correspondiente de
  la listaFiguras.
*/
void insertarArea(Lista& listaFiguras);

/*
  PRE: la listaFiguras debe haber sido creada.
  POST: se imprime la listaFiguras.

  listaFiguras: lista sobre la cual se invoca la primitiva.

  Primero se llama a insertarArea para que coloque el area en las respectivas figuras de la listaFiguras. Luego se
  recorre la lista y se imprime.
*/
void recorrerLista(Lista& listaFiguras);

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

/*
  PRE: la listaFiguras debe haber sido creada.
  POST: se imprimen las figuras con la cantidad que corresponde.

  listaFiguras: lista sobre la cual se invoca la primitiva.

  Se instancian dos arrays de tipo string: uno que contiene todas las formas posibles y otro de tamaño 10 que tendrá los
  colores. Se guardan los colores que hay en la listaFigura. Luego se recorre la lista de tal manera que se imprimen las
  figuras ordenadas por figura y color (recomendado ver el codigo para entender mejor).
*/
void totalPorFiguraColor(Lista& listaFiguras);

/*
  PRE:
  POST:

  listaFiguras:
  colores[10]:

  acavalalogica
*/
void coloresEnListaFiguras(Lista& listaFiguras, string colores[10]);

/*
  PRE: se debe tener un archivo de donde leer las figuras.
  POST: se muestran las figuras ordenadas por su area.

  archivo: .txt de donde se va a obtener las figuras.

  Lo que hacemos es crear una listaFigurasAux que vendría a ser lo mismo que la listaFigura pero en diferente lugar de memoria.
  Luego se recorre una serie de whiles donde se ordenan las figuras de mayor a menor. Finalmente se recorre la lista ordenada y se imprime.
*/
void ordenDescendenteArea(string archivo);

void ordenAscendenteArea(string archivo);

void colorOrdenFiguras (Lista& listaFiguras);

#endif // FIGURA_H_INCLUDED
