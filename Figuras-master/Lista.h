#pragma once

#ifndef NULL
#define NULL 0
#endif // NULL
#ifndef __LISTA_H__
#define __LISTA_H__

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

/*
  Tipo de informacion que esta contenida en los nodos de la lista,
  identificada como DatoLista.
*/
typedef void* PtrDatoLista;

/*
  Tipo de estructura de los nodos de la lista.
*/
struct NodoLista
{
    PtrDatoLista DatoLista;
    NodoLista* SgteDL;
};

/*
  Tipo de puntero a los nodos de la lista, el cual se usa para recorrer
  la lista y acceder a sus datos.
*/
typedef NodoLista* PtrNodoLista;

/*
  Tipo de estructura de la lista.
*/
struct Lista
{
    PtrNodoLista Primero;
};

/* DECLARACION DE PRIMITIVAS */

/*
  PRE: la lista no debe haber sido creada.
  POST: la lista se crea y queda preparada para ser usada.

  mi_lista: estructura de datos a ser creada.
*/
void CrearLista(Lista& mi_lista);

/*
  PRE: la lista debe haber sido creada.
  POST: la lista es destruida.

  mi_lista: lista sobre la cual se invoca la primitiva.
*/
void DestruirLista(Lista& mi_lista);

/*
  PRE: la lista debe haber sido creada.
  POST: la lista queda vacia.

  mi_lista: lista sobre la cual se invoca la primitiva.
*/
bool ListaVacia(Lista mi_lista);

//***************************************************************************************

/*
  PRE: la lista debe haber sido creada.
  POST: agrega un nuevo nodo al principio de la lista con el dato dado.

  mi_lista: lista sobre la cual se invoca la primitiva.
  mi_dato: elemento a adicionar al principio de la lista.
*/
void AdicionarPrincipio(Lista& mi_lista, PtrDatoLista mi_dato);

/*
  PRE: la lista debe haber sido creada.
  POST: agrega un nuevo nodo al final de la lista con el dato dado.

  mi_lista: lista sobre la cual se invoca la primitiva.
  mi_dato: elemento a adicionar al principio de la lista.
*/
void AdicionarFinal(Lista& mi_lista, PtrDatoLista mi_dato);

/*
  PRE: la lista debe haber sido creada y contener elementos.
  POST: agrega un nuevo nodo con el dato dado en la posicion posterior del NodoApuntado.

  mi_lista: lista sobre la cual se invoca la primitiva.
  NodoApuntado: nodo guía.
  mi_dato: elemento a adicionar al principio de la lista.
*/
void AdicionarDespues(Lista& mi_lista, PtrNodoLista NodoApuntado, PtrDatoLista mi_dato);

/*
  PRE: la lista debe haber sido creada y contener elementos.
  POST: agrega un nuevo nodo con el dato dado en la posicion anterior del NodoApuntado.

  mi_lista: lista sobre la cual se invoca la primitiva.
  NodoApuntado: nodo guía.
  mi_dato: elemento a adicionar al principio de la lista.
*/
void AdicionarAntes(Lista& mi_lista, PtrNodoLista NodoApuntado, PtrDatoLista mi_dato);

//***************************************************************************************

/*
  PRE: la lista debe haber sido creada.
  POST: devuelve el puntero al primer elemento de la lista.

  mi_lista: lista sobre la cual se invoca la primitiva.
  return: puntero al primer nodo.
*/
PtrNodoLista Primero(Lista& mi_lista);

/*
  PRE: la lista debe haber sido creada.
  POST: devuelve el puntero al ultimo elemento de la lista.

  mi_lista: lista sobre la cual se invoca la primitiva.
  return: puntero al ultimo nodo.
*/
PtrNodoLista Ultimo(Lista& mi_lista);

/*
  PRE: la lista debe haber sido creada.
  POST: devuelve el puntero al nodo anterior al apuntado de la lista.

  mi_lista: lista sobre la cual se invoca la primitiva.
  NodoApuntado: nodo guia.
  return: puntero al primer nodo.
*/
PtrNodoLista Anterior(Lista& mi_lista, PtrNodoLista NodoApuntado);

