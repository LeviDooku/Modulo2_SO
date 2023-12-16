///////////////////////////
//Pedro Velasco Santana  //
//S1 - Módulo II (SO)    //
///////////////////////////

/*
Ejercicio 3:

Comprobar y analizar el funcionamiento del siguiente programa
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int i;
    struct stat atributos;
    char tipoArchivo[30];

    //Comprobación del número de argumentos

    if(argc < 2){
        printf("\nSintaxis de ejecucion: tarea2 [<nombre_archivo>]+\n\n");    
        exit(-1);
    }

    //Análisis de los argumentos

    //Se usa lstat para el análisis exhaustivo del archivo

    for(i = 1; i < argc; i++){
        printf("%s: ", argv[i]);
        if(lstat(argv[i], &atributos) < 0){ //Se comprueba si la lectura del argumento es correcta
            printf("\n[-] Error al intentar acceder a los atributos de %s",argv[i]);
            perror("\nERROR EN LSTAT");
        }
        else{ //Se analiza el tipo de archivo
            if(S_ISREG(atributos.st_mode)) 
                strcpy(tipoArchivo,"Regular");
            else if(S_ISDIR(atributos.st_mode)) 
                strcpy(tipoArchivo,"Directorio");
            else if(S_ISCHR(atributos.st_mode)) 
                strcpy(tipoArchivo,"Especial de caracteres");
            else if(S_ISBLK(atributos.st_mode)) 
                strcpy(tipoArchivo,"Especial de bloques");
            else if(S_ISFIFO(atributos.st_mode)) 
                strcpy(tipoArchivo,"Cauce con nombre (FIFO)");
            else if(S_ISLNK(atributos.st_mode)) 
                strcpy(tipoArchivo,"Enlace relativo (soft)");
            else if(S_ISSOCK(atributos.st_mode)) 
                strcpy(tipoArchivo,"Socket");
            else strcpy(tipoArchivo,"Tipo de archivo desconocido");
            printf("%s\n",tipoArchivo);
        }
    }
    return 0;
}