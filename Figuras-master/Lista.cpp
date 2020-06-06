#include "Lista.h"

//ver si es necesario
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

/*
void imprimirLista(Lista &listaFiguras){
    /*Figura * auxFigura;
    int i=0;
    PtrNodoLista actual = primero(listaFiguras);

    while(i<longitud(listaFiguras)){ //Se imprime hasta que termine la lista
        auxFigura = (Figura*)actual->ptrDato;

        cout<<"Figura: "<<auxFigura->forma<<", "<< auxFigura->color<<", "<< auxFigura->valor1 <<" | "<< auxFigura->valor2<<endl;

        i++;

        actual = siguiente(listaFiguras,actual);
    }

    int i=0;
    PtrNodoLista actual = primero(listaFiguras);
    Figura * nuevaFigura;

    while(i<longitud(listaFiguras)){ //Se imprime hasta que termine la lista
        nuevaFigura = (Figura*)actual->ptrDato;


        cout<<"Figura: "<<getForma(nuevaFigura)<<", "<< getColor(nuevaFigura)<< endl;//", "<< getValor1(nuevaFigura) <<" | "<< getValor2(nuevaFigura)<<endl;

        i++;

        actual = siguiente(mi_lista,actual);
    }
}
*/


/*
void guardarFiguraSimple(string auxLinea, Lista &datos, Figura &nuevaFigura){

    stringstream ss(auxLinea);

    //Obtengo los datos y los guardo donde corresponde

    //getline(ss, nuevaFigura->forma, ' ' ); //Separo la forma
    //getline(ss, nuevaFigura->color, ' ' ); //Separo los numeros
    string auxiliarStr;

    getline(ss, auxiliarStr, ' ' ); //Separo la forma
    setForma(nuevaFigura, auxiliarStr);
    getline(ss, auxiliarStr, ' ' ); //Separo los numeros
    setColor(nuevaFigura, auxiliarStr);

    //getline(ss, auxiliarStr, ' ' ); //Separo los numeros
    //float auxNumber = convertirStringAFloat(auxiliarStr);
    //nuevaFigura->valor1 = auxNumber;
    //setValor1(nuevaFigura,auxNumber);

    //nuevaFigura->valor2 = NULL;
    //setValor2(nuevaFigura,NULL);
   // Figura* ptrFigura = &nuevaFigura;

    //cout << ptrFigura->forma;
    //cout << "Forma: " << getForma(nuevaFigura) << endl;
    //cout << "Color: " << getColor(nuevaFigura) << endl;

    adicionarFinal(datos, nuevaFigura); //Se guarda la figura al final de la lista

    //imprimirListaFiguras(datos);
}
*/

