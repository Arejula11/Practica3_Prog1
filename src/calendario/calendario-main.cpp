/*******************************************************************************
 * Curso de Programación 1. Práctica 3
 * Autores: Miguel Aréjula Aísa
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
#include<fechas.hpp>
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
 * Pre:  ---
 * Post: Ha escrito en la pantalla  la cabecera del calendario
 * 
 */
void escribirCabecera(int& mes, int& agno){
    cout<<setw(21);
    escribirNombreMes(mes);
    cout<<" "<<agno<<endl;
    cout<<" L   M   X   J   V   S   D"<<endl;
    cout<<" - - - - - - - - - - - - -"<<endl;
}
/*
 * Pre:  1 ≤ mes ≤ 12
 * Post: Solicita al usuario que introduzca el valor del mes
 * Nota: Solicita hasta que el valor del año es valido
 */
void pedirMes(int& mes){
    cout<<"Introduzca el mes [1-12]: ";
    cin>>mes;
    while(mes< 1 || mes> 12)
    {
        cout<<"El mes debe estar comprendido entre 1 y 12: ";
        cin>>mes;
    }

}

/*
 * Pre:  agno ≥ 1900
 * Post: Solicita al usuario introduzca el valor del año
 * Nota: Solicita hasta que el valor del año es valido
 */
void pedirAgno(int& agno){

    cout<<"Introduzca un año igual o posterior a 1900: ";
    cin>>agno;
    while(agno<1900)        
    {
        cout<<"El año debe ser igual o posterior a 1900: ";
        cin>>agno;
    }  
}

/*
 * Pre:  ---
 * Post: Determina y escribe en pantalla la posición del primer mes del día
 * 
 */
void escribirPrimerDia(unsigned dia, unsigned mes, unsigned agno, unsigned separacion, unsigned a){
    while(a<diaDeLaSemana(dia,mes,agno)){
        separacion+=4;
        a++;
    }

    cout<<setw(separacion)<<dia<<"  ";

}

/*
 * Pre:  ---
 * Post: Escribe en pantalla el resto de números del mes correspondiente
 * 
 */
void escribirDias(unsigned dia, unsigned mes, unsigned agno){
    while(dia<diasDelMes(mes,agno)){

            dia++;
            if (diaDeLaSemana(dia,mes,agno)==0)
            {   
                if(dia>=10){        //Determina la cantidad de espacios en función de las cifras del número
                    cout<<endl;
                cout<<dia<<"  ";
                }
                else{
                cout<<endl;
                cout<<" "<<dia<<"  ";
                }
            }
            else{
                if(dia>=10){
                    
                cout<<dia<<"  ";
                }
                else{
                cout<<" "<<dia<<"  ";
                }
            }  
    }


}




/*
 * Programa  que solicita al usuario el valor de un mes y un año.  Si estos valores no son validos solicita reiterademente  
 * que el  usuario  introduzca de nuevo unos valores válidos.
 * El programa muestra el calendario del mes correspondiente en el año solicitado por el usuario. 
 */
int main() {

    int mes;
    pedirMes(mes);
    
    int agno;
    pedirAgno(agno);
    
    escribirCabecera(mes,agno);

    unsigned dia=1;
    unsigned a=0;
    unsigned separacion=2;

    escribirPrimerDia(dia,mes,agno,separacion,a);
    escribirDias(dia,mes,agno);


    return 0;
}
