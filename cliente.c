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
    /* 
    Simulación de clientes: el argumento indicará el número de 
    cliente y código a ejecutar.
    */

    if (argc < 2) {
        printf("No se proporcionaron argumentos suficientes.\n");
        return -1;
    }

    int num_client = atoi(argv[1]); 
    
    if (num_client == 0) {
        printf("Return del init(): %d\n", init());
        double vector1_0[2] = {1, 2};
        // Prueba 1: Value1 no es un string
        printf("Return del set_value(): %d\n",set_value(1, 2, 2, vector1_0));
    }
    else if (num_client == 1){
        // Prueba 2: Init()
        printf("Return del init(): %d\n", init());
        // Prueba 3: Value1 no es un string menor o igual de 256 chars
        double vector1[2] = {1, 2};
        printf("Return del set_value(): %d\n",set_value(2, "holjonhwreguohwerghjuwrguhiowruguhoiwuhoigwuhoiguhwehuoguwhoighuiwouhiogwiuhobgweiuhbgiuhbweruihbguihbwuhibgwhuighuiwuh9igwuhiwuh9gu9hgwu9hg9huwguhowhu9gwuh9oghuowuhiogwuhguhowhugowhuogwuhoguhowuhoiguhoiwuhoigwuhiogwuhiouhigowuho9iguhweio9uhgwhughu9wh9uw9uhd9huog9hwu9hgwerohrwhiguoghoirweohigrweoihoihreiohgiohrehig0o9era", 2, vector1));
        // Prueba 4: N_value2 no es un entero menor o igual de 32
        printf("Return del set_value(): %d\n",set_value(3, "Hola", 33, vector1));
        // Prueba 5: Prueba 4: *Value1 o *N_value o *V_value2 no son punteros válidos
        printf("Return del get_value(): %d\n",get_value(4, "Adiós", 2, NULL));
        printf("Return del get_value(): %d\n",get_value(4, "Hola", NULL, vector1));
        // Prueba 6: Set_value()
        printf("Return del set_value(): %d\n",set_value(5, "Manzana", 2, vector1));
        // Prueba 7: Get_value()
        char value1[MAXSIZE];
        int N_value2;
        double vector2[MAX_N];
        printf("Return del get_value(): %d\n", get_value(5, value1, &N_value2, vector2));
        printf("Valores obtenidos: %s, %d, [%f, %f]\n", value1, N_value2, vector2[0], vector2[1]);
        // Prueba 8: Modify_value()
        double vector3[3] = {1, 2, 3};
        int N_value2_2 = 3;
        printf("Return del modify_value(): %d\n", modify_value(5, "Pera", N_value2_2, vector3));
        // Prueba 9: Delete_key()
        printf("Return del delete_key(): %d\n", delete_key(5));
        // Prueba 10: Exist()
        set_value(6, "Naranja", 2, vector1);
        printf("Return del exist(): %d\n", exist(6)); // Exist: True
        printf("Return del exist(): %d\n", exist(5)); // Exist: False
    }
    else if (num_client == 2) {
        // Cliente que hace set
        double vector4[4] = {1, 2, 4, 5};
        set_value(7, "Melocoton", 4, vector4);
    }
    else if (num_client == 3) {
        // Cliente que hace get
        char value1_2[MAXSIZE];
        int N_value2_3;
        double vector5[MAX_N];
        get_value(7, value1_2, &N_value2_3, vector5);
    }
    else if (num_client == 4) {
        // Cliente que hace mod
        double vector6[3] = {1, 2, 3};
        int N_value2_4 = 3;
        modify_value(7, "Pera", N_value2_4, vector6);
    }
    else if (num_client == 5) {
        // Cliente que hace del
        delete_key(7);
    }
    else if (num_client == 6) {
        // Cliente que hace exist
       exist(7);
    }
    else if (num_client == 7) {
        // Ejemplo de cliente 1 para pruebas

        double vector7[4] = {1, 2, 4, 5};
        char value1_3[MAXSIZE];
        int N_value2_5;
        double vector8[MAX_N];
        printf("Return del set_value(): %d\n",set_value(8, "Pera", 2, vector7));

        // Más operaciones...
        set_value(9, "Albaricoque", 2, vector7);
        exist(9);
        get_value(9, value1_3, &N_value2_5, vector8);
    }
    else if (num_client == 8) {
        // Ejemplo de cliente 2 para pruebas

        char value1_4[MAXSIZE];
        int N_value2_6;
        double vector9[MAX_N];
        printf("Return del get_value(): %d\n",get_value(9, value1_4, &N_value2_6, vector9));
        
        // Más operaciones...
        double vector10[5] = {1, 2, 4, 5, 9.8};
        set_value(24, "Platano", 5, vector10);

        double vector11[3] = {1, 2, 3};
        int N_value2_7 = 3;
        modify_value(24, "Pera", N_value2_7, vector11);
        
    }
    else if (num_client == 9) {
        // Ejemplo de cliente 3 para pruebas

        double vector12[3] = {1, 2, 3};
        int N_value2_8 = 3;
        printf("Return del modify_value(): %d\n", modify_value(9, "Pera", N_value2_8, vector12));

        // Más operaciones...
        delete_key(24);
        double vector13[1] = {2.3};
        set_value(14, "Sandia", 1, vector13);

    }
    else if (num_client == 10) {
        // Ejemplo de cliente 4 para pruebas

        printf("Return del delete_key(): %d\n", delete_key(50));

        // Más operaciones...
        char value1_5[MAXSIZE];
        int N_value2_9;
        double vector14[MAX_N];
        printf("Return del get_value(): %d\n", get_value(9, value1_5, &N_value2_9, vector14));
    }
    else if(num_client == 11){
        // Prueba 22: Set la clave YA existe
        double vector15[2] = {1, 2};
        set_value(15, "Manzana", 2, vector15);
        set_value(15, "Tomate", 2, vector15);
    }
    else if(num_client == 12){
        // Prueba 23: Get la clave NO existe
        char value1_6[MAXSIZE];
        int N_value2_10;
        double vector16[MAX_N];
        get_value(16, value1_6, &N_value2_10, vector16);
    }
    else if(num_client == 13){
        // Prueba 24: Modify la clave NO existe
        double vector17[2] = {1, 2};
        modify_value(16, "Pera", 2, vector17);
    }
    else if(num_client == 14){
        // Prueba 25: Delete la clave NO existe
        delete_key(16);
    }
    else if(num_client == 15){
        // Init()
        init();
    }
    else {
        printf("El valor de num_client no está en el rango permitido (1-15).\n");
    }

    return 0;
}