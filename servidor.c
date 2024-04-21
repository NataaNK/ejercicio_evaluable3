/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include <mqueue.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "cJSON/cJSON.h"
#include <stddef.h> 
#include <errno.h> 
#include <signal.h> 
#include "claves_iu.h"

/* Mutex para proteger el acceso al archivo data.json */
//pthread_mutex_t mutex_archivo;


/* PROTOTIPOS */
cJSON* read_json(char *file_path);
int write_json(char *file_path, char *str);



bool_t
init_1_svc(int *result, struct svc_req *rqstp)
{
	bool_t retval = TRUE;
	*result = 0;  

	// Eliminar json anterior
	remove("data.json");
	
	// Crear nueva base de datos
	//pthread_mutex_lock(&mutex_archivo);
	FILE *fp = fopen("data.json", "w"); 
	//pthread_mutex_unlock(&mutex_archivo);
	if (fp == NULL) { 
		perror("Error: Unable to open the file.\n"); 
		retval = FALSE;
		*result = -1;  
	}
	else if (fputs("{}", fp) < 0) { 
		perror("Error: Unable to write to the file.\n"); 
		retval = FALSE;
		*result = -1;  
	}
	fclose(fp);
	return retval;
}


bool_t
set_value_1_svc(SetValueArgs arg1, int *result,  struct svc_req *rqstp)
{
	bool_t retval = TRUE;
	*result = 0;  

	// Leer cotenido base de datos y obtener json
	cJSON *json = read_json("data.json");
	if (json == NULL){
		perror("Error: Unable to read the json file\n");
		retval = FALSE;
		*result = -1;  
		cJSON_Delete(json);
		return retval;
	}

	// Crear entrada en el json, con la clave como key
	/*struct SetValueArgs {
   	 					int key;
    					string value1<>;
    					int N_value2;
    					V_value2_double V_value2;
						};
	*/

	char list_key[MAXSIZE];
	sprintf(list_key, "%d", arg1.key);

	// Si encuentra un item usando esa clave, la clave ya existe -> error
	cJSON *item = cJSON_GetObjectItemCaseSensitive(json, list_key);
	if (item != NULL){
		printf("Set_value() error: La clave %d ya existe.\n", arg1.key);
		retval = FALSE;
		*result = -1;  
		cJSON_Delete(json);
		return retval;
	}

	cJSON *array = cJSON_AddArrayToObject(json, list_key);

	// Añadimos los valores de la tupla a la lista
	cJSON_AddItemToArray(array, cJSON_CreateString(arg1.value1));
	cJSON_AddItemToArray(array, cJSON_CreateNumber(arg1.N_value2));
	cJSON_AddItemToArray(array, cJSON_CreateDoubleArray(arg1.V_value2.V_value2_val, arg1.N_value2));

	// Convertir cJSON object a JSON string 
	char *json_str = cJSON_Print(json);
	
	// Escribir JSON string al archivo
	if (write_json("data.json", json_str) < 0){
		perror("Error: Unable to write on the file\n");
		retval = FALSE;
		*result = -1;  
		cJSON_free(json_str);
        cJSON_Delete(json);
		return retval;
	}
	
	// Liberar JSON string y cJSON object 
	cJSON_free(json_str); 
	cJSON_Delete(json);
	
	return retval;
}


bool_t
get_value_1_svc(int arg1, GetValueResponse *result,  struct svc_req *rqstp)
{
	bool_t retval = TRUE; 

	// Leer cotenido base de datos y obtener json
	cJSON *json = read_json("data.json");
	if (json == NULL){
		perror("Error: Unable to read the json file\n");
		retval = FALSE; 
		cJSON_Delete(json);
		return retval;
	}
	
	// Buscamos el item asocfiado a la key
	char list_key[MAXSIZE];
	sprintf(list_key, "%d", arg1);
	cJSON *item = cJSON_GetObjectItemCaseSensitive(json, list_key);
	if (item == NULL){
		printf("Get_value() error: La clave %d no está en la base de datos.\n", arg1);
		retval = FALSE;
		cJSON_Delete(json);
		return retval;
	}
	
	// Obtenemos su tubla
	cJSON *value1 = cJSON_GetArrayItem(item, 0);
	cJSON *value2_N = cJSON_GetArrayItem(item, 1);
	cJSON *value2_vector = cJSON_GetArrayItem(item, 2);
	// Valor1
	char *value1_str = cJSON_Print(value1);
	// Valor2 N
	int value2_N_int = cJSON_GetNumberValue(value2_N);
	// Valor2 Vector
	double *double_vector = malloc(value2_N_int * sizeof(double));
	for (int i = 0; i < value2_N_int; i++) {
		cJSON *element = cJSON_GetArrayItem(value2_vector, i);
		double_vector[i] = cJSON_GetNumberValue(element);
	}
	
	// Guardamos el resultado
	/*	
		struct GetValueResponse {
			string value1<>; 
			int N_value2;      
			double V_value2<>;  
		};
	*/
	result->value1 = malloc(strlen(value1_str) + 1);
    strcpy(result->value1, value1_str);  
    result->N_value2 = value2_N_int;
	result->V_value2.V_value2_val = malloc(value2_N_int * sizeof(double));
    result->V_value2.V_value2_len = value2_N_int;

	for(int i = 0; i < value2_N_int; i++){
		result->V_value2.V_value2_val[i] = double_vector[i];
	}

	free(double_vector);
	cJSON_Delete(json);
	return retval;
}


