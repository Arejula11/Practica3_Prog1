﻿/*************************************************************************
 * Curso de Programación 1. Tema 7 y práctica 3
 * Autores: Miguel Ángel Latre y Javier Martínez (esqueleto inicial)
 * Modificado por: Miguel Aréjula Aísa (funciones establecidas en la práctica 3)
 * Última revisión: 23 de octubre de 2020
 * Resumen: Fichero calculos.cpp de implementación del módulo de biblioteca
 *          «calculos» que facilita algunas funciones para trabajar con
 *          datos de tipo entero.
 *          Versión específica de la práctica 3.
\************************************************************************/

/*
 * Pre:  ---
 * Post: Ha devuelto el número de cifras de «n» cuando este se escribe en
 *       base 10.
 */
unsigned numCifras(int n) {
    unsigned cuenta = 1;      // lleva la cuenta de las cifras identificadas
    n = n / 10;             // elimina la cifra menos significativa de «n»
    while (n != 0) {
        // El valor de <cuenta> es igual al de cifras identificadas en «n»
        cuenta++;       // contabiliza la cifra menos significativa de «n»
        n = n / 10;     // y la elimina de «n».
    }
    return cuenta;
}


/*
 * Pre:  ---
 * Post: Ha devuelto la suma de las cifras de «n» cuando «n» se escribe en
 *       base 10.
 */
unsigned sumaCifras(int n) {
    if (n < 0) {
        n = -n;                 // si «n» es negativo, le cambia el signo
    }
    unsigned suma = 0;      // suma de las cifras eliminadas de «n»
    while (n != 0) {
        suma = suma + n % 10;   // suma la cifra menos significativa de «n»
        n = n / 10;             // y la elimina de «n»
    }
    return suma;
}


/*
 *  Pre:  i ≥ 1
 *  Post: Ha devuelto la «i»-ésima cifra menos significativa de «n» cuando
 *        «n» se escribe en base 10.
 */
unsigned cifra(int n, unsigned i) {
    if (n < 0) {
        n = -n;             // si «n» es negativo, le cambia el signo
    }
    for (unsigned exp = 1; exp < i; exp++) {
        n = n / 10;         // elimina la cifra menos significativa de «n»
    }
    return n % 10;
}


/*
 *  Pre:  ---
 *  Post: Ha devuelto el número que escrito en base 10 es la imagen
 *        especular de «n» cuando «n» se escribe también en base 10.
 */
int imagen(int n) {
    // «negativo» memoriza si «n» es, inicialmente, positivo o negativo.
    bool negativo = n < 0;
    if (n < 0) {
        n = -n;                  // si «n» es negativo, le cambia el signo
    }

    // Variable para el cálculo de la imagen especular de «n»
    int resultado = 0;
    while (n != 0) {
        // Incorpora el dígito menos significativo de «n» a la variable
        // «resultado»
        resultado = 10 * resultado + n % 10;
        // Y lo elimina de «n»
        n = n / 10;
    }
    
    // Se devuelve el valor «resultado» con el signo que tenía «n» al
    // la ejecución de esta función.
    if (negativo) {
        return -resultado;
    }
    else {
        return resultado;
    }
}


/*
 *  Pre:  ---
 *  Post: Ha devuelto el factorial de «n».
 */
unsigned factorial(unsigned n) {
    int factorial = 1;      //  factorial = 0!
    for (unsigned i = 2; i <= n; i++) {
        //  factorial = (i - 1)!
        factorial = i * factorial;
        // factorial = i!
    }
    // factorial = n!
    return factorial;
}


/*
 *  Pre:  ---
 *  Post: Ha devuelto true si y solo si «n» es un número primo.
 */
bool esPrimo(unsigned n) {
    if (n == 2) {
        return true;      // «n» es igual a 2, luego es primo.
    }
    else if (n < 2 || n % 2 == 0) {
        return false;     // «n» es menor que 2 o par mayor que 2.
    }
    else {
        // Se buscan posibles divisores impares de «n» a partir del 3:

        // «divisor» indica el siguiente impar candidato a dividir a «n».
        unsigned divisor = 3;              // Primer divisor impar a probar

        // «encontrado» indica si se ha encontrado un divisor de «n».
        bool encontrado = false;

        while (!encontrado && divisor * divisor <= n) {
            encontrado = n % divisor == 0;
            divisor = divisor + 2;
        }
        return !encontrado;
    }
}


/*
 *  Pre: a ≠ 0 o b ≠ 0
 *  Post: Ha devuelto el máximo común divisor de <a> y <b>.
 */
unsigned mcd(int a, int b) {
    // Algoritmo de Euclides para el cálculo del mcd
    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }
    
    while (b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }
    
    return a;
}

/*
 Pre: a!=0ob!=0
* Post: Ha devuelto el mínimo común múltiplo de «a» y «b». */
unsigned mcm(int a, int b){

    //En caso en el que solo uno de los dos sea negativo lo convierte a posotivo
    if (a<0 && b>0){
        a = -a;
    }
    else if(a>0 && b<0){
        b = -b;
    }
    //Equivalencia matemática entre Mcd y mcm
    int n=(a*b)/mcd(a,b);

    return n;
    
}

/*
* Pre: ---
* Post: Ha devuelto true si y solo si el número «n» es capicúa cuando se escribe en base 10. */
bool esCapicua(int n){
    
    //A partir de una funicón previamente declarada compruebo si el número es igual a su imágen especular
    if (imagen(n)==n){
        return true;
    }
    else{
        return false;
    }
}

