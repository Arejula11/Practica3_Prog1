/*******************************************************************************
 * Curso de Programación 1. Práctica 3
 * Autores: ¡PON AQUÍ TU NOMBRE!
 * Última revisión: 21 de octubre de 2021
 * Resumen: Programa que escribe en la pantalla el calendario de un determinado
 *          mes de un año, que se solicitan al usuario. El programa se asegura
 *          de que el mes introducido está comprendido entre 1 y 12 y de que el
 *          año es igual o posterior a 1900.
 *          Clase de problemas correspondiente al tema 7 (diseño modular y
 *          descendente) y 3ª práctica.
 * Nota: Leer el fichero README.md, que contiene instrucciones para su 
 *       compilación y ejecución.
\******************************************************************************/
#include <iostream>
#include <string>
#include<iomanip>
using namespace std;

/*
 * Pre:  1 ≤ mes ≤ 12
 * Post: Ha escrito en la pantalla el nombre (en mayúsculas) del mes
 *       correspondiente al valor del parámetro «mes».
 * Nota: Este código lo podrás comprender adecuadamente cuando hayamos visto
 *       los temas 9 (vectores) y 10 (cadenas de caracteres).
 */
void escribirNombreMes(unsigned mes) {
    const string NOMBRES_MES[12] = { "ENERO",
            "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO",
            "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE" };
    cout << NOMBRES_MES[mes - 1];
}


/*
 * Programa  que solicita al usuario el valor de un mes y un año.  Si estos valores no son validos solicita reiterademente  
 * que el  usuario  introduzca de nuevo unos valores válidos.
 * El programa muestra el calendario del mes correspondiente en el año solicitado por el usuario. 
 */
int main() {

    int mes;
    
    cout<<"Introduzca el mes [1-12]: ";
    cin>>mes;
    while(mes< 1 || mes> 12)
    {
        cout<<"El mes debe estar comprendido entre 1 y 12: ";
        cin>>mes;
    }
    
    int agno;

    cout<<"Introduzca un año igual o posterior a 1900: ";
    cin>>agno;
    while(agno<1900)
    {
        cout<<"El año debe ser igual o posterior a 1900: ";
        cin>>agno;
    } 
    cout<<setw(19);
    escribirNombreMes(mes);
    cout<<" "<<agno<<endl;
    cout<<setw(24)<<" L  M  X  J  V  S  D"<<endl;
    cout<<" - - - - - - - - - - - -"<<endl;
     
     
     
     
     
     
    return 0;
}
