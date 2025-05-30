﻿/*******************************************************************************
 * Curso de Programación 1. Tema 7 y práctica 3
 * Autores originales: Miguel Ángel Latre y Javier Martínez
 * Modificado por: Miguel Aréjula Aísa
 * Última revisión: 9 de octubre de 2021
 * Resumen: Módulo principal de un programa interactivo dirigido por menú que
 *          permite al usuario la realización de algunos cálculos con datos de
 *          tipo entero
 * Nota: Leer el fichero README.md, que contiene instrucciones para su 
 *       compilación y ejecución.
 ******************************************************************************/

#include <iostream>
#include "calculos.hpp"
using namespace std;

/*
 * Número de operaciones que ofrece actualmente el menú del programa.
 */
const unsigned NUM_OPERACIONES = 9;

/*
 *  Pre:  ---
 *  Post: Ha presentado en la pantalla el menú de opciones disponibles.
 */
void presentarMenu() {
    cout << endl;
    cout << "MENÚ DE OPERACIONES" << endl;
    cout << "===================" << endl;
    cout << "0 - Finalizar" << endl;
    cout << "1 - Calcular el número de cifras de un entero" << endl;
    cout << "2 - Sumar las cifras de un entero" << endl;
    cout << "3 - Extraer una cifra de un entero" << endl;
    cout << "4 - Calcular la imagen especular de un entero" << endl;
    cout << "5 - Comprobar si un entero es primo" << endl;
    cout << "6 - Calcular el factorial de un número" << endl;
    cout << "7 - Calcular el máximo común divisor de dos numeros" << endl;
    cout << "8 - Calcular el mínimo común múltiplo de dos numeros" << endl;
    cout << "9 - Comprobar si un entero es capicua" << endl;
    cout << endl;
}

/*
 *  Pre:  ---
 *  Post: Ha presentado en la pantalla el menú de opciones disponibles, ha
 *        solicitado al usuario que escriba el código de una de ellas y ha
 *        asignado a «operacion» la nueva respuesta del usuario.
 */
void pedirOrden(unsigned& operacion) {
    presentarMenu();
    cout << "Seleccione una operación [0-" << NUM_OPERACIONES << "]: ";
    cin >> operacion;    
}


/*
 * Pre:  ---
 * Post: Ha ejecutado la 1ª orden, informando del número de cifras de «numero».
 */
void ejecutarNumCifras(int numero) {
    cout << "El número " << numero << " tiene " << numCifras(numero) << " cifras."
         << endl;
}


/*
 * Pre:  ---
 * Post: Ha ejecutado la 2ª orden, informando de la suma de las cifras de
 *       «numero».
 */
void ejecutarSumaCifras(int numero) {
    cout << "Las cifras de " << numero << " suman " << sumaCifras(numero) << "."
         << endl;
}


/*
 * Pre:  ---
 * Post: Ha ejecutado la 3ª orden, informando del valor de la cifra de «numero»
 *       ubicada en la posición especificada por el usuario.
 */
void ejecutarExtraerCifra(int numero) {
    // El usuario debe definir la posición de la cifra de «numero»
    // en la que está interesado.
    cout << "Seleccione la posición de una cifra: ";
    int posicion;
    cin >> posicion;

    if (posicion >= 1) {
        cout << "La cifra situada en la posición " << posicion << " del número " 
             << numero << " es " << cifra(numero, posicion) << "." << endl;
    }
    else {
        cout << "La posición tiene que ser mayor que 0." << endl;
    }
}


/*
 * Pre:  ---
 * Post: Ha ejecutado la 4ª orden, informando del valor de la imagen especular de
 * «numero».
 */
void ejecutarImagenEspecular(int numero) {
    cout << "El número imagen especular de " << numero
         << " es el " << imagen(numero) << "." << endl;
}


/*
 * Pre:  ---
 * Post: Ha ejecutado la 5ª orden, informando sobre si «numero» es un número primo
 *       o no lo es.
 */
