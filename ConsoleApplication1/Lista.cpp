#include "Lista.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
//#include "pch.h"

void CrearLista(Lista& mi_lista)
{
    mi_lista.Primero = Fin_Lista();
}

void DestruirLista(Lista& mi_lista)
{
    PtrNodoLista PtrAux;
    while (!ListaVacia(mi_lista))
    {
        PtrAux = mi_lista.Primero;
        mi_lista.Primero = mi_lista.Primero->SgteDL;
        delete PtrAux->DatoLista;
        delete PtrAux;
    }
}


PtrNodoLista Fin_Lista()
{
    return NULL;
}


bool ListaVacia(Lista mi_lista)
{
    return(mi_lista.Primero == Fin_Lista());
}


void AdicionarPrincipio(Lista& mi_lista, PtrDatoLista mi_dato)
{
    PtrNodoLista NuevoNodo = CrearNodo(mi_dato);
    NuevoNodo->SgteDL = mi_lista.Primero;
    mi_lista.Primero = NuevoNodo;
}


void AdicionarFinal(Lista& mi_lista, PtrDatoLista mi_dato)
{
    if (ListaVacia(mi_lista))
        AdicionarPrincipio(mi_lista, mi_dato);
    else
    {
        PtrNodoLista NuevoNodo = CrearNodo(mi_dato);
        NuevoNodo->SgteDL = Fin_Lista();
        Ultimo(mi_lista)->SgteDL = NuevoNodo;
    }
}


PtrNodoLista CrearNodo(PtrDatoLista mi_dato)
{
    PtrNodoLista NuevoNodo = new NodoLista;
    NuevoNodo->DatoLista = mi_dato;
    return NuevoNodo;
}


void AdicionarDespues(Lista& mi_lista, PtrNodoLista NodoApuntado, PtrDatoLista mi_dato)
{
    PtrNodoLista NuevoNodo = CrearNodo(mi_dato);
    NuevoNodo->SgteDL = NodoApuntado->SgteDL;
    NodoApuntado->SgteDL = NuevoNodo;
}


void AdicionarAntes(Lista& mi_lista, PtrNodoLista NodoApuntado, PtrDatoLista mi_dato)
{
    if (NodoApuntado == Primero(mi_lista))
    {
        AdicionarPrincipio(mi_lista, mi_dato);
    }
    else
    {
        PtrNodoLista NuevoNodo = CrearNodo(mi_dato);
        Anterior(mi_lista, NodoApuntado)->SgteDL = NuevoNodo;
        NuevoNodo->SgteDL = NodoApuntado;
    }
}


PtrNodoLista Primero(Lista& mi_lista)
{
    return mi_lista.Primero;
}


PtrNodoLista Ultimo(Lista& mi_lista)
{
    return Anterior(mi_lista, Fin_Lista());
}


PtrNodoLista Anterior(Lista& mi_lista, PtrNodoLista NodoApuntado)
{
    if (!ListaVacia(mi_lista) && Primero(mi_lista) != NodoApuntado)
    {
        PtrNodoLista Cursor = Primero(mi_lista);

        while (Cursor->SgteDL != NodoApuntado && Cursor != Fin_Lista())
        {
            Cursor = Cursor->SgteDL;
        }
        return Cursor;
    }
    else
        return Fin_Lista();
}


PtrNodoLista Siguiente(Lista& mi_lista, PtrNodoLista NodoApuntado)
{
    if (!ListaVacia(mi_lista))
    {
        PtrNodoLista Cursor = Primero(mi_lista);

        while (Cursor != NodoApuntado && Cursor != Ultimo(mi_lista))
        {
            Cursor = Cursor->SgteDL;
        }
        return Cursor->SgteDL;
    }
    else
        return Fin_Lista();
}


void EliminarPrimero(Lista& mi_lista)
{
    if (!ListaVacia(mi_lista))
    {
        PtrNodoLista PtrAux = mi_lista.Primero->SgteDL;
        delete mi_lista.Primero;
        mi_lista.Primero = PtrAux;
    }
}


void EliminarUltimo(Lista& mi_lista)
{
    if (!ListaVacia(mi_lista))
    {
        if (Primero(mi_lista) != Ultimo(mi_lista))
        {
            EliminarNodo(mi_lista, Ultimo(mi_lista));
        }
        else
        {
            EliminarPrimero(mi_lista);
        }
    }
}


void EliminarNodo(Lista& mi_lista, PtrNodoLista NodoApuntado)
{
    if (NodoApuntado == Primero(mi_lista))
    {
        mi_lista.Primero = NodoApuntado->SgteDL;
    }
    else
    {
        Anterior(mi_lista, NodoApuntado)->SgteDL = NodoApuntado->SgteDL;
    }
    delete NodoApuntado;
}


void ColocarDato(Lista& mi_lista, PtrNodoLista NodoApuntado, PtrDatoLista mi_dato)
{
    NodoApuntado->DatoLista = mi_dato;
}


PtrDatoLista ObtenerDato(Lista mi_lista, PtrNodoLista NodoApuntado)
{
    return NodoApuntado->DatoLista;
}


void EliminarDatoYNodo(Lista& mi_lista, PtrDatoLista mi_dato)
{
    if (!ListaVacia(mi_lista))
    {
        PtrNodoLista Cursor = Primero(mi_lista);

        while (Cursor->DatoLista != mi_dato && Cursor != Fin_Lista())
        {
            Cursor = Cursor->SgteDL;
        }
        if (Cursor != Fin_Lista())
        {
            EliminarNodo(mi_lista, Cursor);
        }
    }
}


PtrNodoLista LocalizarDato(Lista mi_lista, PtrDatoLista mi_dato)
{
    if (ListaVacia(mi_lista))
    {
        return Fin_Lista();
    }
    else
    {
        PtrNodoLista Cursor = Primero(mi_lista);

        while (Cursor->DatoLista != mi_dato && Cursor != Fin_Lista())
        {
            Cursor = Cursor->SgteDL;
        }
        return Cursor;
    }
}


int Longitud_Lista(Lista mi_lista)
{
    int i = 0;
    PtrNodoLista Cursor = Primero(mi_lista);
    while (Cursor != Fin_Lista())
    {
        i++;
        Cursor = Cursor->SgteDL;
    }
    return i;
}