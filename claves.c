/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "claves_iu.h"
#include "claves.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>



/*PROTOTIPOS*/
CLIENT* communication_with_server();
void handler_SIGSEGV(int sig);





int init() {
    // Código para inicializar el servicio
	CLIENT *clnt;
	clnt = communication_with_server();
	if (clnt == NULL){
		printf("Error al comunicarse con el servidor\n");
		return -1;
	}

	enum clnt_stat retval_1;
	int result_1;
	retval_1 = init_1(&result_1, clnt);
	if (retval_1 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
		clnt_destroy( clnt );
		return -1;
	}

	clnt_destroy( clnt );
    return 0; // Éxito
}


int set_value(int key, char *value1, int N_value2, double *V_value2) {
    // Código para insertar el elemento <key, value1, value2>
    
    // Comprobar argumentos
    signal(SIGSEGV, handler_SIGSEGV);
    if (strlen(value1) > 256){
        printf("Error: Value1 debe ser un string de 255 caracteres o menor\n");
        return -1;
    }

    if (N_value2 > 32){
        printf("Error: N_value2 debe ser 32 o menor\n");
        return -1;
    }

	CLIENT *clnt;
	clnt = communication_with_server();
	if (clnt == NULL){
		printf("Error al comunicarse con el servidor\n");
		return -1;
	}

	enum clnt_stat retval_2;
	int result_2;
	SetValueArgs set_value_1_arg1;
	/*
	struct SetValueArgs {
				int key;
				string value1<>;
				int N_value2;
				double V_value2<>;
				};
	*/
    set_value_1_arg1.key = key;
	set_value_1_arg1.value1 = malloc(strlen(value1) + 1); // IMPORTANTE, SI DA MAS SIGSEGV EN OTRAS FUNCIONES
	strcpy(set_value_1_arg1.value1, value1);
    set_value_1_arg1.N_value2 = N_value2;
	set_value_1_arg1.V_value2.V_value2_len = N_value2;
	set_value_1_arg1.V_value2.V_value2_val = malloc(N_value2 * sizeof(double));
    for (int i=0; i < N_value2; i++){
        set_value_1_arg1.V_value2.V_value2_val[i] = V_value2[i];
    }

	retval_2 = set_value_1(set_value_1_arg1, &result_2, clnt);
	if (retval_2 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
		clnt_destroy( clnt );
		return -1;
	}

	clnt_destroy( clnt );
	free(set_value_1_arg1.value1);
	free(set_value_1_arg1.V_value2.V_value2_val);
    return 0; // Éxito
}


int get_value(int key, char *value1, int *N_value2, double *V_value2) {
    // Código para obtener los valores asociados a la clave key

    // Comprobar argumentos: punteros
    signal(SIGSEGV, handler_SIGSEGV);
    if (value1 == NULL || N_value2 == NULL || V_value2 == NULL) {
        printf("Error: los argumentos deben ser punteros no nulos\n");
        return -1;
    } else if (sizeof(value1) != sizeof(char *) || sizeof(N_value2) != sizeof(int *) || sizeof(V_value2) != sizeof(double *)) {
        printf("Error: los argumentos deben ser punteros\n");
        return -1;
    }

    // Inicialización de los valores antes de su uso
    memset(value1, 0, MAXSIZE); 
    *N_value2 = MAX_N;          
    memset(V_value2, 0, sizeof(double) * MAX_N); 


	CLIENT *clnt;
	clnt = communication_with_server();
	if (clnt == NULL){
		printf("Error al comunicarse con el servidor\n");
		return -1;
	}

	enum clnt_stat retval_3;
	int result_3;
	int get_value_1_arg1;
	GetValueResponse get_value_response_1;
	/*	
		struct GetValueResponse {
			string value1<>; 
			int N_value2;      
			double V_value2<>;  
		};
	*/
    get_value_1_arg1 = key;
	get_value_response_1.value1 = value1;
	get_value_response_1.N_value2 = *N_value2;
	get_value_response_1.V_value2.V_value2_len = *N_value2;
	get_value_response_1.V_value2.V_value2_val = V_value2;


	retval_3 = get_value_1(get_value_1_arg1, &get_value_response_1, clnt);
	if (retval_3 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
		clnt_destroy( clnt );
		return -1;
	}

    // Copia los valores de la respuesta en las variables locales
    strcpy(value1, get_value_response_1.value1);
    *N_value2 = get_value_response_1.N_value2;
    memcpy(V_value2, get_value_response_1.V_value2.V_value2_val, get_value_response_1.V_value2.V_value2_len * sizeof(double));
	
	clnt_destroy( clnt );
    return 0; // Éxito
}