/*
  PRE: la lista debe haber sido creada.
  POST: devuelve el puntero al nodo siguiente al apuntado de la lista.

  mi_lista: lista sobre la cual se invoca la primitiva.
  NodoApuntado: nodo guia.
  return: puntero al primer nodo.
*/
PtrNodoLista Siguiente(Lista& mi_lista, PtrNodoLista NodoApuntado);

/*
  PRE: la lista debe haber sido creada.
  POST: devuelve la representacion de lo siguiente al último Nodo de la lista,
        o sea el valor NULL, que en esta implementacion representa el final de
        la lista.

  return: NULL.
*/
PtrNodoLista Fin_Lista();
//***************************************************************************************

/*
  PRE: la lista debe haber sido creada.
  POST: elimina el nodo apuntado.

  mi_lista: lista sobre la cual se invoca la primitiva.
  NodoApuntado: puntero al nodo que se desea eliminar.
*/
void EliminarNodo(Lista& mi_lista, PtrNodoLista NodoApuntado);

/*
  PRE: la lista debe haber sido creada.
  POST: elimina el primer nodo de la lista.

  mi_lista: lista sobre la cual se invoca la primitiva.
*/
void EliminarPrimero(Lista& mi_lista);

/*
  PRE: la lista debe haber sido creada.
  POST: elimina el ultimo nodo de la lista.

  mi_lista: lista sobre la cual se invoca la primitiva.
*/
void EliminarUltimo(Lista& mi_lista);

/*
  PRE: .
  POST: crea un nodo utilizando el dato dado.

  mi_dato: puntero al dato con el que se crea el nodo.
  return: puntero al nodo creado.
*/
PtrNodoLista CrearNodo(PtrDatoLista mi_dato);

//***************************************************************************************

/*
  PRE: la lista debe haber sido creada.
  POST: agrega el dato al nodo de la lista.

  mi_lista: lista sobre la cual se invoca la primitiva.
  NodoApuntado: nodo a ser modificado.
  mi_dato: elemento a insertar.
*/
void ColocarDato(Lista& mi_lista, PtrNodoLista NodoApuntado, PtrDatoLista mi_dato);    //PUEDE DEVOLVER UN BOOLEANO?

/*
  PRE: la lista debe haber sido creada.
  POST: obtengo el dato del nodo.

  mi_lista: lista sobre la cual se invoca la primitiva.
  NodoApuntado: nodo del dato a ser obtenido.
  return: puntero al dato del nodo.
*/
PtrDatoLista ObtenerDato(Lista mi_lista, PtrNodoLista NodoApuntado);

/*
  PRE: la lista debe haber sido creada.
  POST: se elimina el dato y el nodo.

  mi_lista: lista sobre la cual se invoca la primitiva.
  mi_dato: dato que quiero eliminar.
*/
void EliminarDatoYNodo(Lista& mi_lista, PtrDatoLista mi_dato);     //PUEDE DEVOLVER UN BOOLEANO?

/*
  PRE: la lista debe haber sido creada.
  POST: si el dato se encuentra en la lista, devuelve el puntero al primer nodo
        que lo contiene. Si el dato no se encuentra en la lista devuelve Fin_Lista().

  mi_lista: lista sobre la cual se invoca la primitiva.
  mi_dato: elemento a localizar.
  return: puntero al nodo localizado o Fin_Lista().
*/
PtrNodoLista LocalizarDato(Lista mi_lista, PtrDatoLista mi_dato);

//**************************************************************************************

/*
  PRE: la lista debe haber sido creada.
  POST: devuelve la longitud de la lista.

  mi_lista: lista sobre la cual se invoca la primitiva.
  return: longitud de la lista.
*/
int Longitud_Lista(Lista mi_lista);

//void imprimirLista(Lista &mi_lista);

//void guardarFiguraSimple(string auxLinea, Lista &datos, Figura //&nuevaFigura);

#endif // __LISTA_H__

