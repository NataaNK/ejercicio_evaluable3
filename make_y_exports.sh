#!/bin/bash

# Obtener el directorio actual de forma absoluta
currentDir=$(pwd)

# Compilar el proyecto
make -f Makefile.claves_iu

# Bibliotecas y variables de entorno necesarias en tiempo de ejecución
export LD_LIBRARY_PATH="${currentDir}/ejercicio_evaluable2:${currentDir}/ejercicio_evaluable2/cJSON:$LD_LIBRARY_PATH"
export IP_TUPLAS=localhost