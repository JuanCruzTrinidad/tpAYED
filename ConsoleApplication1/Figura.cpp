#include "Figura.h"
#include "Lista.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

/* Implementacion de primitivas */

using namespace std;

void crearFigura(PtrFigura& mi_figura) {
    mi_figura = new Figura;

    /* figura->forma = "";
     figura->color = "";
     figura->valor1 = NULL;
     figura->valor2 = NULL;*/

}

string getForma(PtrFigura& figura) {
    return figura->forma;
}

void setForma(PtrFigura& figura, string forma) {
    figura->forma = forma;
}

string getColor(PtrFigura& figura) {
    return figura->color;
}

void setColor(PtrFigura& figura, string color) {
    figura->color = color;
}


float getValor1(PtrFigura& figura) {
    return figura->valor1;
}

void setValor1(PtrFigura& figura, float valor1) {
    figura->valor1 = valor1;
}


float getValor2(PtrFigura& figura) {
    return figura->valor2;
}

void setValor2(PtrFigura& figura, float valor2) {
    figura->valor2 = valor2;
}


void CargarDesdeArchivo(ifstream& Archivo, Lista& lista)
{
    string linea, Dato2, Dato1, Dato3, Dato4;

    while (!Archivo.eof())
    {
        string Dato1 = Dato3 = Dato2 = Dato4 = "";
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
            if (linea.at(i) == ';') {
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
        CargarListaFiguras(lista, Dato1, Dato2, a, b);
    }
}

/*Cargo uno a uno los valores mediante los Set */
void CargarListaFiguras(Lista& listaFiguras, string forma, string color, float  valor1, float valor2)
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

float convertirStringAFloat(string str) {
    float number = 0;
    int coma = str.find(',');
    if (coma == -1) {
        istringstream iss(str);
        iss >> number;
        return number;
    }
    string punto = ".";
    str.replace(coma,1,punto);
    istringstream iss(str);
    iss >> number;
    return number;
}

/*Recorro la lista e imprimo */
void recorrerLista(Lista& listaFiguras) {
    PtrNodoLista cursor = listaFiguras.Primero;
    float areaTotal = 0;
    while (cursor != Fin_Lista()) {
        cout << ((Figura*)cursor->DatoLista)->forma << " ";
        cout << ((Figura*)cursor->DatoLista)->color << " ";
        cout << ((Figura*)cursor->DatoLista)->valor1 << "; ";
        if (((Figura*)cursor->DatoLista)->valor2 > 0) {
            cout << ((Figura*)cursor->DatoLista)->valor2;
        }
        cout << endl;
        float areaFiguraActual = calcularArea(((Figura*)cursor->DatoLista)->forma, ((Figura*)cursor->DatoLista)->valor1, ((Figura*)cursor->DatoLista)->valor2);
        ((Figura*)cursor->DatoLista)->area = areaFiguraActual;
        cout << "Area: " << areaFiguraActual << endl;
        cursor = cursor->SgteDL;
    }
    delete (cursor);
}

float calcularArea(string nombre, float valor1, float valor2) {

    float area = 0;

    if (nombre.compare("circulo") == false) {
        area = valor1 * 3.14;
    }
    if (nombre.compare("cubo") == false) {
        area = valor1 * valor1;
    }
    if (nombre.compare("triangulo") == false) {
        area = (valor1 * valor2) / 2;
    }
    if (nombre.compare("rectangulo") == false) {
        area = valor1 * valor2;
    }
    if (nombre.compare("cilindro") == false) {
        area = (valor1 * 3.14) * valor2;
    }
    return area;
}

/* calcula el total de plastico utilizado */
float calcularAreaTotal(Lista& listaFiguras) {
    float areaTotal = 0;
    PtrNodoLista cursor = listaFiguras.Primero;
    while (cursor != Fin_Lista()) {
        areaTotal = areaTotal + ((Figura*)cursor->DatoLista)->area;
        cursor = cursor->SgteDL;
    }
    delete (cursor);
    return areaTotal;
}


/* Calcula el total de las figuras */
void totalPorFigura(Lista& listaFigurasOriginal) {
    PtrNodoLista cursor = listaFigurasOriginal.Primero;
    string figuras[5] = { "circulo", "cilindro", "cubo", "triangulo", "rectangulo" }; //Array con las figuras.
    Lista listaFiguras; //Instancia una nueva lista de figuras auxiliar
    for (int i = 0; i <= 4; i++) { //Figuras
        CrearLista(listaFiguras); //por cada iteracion del for, vuelvo a crear la lista
        while (cursor != Fin_Lista()) { //este primer while lo que hace es recorrer la lista original buscando emparejar
            if (((Figura*)cursor->DatoLista)->forma == figuras[i]) { //y al encontrar que concuerden con lo que busca, lo guarda en 
                AdicionarFinal(listaFiguras, ((Figura*)cursor->DatoLista)); //la nueva lista que instancie antes
            }
            cursor = cursor->SgteDL; //va recorriendo la lista original
        }
        cursor = listaFiguras.Primero; //al terminar de añadir a la auxiliar lo que deseo recorrer, itero por figura. Apunto el cursor a la auxiliar.
        cout << "\t" << figuras[i] << ": " << Longitud_Lista(listaFiguras) << endl; //diciendo la cantidad
        cout << "Area total por figura" << ":" << calcularAreaTotal(listaFiguras) << endl;
        recorrerLista(listaFiguras); //haciendo mini recorridos de esas listas
        DestruirLista(listaFiguras); // eliminando las lista en cuestion auxilizar, que en una nueva iteracion vuelve a crearse
        cursor = listaFigurasOriginal.Primero; //apunto el cursor a la lista original, se repite la iteracion. 
    }
    cursor = listaFiguras.Primero;
    delete (cursor);
}


void totalPorFiguraColor(Lista& listaFigurasOriginal) {
    PtrNodoLista cursor = listaFigurasOriginal.Primero;
    string figuras[5] = { "circulo", "cilindro", "cubo", "triangulo", "rectangulo" }; //Array con las figuras.
    string colores[10] = { "amarillo", "rojo", "azul" };
    string colorActual = "";
    Lista listaFiguras; //Instancia una nueva lista de figuras auxiliar
    for (int i = 0; i <= 4; i++) { //Figuras
        for (int j = 0; j <= 2; j++) {
            CrearLista(listaFiguras);
            if (((Figura*)cursor->DatoLista)->forma == figuras[i] && ((Figura*)cursor->DatoLista)->color == "rojo")
            {
                cout << ((Figura*)cursor->DatoLista)->forma << ":" << ((Figura*)cursor->DatoLista)->color << endl;
            }
            }
        }
    }
    




/*
void guardarFiguraCompleja(string auxLinea, Lista &datos, Figura nuevaFigura){
    /* CON PUNTEROS
    stringstream ss(auxLinea); //No se muy bien como funciona todavia jejo

    //Obtengo los datos y los guardo donde corresponde

    getline(ss, nuevaFigura->forma, ' ' ); //Separo la forma
    getline(ss, nuevaFigura->color, ' ' ); //Separo los numeros

    string auxiliarStr;
    getline(ss, auxiliarStr, ';' ); //Separo los numeros
    float auxNumber = convertirStringAFloat(auxiliarStr);
    nuevaFigura->valor1 = auxNumber;

    getline(ss, auxiliarStr, ';' ); //Separo los numeros
    auxNumber = convertirStringAFloat(auxiliarStr);
    nuevaFigura->valor2 = auxNumber;

    adicionarFinal(datos,nuevaFigura); //Se guarda la figura al final de la lista
    /

    // CON GETS Y SETS

    stringstream ss(auxLinea); //No se muy bien como funciona todavia jejo

    //Obtengo los datos y los guardo donde corresponde
    string auxiliarStr;

    getline(ss, auxiliarStr, ' ' ); //Separo la forma
    setForma(nuevaFigura, auxiliarStr);
    getline(ss, auxiliarStr, ' ' ); //Separo los numeros
    setColor(nuevaFigura, auxiliarStr);

    getline(ss, auxiliarStr, ';' ); //Separo los numeros
    float auxNumber = convertirStringAFloat(auxiliarStr);
    setValor1(nuevaFigura,auxNumber);

    getline(ss, auxiliarStr, ';' ); //Separo los numeros
    auxNumber = convertirStringAFloat(auxiliarStr);
    setValor2(nuevaFigura,auxNumber);

    Figura* ptrFigura = &nuevaFigura;

    adicionarFinal(datos, ptrFigura); //Se guarda la figura al final de la lista
}
*/

