#define MAX_N 32  /* Máximo valor de N */
#define MAXSIZE	256

struct valor2  {
	int N;                  /* Número de elementos del vector */
    double vector[MAX_N];   /* Vector de N elementos */
};


struct peticion  {
    int op; /* Operación, 0 (init), 1 (set), 2 (get), 3 (del), 4 (mod), 5 (exs)*/
	int clave;		        /* clave del elemento */
	char valor1[MAXSIZE]; 	/* string de 255 chars como máx */
	struct valor2 valor2;	/* vector de N elementos double */
	char q_name[MAXSIZE]; 	/* nombre de la cola cliente donde debe enviar la respuesta el servidor */
	char err_msg[MAXSIZE];  /* mensaje  de error personalizado para que lo vea el cliente */
};