bool_t
delete_key_1_svc(int arg1, int *result,  struct svc_req *rqstp)
{
	bool_t retval = TRUE;
	*result = 0;  

	// Leer cotenido base de datos y obtener json
	cJSON *json = read_json("data.json");
	if (json == NULL){
		perror("Error: Unable to read the json file\n");
		retval = FALSE;
		*result = -1; 
		cJSON_Delete(json);
		return retval;
	}

	// Eliminar entrada
	char list_key[MAXSIZE];
	sprintf(list_key, "%d", arg1);
	cJSON *item = cJSON_GetObjectItemCaseSensitive(json, list_key);
	if (item == NULL){
		printf("Delete_key() error: La clave %d no está en la base de datos.\n", arg1);
		retval = FALSE;
		*result = -1; 
		cJSON_Delete(json);
		return retval;
	}

	cJSON_DeleteItemFromObject(json, list_key);

	// Covertir cJSON object a JSON string 
	char *json_str = cJSON_Print(json); 

	// Escribir JSON string al archivo
	if (write_json("data.json", json_str) < 0){
		perror("Error: Unable to write on the file\n");
		retval = FALSE;
		*result = -1;
		cJSON_free(json_str); 
		cJSON_Delete(json);
		return retval;
	}

	// Liberar el JSON string y cJSON object 
	cJSON_free(json_str); 
	cJSON_Delete(json);

	return retval;
}


bool_t
modify_value_1_svc(SetValueArgs arg1, int *result,  struct svc_req *rqstp){

	bool_t retval = TRUE;
	*result = 0;

	// Leer cotenido base de datos y obtener json
	cJSON *json = read_json("data.json");
	if (json == NULL){
		perror("Error: Unable to read the json file\n");
		retval = FALSE;
		*result = -1;
		cJSON_Delete(json);
		return retval;
	}

	// Modificar los datos del JSON 
	/*	struct SetValueArgs {
    						int key;
    						string value1<>;
    						int N_value2;
   							V_value2_double V_value2;
							};
	*/
	char list_key[MAXSIZE];
	sprintf(list_key, "%d", arg1.key);
	cJSON *item = cJSON_GetObjectItemCaseSensitive(json, list_key);
	if (item == NULL){
		printf("Modify_value() error: La clave %d no está en la base de datos.\n", arg1.key);
		retval = FALSE;
		*result = -1;
		cJSON_Delete(json);
		return retval;
	}

	cJSON_ReplaceItemInArray(item, 0, cJSON_CreateString(arg1.value1));
	cJSON_ReplaceItemInArray(item, 1, cJSON_CreateNumber(arg1.N_value2));
	cJSON_ReplaceItemInArray(item, 2, cJSON_CreateDoubleArray(arg1.V_value2.V_value2_val, arg1.N_value2));

	// Covertir cJSON object a JSON string 
	char *json_str = cJSON_Print(json); 

	// Escribir JSON string al archivo
	if (write_json("data.json", json_str) < 0){
		perror("Error: Unable to write on the file\n");
		retval = FALSE;
		*result = -1;
		cJSON_free(json_str); 
		cJSON_Delete(json);
		return retval;
	}

	// Liberar el JSON string y cJSON object 
	cJSON_free(json_str); 
	cJSON_Delete(json);

	return retval;
}


bool_t
exist_1_svc(int arg1, int *result,  struct svc_req *rqstp)
{
	bool_t retval = TRUE;

	// Leer cotenido base de datos y obtener json
	cJSON *json = read_json("data.json");
	if (json == NULL){
		perror("Error: Unable to read the json file\n");
		retval = FALSE;
		*result = -1;
		cJSON_Delete(json);
		return retval;
	}
	
	// Determinar si existe la entrada
	char list_key[MAXSIZE];
	sprintf(list_key, "%d", arg1);
	cJSON *item = cJSON_GetObjectItemCaseSensitive(json, list_key);

	// Usamos campo clave de la petición para el return en claves.c
	if (item == NULL){
		*result = 0;
	}
	else{
		*result = 1;
	}

	// Liberar cJSON object 
	cJSON_Delete(json);
	
	return retval;
}



/*Funciones de lectura y escritura de data.json*/
cJSON* read_json(char *file_path){
	//pthread_mutex_lock(&mutex_archivo); // Adquirir el mutex antes de leer

	FILE *fp = fopen(file_path, "r"); 
	if (fp == NULL) { 
		perror("Error: Unable to open the file.\n"); 
		return NULL; 
	} 

	// Leer contenido de la base de datos, tamaño dinámico
	char *buffer = NULL;
	size_t file_size = 0;
	fseek(fp, 0, SEEK_END);
	file_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	buffer = (char *)malloc(file_size + 1);
	fread(buffer, 1, file_size, fp);
	buffer[file_size] = '\0';
	fclose(fp); 

	//pthread_mutex_unlock(&mutex_archivo); // Liberar el mutex después de leer

	// Parse los datos del json
	cJSON *json = cJSON_Parse(buffer); 
	if (json == NULL) { 
		const char *error_ptr = cJSON_GetErrorPtr(); 
		if (error_ptr != NULL) { 
			printf("Error: %s\n", error_ptr); 
		} 
		cJSON_Delete(json); 
		return NULL; 
	} 
	return json;
}

int write_json(char *file_path, char *str){
	//pthread_mutex_lock(&mutex_archivo); // Adquirir el mutex antes de escribir

	FILE *fp = fopen(file_path, "w"); 
	if (fp == NULL) { 
		perror("Error: Unable to open the file.\n"); 
		return -1; 
	} 

	fputs(str, fp);
	fclose(fp); 

	//pthread_mutex_unlock(&mutex_archivo); // Liberar el mutex después de escribir

	return 0;
}


int
claves_prog_1_freeresult (SVCXPRT *transp, xdrproc_t xdr_result, caddr_t result)
{
	xdr_free (xdr_result, result);
	return 1;
}