int delete_key(int key) {
    // Código para borrar el elemento cuya clave es key

	CLIENT *clnt;
	clnt = communication_with_server();
	if (clnt == NULL){
		printf("Error al comunicarse con el servidor\n");
		return -1;
	}

	enum clnt_stat retval_4;
	int result_4;
	int delete_key_1_arg1;
	
    delete_key_1_arg1 = key;


	retval_4 = delete_key_1(delete_key_1_arg1, &result_4, clnt);
	if (retval_4 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
		clnt_destroy( clnt );
		return -1;
	}
    
	clnt_destroy( clnt );
    return 0; // Éxito
}



int modify_value(int key, char *value1, int N_value2, double *V_value2) {
    // Código para modificar los valores asociados a la clave key

    // Comprobar argumentos
    signal(SIGSEGV, handler_SIGSEGV);
    if (strlen(value1) > 256){
        printf("Error: Value1 debe ser un string de 255 caracteres o menor\n");
        return -1;
    }

    if (N_value2 > 32){
        printf("Error: N_value2 debe ser 32 o menor\n");
        return -1;
    }
    

	CLIENT *clnt;
	clnt = communication_with_server();
	if (clnt == NULL){
		printf("Error al comunicarse con el servidor\n");
		return -1;
	}

	enum clnt_stat retval_5;
	int result_5;
	SetValueArgs modify_value_1_arg1;
	/*
	struct SetValueArgs {
				int key;
				string value1<>;
				int N_value2;
				double V_value2<>;
				};
	*/
    modify_value_1_arg1.key = key;
	modify_value_1_arg1.value1 = malloc(strlen(value1) + 1);
	strcpy(modify_value_1_arg1.value1, value1);
    modify_value_1_arg1.N_value2 = N_value2;
	modify_value_1_arg1.V_value2.V_value2_len = N_value2;
	modify_value_1_arg1.V_value2.V_value2_val = malloc(N_value2 * sizeof(double));
    for (int i=0; i < N_value2; i++){
        modify_value_1_arg1.V_value2.V_value2_val[i] = V_value2[i];
    }


	retval_5 = modify_value_1(modify_value_1_arg1, &result_5, clnt);
	if (retval_5 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
		clnt_destroy( clnt );
		return -1;
	}

	free(modify_value_1_arg1.value1);
	free(modify_value_1_arg1.V_value2.V_value2_val);
	clnt_destroy( clnt );
    return 0; // Éxito
}



int exist(int key) {
    // Código para determinar si existe un elemento con clave key

	CLIENT *clnt;
	clnt = communication_with_server();
	if (clnt == NULL){
		printf("Error al comunicarse con el servidor\n");
		return -1;
	}

	enum clnt_stat retval_6;
	int result_6;
	int exist_1_arg1;
	
    exist_1_arg1 = key;

	retval_6 = exist_1(exist_1_arg1, &result_6, clnt);
	if (retval_6 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
		clnt_destroy( clnt );
		return -1;
	}
	
    clnt_destroy( clnt );
    return result_6; 
}



CLIENT* communication_with_server(){
	// Obtener variable de entorno
	char *host;
    host = getenv("IP_TUPLAS");
    if (host == NULL){
        printf("Variable IP_TUPLAS no definida\n");
        return NULL;
    }

	CLIENT *clnt;
	clnt = clnt_create (host, CLAVES_PROG, CLAVES_VERS, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		return NULL;
	}

	return clnt;
}

void handler_SIGSEGV(int sig){
    printf("Error, revise los argumentos introducidos: Debe introducirse un string en valor1,\n");
    printf("value2_N debe corresponder con el tamaño real del vector, los pointers en modify_value()\n");
    printf("deben ser válidos, ...\n");
    exit(sig);
}