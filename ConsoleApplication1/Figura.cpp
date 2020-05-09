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

float calcularArea(string nombre, float valor, float valor2) {

    float area = 0;

    if (nombre.compare("circulo") == false) {
        area = valor * 3.16;
    }
    if (nombre.compare("cubo") == false) {
        area = valor * valor;
    }
    if (nombre.compare("triangulo") == false) {
        area = (valor * valor2) / 2;
    }
    if (nombre.compare("rectangulo") == false) {
        area = valor * valor2;
    }
    return area;
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

