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

typedef void* PtrDatoLista;

struct NodoLista
{
    PtrDatoLista DatoLista;
    NodoLista* SgteDL;
};

typedef NodoLista* PtrNodoLista;

struct Lista
{
    PtrNodoLista Primero;
};

//DECLARACION DE PRIMITIVAS

void CrearLista(Lista& mi_lista);

void DestruirLista(Lista& mi_lista);

bool ListaVacia(Lista mi_lista);

//***************************************************************************************
void AdicionarPrincipio(Lista& mi_lista, PtrDatoLista mi_dato);

void AdicionarFinal(Lista& mi_lista, PtrDatoLista mi_dato);

void AdicionarDespues(Lista& mi_lista, PtrNodoLista NodoApuntado, PtrDatoLista mi_dato);

void AdicionarAntes(Lista& mi_lista, PtrNodoLista NodoApuntado, PtrDatoLista mi_dato);
//***************************************************************************************
PtrNodoLista Primero(Lista& mi_lista);

PtrNodoLista Ultimo(Lista& mi_lista);

PtrNodoLista Anterior(Lista& mi_lista, PtrNodoLista NodoApuntado);

PtrNodoLista Siguiente(Lista& mi_lista, PtrNodoLista NodoApuntado);

PtrNodoLista Fin_Lista();
//***************************************************************************************
void EliminarNodo(Lista& mi_lista, PtrNodoLista NodoApuntado);

void EliminarPrimero(Lista& mi_lista);

void EliminarUltimo(Lista& mi_lista);

PtrNodoLista CrearNodo(PtrDatoLista mi_dato);

//***************************************************************************************
void ColocarDato(Lista& mi_lista, PtrNodoLista NodoApuntado, PtrDatoLista mi_dato);    //PUEDE DEVOLVER UN BOOLEANO?

PtrDatoLista ObtenerDato(Lista mi_lista, PtrNodoLista NodoApuntado);

void EliminarDatoYNodo(Lista& mi_lista, PtrDatoLista mi_dato);     //PUEDE DEVOLVER UN BOOLEANO?

PtrNodoLista LocalizarDato(Lista mi_lista, PtrDatoLista mi_dato);

//**************************************************************************************

int Longitud_Lista(Lista mi_lista);

//void imprimirLista(Lista &mi_lista);

//void guardarFiguraSimple(string auxLinea, Lista &datos, Figura //&nuevaFigura);

#endif // __LISTA_H__