void ejecutarEsPrimo(int numero) {
    cout << "El número " << numero;
    if (!esPrimo(numero)) {
        cout << " no";
    }
    cout << " es primo." << endl;
}


/*
 * Pre:  ---
 * Post: Ha ejecutado la 6ª orden, informando sobre si «numero» es un número primo
 *       o no lo es.
 */
void ejecutarFactorial(int numero) {
    cout<< "El factorial de "<< numero<< " es "<<factorial(numero)<< "."<<endl;
 

}


/*
 * Pre:  ---
 * Post: Ha ejecutado la 7ª orden, informando sobre si «numero» es un número primo
 *       o no lo es.
 */
void ejecutarMcd(int numero, int numero2){
    if (numero==numero2)
    {
        cout<<"Ambos números no  pueden ser "<<numero<<" simultáneamente"<<"."<<endl;
    }
    else{
        cout<<"El máximo común divisor de "<<numero<< " y "<<numero2<< " es "<<mcd(numero,numero2)<<"."<<endl;
    }
    
}


/*
 * Pre:  ---
 * Post: Ha ejecutado la 8ª orden, informando sobre si «numero» es un número primo
 *       o no lo es.
 */
void ejecutarMcm(int numero, int numero2){
    if (numero==numero2)
    {
        cout<<"Ambos números no  pueden ser "<<numero<<" simultáneamente"<<"."<<endl;
    }
    else{
        cout<<"El mínimo común multiplo de "<<numero<< " y "<<numero2<< " es "<<mcm(numero,numero2)<<endl;
    }

}


/*
 * Pre:  ---
 * Post: Ha ejecutado la 9ª orden, informando sobre si «numero» es un número primo
 *       o no lo es.
 */
void ejecutarEsCapicua(int numero){

   cout << "El número " << numero;
    if (!esCapicua(numero)) {
        cout << " no";
    }
    cout << " es capicúa." << endl;
}

    


/*
 *  Pre:  ---
 *  Post: Ha ejecutado las acciones asociadas a la orden cuyo código es
 *        igual al valor del parámetro «operacion». Si «operacion» no se
 *        corresponde con ninguna de las operaciones, escribe en la pantalla un
 *        mensaje de error.
 */
void ejecutarOrden(unsigned operacion) {
    if (operacion >= 1 && operacion <= NUM_OPERACIONES) {
        // Se va a ejecutar una operación válida.
        // En primer lugar se pide al usuario que defina un número entero.
        cout << "Escriba un número entero: ";
        int numero;
        cin >> numero;

        if (operacion == 1) {
            ejecutarNumCifras(numero);
        }
        else if (operacion == 2) {
            ejecutarSumaCifras(numero);
        }
        else if (operacion == 3) {
            ejecutarExtraerCifra(numero);
        }
        else if (operacion == 4) {
            ejecutarImagenEspecular(numero);
        }
        else if (operacion == 5) {
            ejecutarEsPrimo(numero);
        }
        else if (operacion == 6) {
            ejecutarFactorial(numero);
        }
        else if (operacion == 7) {
            cout<<"Escriba otro numero: ";
            int numero2;
            cin>>numero2;
            ejecutarMcd(numero,numero2);
        }
        else if (operacion == 8){
            cout<<"Escriba otro numero: ";
            int numero2;
            cin>>numero2;
            ejecutarMcm(numero,numero2);

        }
        else if (operacion == 9){
        ejecutarEsCapicua(numero);

        }
    }
    else {
        // El código de operación no es válido
        cout << "Opción desconocida" << endl;
    }
}



/*
 * Programa que plantea al usuario de forma reiterada un menú con varias opciones.
 * En cada iteración, lee la respuesta del usuario y presenta los resultados de
 * ejecutar la opción elegida. Concluye cuando el usuario selecciona la
 * opción «0».
 */
int main() {
    unsigned operacion;
    pedirOrden(operacion);

    // Itera hasta que el valor de «operacion» sea igual a 0.
    while (operacion != 0) {
        ejecutarOrden(operacion);
        pedirOrden(operacion);
    }

    return 0;
}
