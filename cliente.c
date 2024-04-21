/*
    Autores: Natalia Rodríguez Navarro (100471976)
             Arturo Soto Ruedas (100472007)

    Este módulo desarrolla un ejemplo de código de un 
    cliente que utilice las funciones ofrecidas por claves.h.
    Puede introducirse el argumento de número de cliente (del 1-15)
    para ejecutar códigos distintos.
*/

#include <stdio.h>
#include <stdlib.h>
#include "claves.h"

#define MAXSIZE 256
#define MAX_N 32


int main(int argc, char *argv[]){
    init();
    double vector[4] = {1, 2, 3 ,4};
    set_value(1, "caca", 4, vector);
    set_value(2, "caca", 4, vector);
    int i;
    double v[MAX_N];
    char a[MAXSIZE];
    get_value(2, a, &i, v);
    printf("Obtenidos del get: %s %d [%f, %f, %f, %f]", a, i, v[0], v[1], v[2], v[3]);
    delete_key(1);
    double vector2[3] = {22222, 4444, 5555};
    modify_value(2, "cosa mona", 3, vector2);
    printf("esists: %d", exist(2));
}