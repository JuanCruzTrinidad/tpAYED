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
} Figura;

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

/*CargarDesdeArchivo¨:¨
    PRE : Necesitamos el archivo cargado con el formato que fue especificado
    POST: Separa los datos de la linea, para poder pasarlo por parametro a CargarListaFiguras

    Leemos la linea completa y vamos haciendo una separacion por cada dato que se encuentra en ella. Estos datos se van asignando a variables.
    que son las que se enviaran por parametro a la siguiente funcion.
*/
void CargarDesdeArchivo(ifstream& Archivo, Lista& lista);


/*CargarListaFiguras:
    PRE :Necesitamos las variables cargadas con los datos de cada linea.
    POST:Devuelve una lista cargada con los datos que se obtuvieraon

    Recibe las variables cargadas con los datos y las va incorporando mediante el bucle a la lista.
*/
void CargarListaFiguras(Lista& listaFiguras, string forma, string color, float valor1, float valor2);


/*  convertirStringAFloat
    PRE: el string a convertir debe contener solo numeros.
    POST: devuelve str convertido en un dato tipo float.

    str: string a convertir a float.
    return: el float convertido.

    Primero tomamos un string llamado str. Luego nos fijamos si contiene una coma(,). Si no la contiene se
    transforma en float y sale. Si la contiene reemplaza la coma por un punto, lo transforma en float y sale.
*/
float convertirStringAFloat(string str);


/*  calcularArea
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


/*insertarArea
    PRE: la listaFiguras debe haber sido creada.
    POST: inserta el area de cada figura en la listaFiguras.

    listaFiguras: lista sobre la cual se invoca la primitiva.

    Se recorre la lista, llamando a calcularArea que devuelve el area de cada figura, y se inserta el dato en la
    figura correspondiente de la listaFiguras.
*/
void insertarArea(Lista& listaFiguras);


/*  imprimirFiguras
    PRE: la listaFiguras debe haber sido creada.
    POST: se imprime la listaFiguras.

    Recorre la lista y se imprime.
*/
void imprimirFiguras(Lista& listaFiguras);


/*  calcularAreaTotal
    PRE: la listaFiguras debe haber sido creada.
    POST: devuelve el area total de las figuras que se encuentran en la lista.

    listaFiguras: lista sobre la cual se invoca la primitiva.
    return: float que contiene el areaTotal.

    Se inicializa un cursor en el primer elemento de la lista. Este cursor va a recorrer toda la lista hasta que termine.
    Mientras el cursor recorre la lista se van sumando las areas de las figuras.
*/
float calcularAreaTotal(Lista& listaFiguras);


/*  totalPorFigura
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


/*totalPorFiguraColor
    PRE: la listaFiguras debe haber sido creada.
    POST: se imprimen las figuras con la cantidad que corresponde.

    listaFiguras: lista sobre la cual se invoca la primitiva.

    Se instancian dos arrays de tipo string: uno que contiene todas las formas posibles y otro de tamaño 10 que tendrá los
    colores. Se guardan los colores que hay en la listaFigura. Luego se recorre la lista de tal manera que se imprimen las
    figuras ordenadas por figura y color (recomendado ver el codigo para entender mejor).
*/
void totalPorFiguraColor(Lista& listaFiguras);



/*  coloresEnListaFiguras
    PRE: la lista de figuras debe haber sido creada
    POST: carga en un array de string los colores existentes

    Recibe por parametro la lista de Figuras y un array de String llamado colores
    Busca los colores que existen en la lista y los coloca en un array sin repetir
*/
void coloresEnListaFiguras(Lista& listaFiguras, string colores[10]);



/*  ordenDescendenteArea:
    PRE: la lista de figuras debe haber sido creada
    POST: se muestran las figuras ordenadas descendente por area

    Recibe por parametro el archivo, lo carga a una lista auxiliar,
    luego se calcula el area de todas las figuras para poder ordenarlas
    se ordena la lista por el metodo de burbuja
    luego imprime la lista ordenada de forma descendente
*/
void ordenDescendenteArea(string archivo);


/*  ordenAscendenteArea:
    PRE: la lista de figuras debe haber sido creada
    POST: se muestran las figuras ordenadas ascendente por area

    Recibe por parametro el archivo, lo carga a una lista auxiliar,
    luego se calcula el area de todas las figuras para poder ordenarlas
    se ordena la lista por el metodo de burbuja
    luego imprime la lista ordenada de forma ascendente
*/
void ordenAscendenteArea(string archivo);


/*  colorOrdenFiguras:
	PRE: la lista debe haber sido creada
	POST: la funcion debe imprimir por cada color, las figuras en orden de produccion

    Dentro de cada color mostrar el orden de produccion de las figuras
    Recibe por parametro la direccion de la lista de figuras,
    se genera un array con todas las opciones de colores existentes en la lista
    Por cada color, imprime la figura correspondiente y su orden de llegada
*/
void colorOrdenFiguras (Lista& listaFiguras);


#endif // FIGURA_H_INCLUDED
